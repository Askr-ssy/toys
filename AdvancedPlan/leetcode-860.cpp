#include<vector>
#include<string>
#include<iostream>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int ten=0;
    int five=0;
    for(int i =0;i<bills.size();++i){
        if(bills[i]==5)
            five++;
        else if (bills[i]==10){
            if(five<=0)
                return false;
            else{
                five--;
                ten++;
            }
        }
        else{
            if (five>0 && ten >0){
                five--;
                ten--;
            }
            else if(five>=3)
                five-=3;
            else{
                return false;
            }
        }
    }
    return true;
}
int main(void){
    vector<int> bills{5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
    cout<<lemonadeChange(bills)<<endl;
}