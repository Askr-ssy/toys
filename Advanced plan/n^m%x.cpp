#include<iostream>

int nmx(int n,int m,int x){
    int ans=1;
    if (m==0)return 1%x;
    if (m==1)return n%x;
    ans = nmx(n,m/2,x);
    ans = ans * ans%x;
    if (m%2==1) ans =ans*n %x; // 分解 m 

    return ans;
}

int main(void){
    //nmx();
    return 0;
}