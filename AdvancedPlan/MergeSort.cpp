#include<algorithm>
#include<vector>
template<typename T>
void Merge(std::vector<T> &arr,size_t start,size_t mid,size_t end){
    std::vector<T> left(arr.begin()+start,arr.begin()+mid+1);
    std::vector<T> right(arr.begin()+mid+1,arr.begin()+end+1);
    left.insert(left.end(), numeric_limits<T>::max());
    right.insert(right.end(), numeric_limits<T>::max());    
    size_t l=0;
    size_t r=0;
    for (i = start;i<end;++i){
        if (left[l]<=right[r]){
            arr[i] = left[l];
            l++
        }
        else{
            arr[i] = right[r];
            r++;
        }
    }
}
template<typename T>
void MergeSort(std::vector<T> &arr,size_t start,size_t end){
    if (start>=end)
        return;
    size_t mid = (start+end)/2;
    MergeSort(arr,start,mid);
    MergeSort(arr,mid,end);
    Merge(arr,start,mid,end);
}
int main(void){
    std::vector<int> arr{124,5,1234,124,6,87567,4,512334,12,35,5645,43};
    MergeSort<int>(arr,0,arr.size());
    return 0;
}