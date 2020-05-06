#include<vector>
#include<iostream>

template<typename T>
void bubble(std::vector<T> &arr){
    // a [0 ... i ... n]
    // 0 ... i 为未排序
    // i ... n 未已排序
    for(int i=0;i<arr.size()-1;++i){
        for(int j=0;j<arr.size()-1-i;++j){
            if (arr[j]>arr[j+1])std::swap(arr[j],arr[j+1]);
        }
    }

}
int main(void){
    std::vector<int> arr {12,3,5,6,78,2,3,123,12,312,5,778};
    bubble<int>(arr);
    for (int i=0;i<arr.size()-1;++i)std::cout<<arr[i]<<std::endl;
    return 0;
}