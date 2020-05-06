#include<vector>
#include<iostream>

template<typename T>
void select(std::vector<T> &arr){
    // [0 ... i ... n]
    // j 未 i 中最大元素的下标
    // 0 ... i 为未排序
    // i ... n 为已排序
    for(int i=0;i<arr.size()-1;++i){
        T max = i;
        for(int j=0;j<arr.size()-1-i;++j){
            if (arr[j]>arr[max]) max = i;
        }
        std::swap(arr[i],arr[max]);
    }

}
int main(void){
    std::vector<int> arr {12,3,5,6,78,2,3,123,12,312,5,778};
    select<int>(arr);
    for (int i=0;i<arr.size()-1;++i)std::cout<<arr[i]<<std::endl;
    return 0;
}