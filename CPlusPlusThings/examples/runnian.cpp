#include<iostream>
using namespace std;


bool isrun (long age){
    return age%4==0&&age%100!=0||age%400==0;
}
int main(void){

    long age{0};
    cin>>age;
    cout<<isrun(age)<<endl;
}