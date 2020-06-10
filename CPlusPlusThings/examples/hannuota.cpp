#include<iostream>
using namespace std;
void move(int a,int b){
    cout<<a<<"----->"<<b<<endl;
}
void hanni(int n,char A,char B,char C){
    // 
    // A:from
    // B:buffer
    // C:to
    // 

    if (n==1)
        move(A,C);
    else{
        hanni(n-1,A,C,B);
        move(A,C);
        hanni(n-1,B,A,C);
    }
}
int main(void){
    int n;
    cin>>n;
    cout<<"ÇëÊäÈëÅÌ×ÓÊýÁ¿£º";
    hanni(n,'A','B','C');
    return 0;
}
