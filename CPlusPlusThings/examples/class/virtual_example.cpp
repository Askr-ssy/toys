#include<iostream>
using namespace std;
class A{
    public:
    virtual void FuzzBuzz()=0;
    protected:
        double x,y;
    void set(double x,double y){
        this->x = x;
        this->y = y;
    }
};
class B:public A{
    public:
    void FuzzBuzz(){
        cout<<"Fuzz"<<endl;
    }
    void ping(){
        cout<<"pong"<<endl;
    }
};
class C:public B{
    void FuzzBuzz(){
        cout<<"FuzzBuzz"<<endl;
    }
};

int main(void){
    A *a;
    C c;
    a = &c;
    a->FuzzBuzz();
    // a->ping();
    c.B::FuzzBuzz();
    return 0;
}