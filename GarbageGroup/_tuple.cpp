#include<bits/stdc++.h>

using namespace std;

int main(void){
    tuple<string,int,double> t("hello",1,3.14);
    for (size_t i =0;i<sizeof(t);i++){
        std::cout<<i<<endl;
    }
    return 0;
}