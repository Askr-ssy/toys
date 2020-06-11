#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    char stu[5][10];
    int i;
    for(i=0;i<5;i++)
        cin.getline(stu[i],10,',');
    cout<<"pong"<<endl;
    for(i=0;i<5;i++)
        cout<<stu[i]<<endl;
    system("pause");
    return 0;
}