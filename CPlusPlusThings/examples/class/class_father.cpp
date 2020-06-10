#include<iostream>
using namespace std;


class A{
    public:
        int x=0;
        virtual void foo(){
            cout<<"A.foo"<<endl;
        }
};
class B:public A{
    public:
        int x=1;
        virtual void foo(){
            cout<<"B.foo"<<endl;
        }
};

int main(void){
    A *a = new B;
    a->foo();
    cout<<a->x<<endl;
}