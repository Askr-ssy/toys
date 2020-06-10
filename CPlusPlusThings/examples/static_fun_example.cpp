#include<iostream>
using namespace std;

class person{
    public:
    static void f();
    static void g();
    private:
    static int x;
};

int person::x=0;
void person::f(){
    x=5;
}
void person::g(){
    cout<<x<<endl;
}
int main(void){
    person::f();
    person::g();
}