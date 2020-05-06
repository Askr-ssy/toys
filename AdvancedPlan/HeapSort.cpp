#include<iostream>
#include<algorithm>
#include<vector>

// 循环不变式
// def [0 ... start ... end ... n]
// start 为 区间的根(最大或最小)
// 每次循环 start 为最大的根
template<typename T>
void MaxHeapify(std::vector<T> &arr,size_t start,size_t end){
    int dad = start;
    int son = dad*2+1;
    while (son <= end){
        if (son+1 <=end && arr[son]<arr[son+1])
            son++;
        if (arr[dad]>arr[son]){
            return;
        }
        else{
            std::swap(arr[dad],arr[son]);
            dad = son;
            son = dad*2+1;
        }
    }
}

template<typename T>
void HeapSort(std::vector<T> &arr){
    size_t len = arr.size();
    for (int i=len/2-1;i>=0;i--){        // 循环不变式
        MaxHeapify(arr,i,len-1);            // start -1 ... end 为已经排序的堆,start 为新增的元素
    }                                       // start ... end 中 start 的位置为根(最大或最小)
    for(int i=len-1;i>0;--i){
        std::swap(arr[0],arr[i]);
        MaxHeapify(arr,0,i-1);
    }
}

int main(void){
    std::vector<int> arr{124,5,1234,124,6,87567,4,512334,12,35,5645,43};
    HeapSort<int>(arr);
    return 0;
}