int gcd(int m=0,int n=0){
    if (m<n){
        m = n + m;
        n = m - n;
        m = m - n;
    }
    if (n==0)return m;
    return gcd(n,m%n);
}

#include<iostream>
int main(void){
    std::cout<<gcd(1071,462)<<std::endl;
}