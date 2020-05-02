/**
 * 简易容器类
 */
#ifndef LIMONP_LOCAL_VECTOR_HPP
#define LIMONP_LOCAL_VECTOR_HPP

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

namespace limonp
{
using namespace std;
/*
 * LocalVector<T> : T must be primitive type (char , int, size_t), if T is struct or class, LocalVector<T> may be dangerous..
 * LocalVector<T> is simple and not well-tested.
 */
const size_t LOCAL_VECTOR_BUFFER_SIZE = 16;
template <class T> //简单容器类
class LocalVector
{
public:
    typedef const T *const_iterator; //指向一个常量类的指针
    typedef T value_type;
    typedef size_t size_type;

private:
    T buffer_[LOCAL_VECTOR_BUFFER_SIZE]; //缓冲区
    T *ptr_;                             // 开头指针
    size_t size_;                        // 大小
    size_t capacity_;                    //占用大小

public:
    LocalVector()
    {
        init_();
    };
    LocalVector(const LocalVector<T> &vec) // 加载已有模型
    {
        init_();
        *this = vec;
    }
    LocalVector(const_iterator begin, const_iterator end) //初始和结束迭代器
    {                                                     // TODO: make it faster
        init_();
        while (begin != end)
        {
            push_back(*begin++);
        }
    }
    LocalVector(size_t size, const T &t) //重复n遍
    {                                    // TODO: make it faster
        init_();
        while (size--)
        {
            push_back(t);
        }
    }
    ~LocalVector()
    {
        if (ptr_ != buffer_)
        {
            free(ptr_);
        }
    };

public:
    LocalVector<T> &operator=(const LocalVector<T> &vec) //重载等于运算符
    {
        clear();
        size_ = vec.size();
        capacity_ = vec.capacity();
        if (vec.buffer_ == vec.ptr_) // 如果缓冲区用完?
        {
            memcpy(buffer_, vec.buffer_, sizeof(T) * size_);
            ptr_ = buffer_;
        }
        else
        {
            ptr_ = (T *)malloc(vec.capacity() * sizeof(T));
            assert(ptr_);
            memcpy(ptr_, vec.ptr_, vec.size() * sizeof(T));
        }
        return *this;
    }

private:
    //初始化
    void init_()
    {
        ptr_ = buffer_;                       //实际指针
        size_ = 0;                            //实际大小
        capacity_ = LOCAL_VECTOR_BUFFER_SIZE; //占用大小
    }

public:
    //重载下标索引
    T &operator[](size_t i)
    {
        return ptr_[i];
    }

    //重载下标索引
    const T &operator[](size_t i) const
    {
        return ptr_[i];
    }

    //
    void push_back(const T &t)
    {
        if (size_ == capacity_) //占用满则2倍空间
        {
            assert(capacity_);
            reserve(capacity_ * 2);
        }
        ptr_[size_++] = t;
    }

    //
    void reserve(size_t size)
    {
        if (size <= capacity_)
        {
            return;
        }
        T *next = (T *)malloc(sizeof(T) * size);
        assert(next);
        T *old = ptr_;
        ptr_ = next;
        memcpy(ptr_, old, sizeof(T) * capacity_);
        capacity_ = size;
        if (old != buffer_)
        {
            free(old);
        }
    }

    //是否为空
    bool empty() const
    {
        return 0 == size();
    }
    //返回size_
    size_t size() const
    {
        return size_;
    }
    //返回capacity
    size_t capacity() const
    {
        return capacity_;
    }
    //返回ptr_
    const_iterator begin() const
    {
        return ptr_;
    }
    //返回ptr_+size_
    const_iterator end() const
    {
        return ptr_ + size_;
    }
    void clear() //初始化
    {
        if (ptr_ != buffer_)
        {
            free(ptr_);
        }
        init_();
    }
};

template <class T>
ostream &operator<<(ostream &os, const LocalVector<T> &vec)
{
    if (vec.empty())
    {
        return os << "[]";
    }
    os << "[\"" << vec[0];
    for (size_t i = 1; i < vec.size(); i++)
    {
        os << "\", \"" << vec[i];
    }
    os << "\"]";
    return os;
}

} // namespace limonp

#endif
