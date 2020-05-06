#include<algorithm>
#include<vector>
template<typename T>
void QuickSort(std::vector<T> &arr,int start,int end){
    if (start>=end) return;
    int l = start;
    int r = end+1;
    T key = arr[start];     // get key    
    while (true){
        while (arr[++l]<key)
            if (l==end)
                break;
        while (arr[--r]>key)
            if (r==start)
                break;
        if (l>=r)
            break;
        std::swap(arr[l],arr[r]);
    }
    std::swap(arr[start],arr[r]);
    QuickSort(arr,start,r-1);
    QuickSort(arr,r+1,end);
}
int main(void){
    std::vector<int> arr{124,5,1234,124,6,87567,4,512334,12,35,5645,43};
    QuickSort<int>(arr,0,arr.size());
    return 0;
}