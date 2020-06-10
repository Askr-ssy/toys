#include<iostream>
using namespace std;

long xn(int x,int n){
    
    long sum=1;
    while (n--){
        sum*=x;
    }
    return sum;
}

int main(void){
    cout<<xn(2,2)<<endl;

    return 0;
}