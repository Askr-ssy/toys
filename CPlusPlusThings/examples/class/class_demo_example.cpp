#include<iostream>
#include<string>
using namespace std;
class Employee{
    public:
        Employee(string name,string id):name(name),id(id){}
        string getName(){return this->name;}
        string getId(){return this->id;}
        virtual float getSalary()=0;
        void print(){cout<<"姓名:"<<name<<endl<<"id:"<<id<<endl;}

    private:
        string name{""};
        string id{""};
};
class Manager:public Employee{
    public:
        Manager(string Name,string Id,int week):Employee(Name,Id){WeeklySalary=week*1000;}
        float getSalary(){return WeeklySalary;}

    private:
        float WeeklySalary;					//周薪

};
int main(void){
    Employee *rm;
    rm = new Manager("小王","1",10);
    rm->print();
    return 0;
}