#include<iostream>
using namespace std;
class A{
    int x=0;
    // friend int main(void);
    friend class B;
};
class B{
    public:
        int getA(A a){
            return a.x;
        }
};
int main(void){
    B b;
    A a;
    cout<<b.getA(a)<<endl;

}