#include<iostream>
#include<vector>

template<typename T>
void insert_sort(std::vector<T> &arr){
    for (int i=0;i<arr.size()-1;++i){
        for (int j=i+1;j<arr.size()-1;++j){
            if(arr[j]<arr[j+1])std::swap(arr[j])
        }
    }

}
int main(void){
    std::vector<int> arr{124,5,1234,124,6,87567,4,512334,12,35,5645,43};
    insert_sort<int>(arr);
    return 0;
}