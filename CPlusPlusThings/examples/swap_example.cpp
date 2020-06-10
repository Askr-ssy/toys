#include<iostream>
using namespace std;
inline void swap(int &a,int &b){
    a = b+a;
    b = a-b;
    a = a-b;
}
int main(void){
    int x=1,b=2;
    swap(x,b);
    cout<<x<<" "<<b<<endl;


    return 0;
}