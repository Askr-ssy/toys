#include<array>
#include<iostream>
int bs(int p[],int l,int r,int x ){
    std::cout<<l<<" "<<(l+r)/2<<" "<<r<<std::endl;
    if (p[(l+r)/2] >x )return bs(p,l,(l+r)/2-1,x);
    else if(p[(l+r)/2] < x ) return bs(p,(l+r)/2+1,r,x);
    else if (p[(l+r)/2]==x) return (l+r)/2;
    else return false;
}

int main(void){
    int p [] = {1,2,3,4,5};
    std::cout<<bs(p,0,4,4)<<std::endl;
    return 0;
}