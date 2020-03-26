#include<vector>
#include<cmath>
#include<valarray>
#include<iostream>
#include<utility>
#include<numeric>
using namespace std;
int largestSumAfterKNegations(vector<int>& A, int K) {
    if (A.empty())return 0;

    for(int c=0;c<K;c++){
        int min=0;
        for (int i=0;i<A.size();++i){
            if (A[i]<A[min])min=i;
        }
        A[min] = -A[min];
    }

    return accumulate(A.begin(),A.end(),0);
}
int main(void){
    vector<int> arr{5,6,9,-3,3};
    cout<<largestSumAfterKNegations(arr,2)<<endl;
}