#include<iostream>
using namespace std;

union askr
{
    struct { char *name;int age;}u;
    int k;
}a;

int main(void){
    cout<<a.k<<endl;
    return 0;


}