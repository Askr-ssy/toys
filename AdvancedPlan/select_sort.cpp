#include<vector>
template<typename T>
void select_sort(std::vector<T>& arr){
    for(int i=0;i<arr.size()-1;++i){
        int min = i;
        for (int j = i+1;j<arr.size()-1;++j){
            if(arr[j]<arr[min])min = j;
        }
        std::swap(arr[i],arr[min]);
    }
}

int main(void){
    std::vector<int> result{1,2,5,6,7,2,4,6};
    select_sort<int>(result);
}