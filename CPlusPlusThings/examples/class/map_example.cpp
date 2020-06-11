#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(void){
    map<string,double> se;
    se["hello"]=1;
    se["葡萄"]=2;
    
    
    for (map<string,double>::iterator it=se.begin();it!=se.end();++it){
        cout<<it->first<<":"<<it->second<<endl;
    }
    string str;
    cin>>str;
    map<string,double>::iterator result;
    result = se.find(str);
    cout<<(result!=se.end())<<endl;
}