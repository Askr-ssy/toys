#include<iostream>
#include<cstring>


using namespace std;
class Person{
    public:
    typedef enum{
        Boy=0,
        Girl
    }SexType;
    Person(char *n,int age,SexType s){
        name = new char[strlen(n)+1];
        strcpy(name,n);
        this->age=age;
        this->s = s;


        ;
    }
    ~Person(){
        delete [] this->name;
    }
    Person & addage(int a){
        this->age+=a;
        return *this;
    }
    int getage() const {
        return this->age;
    }
    private:
        char *name;
        int age;
        SexType s;
};

int main(void){

    Person per{"askr",18,Person::Girl};
    cout<<per.getage()<<endl;
    cout<<per.addage(30).getage()<<endl;

}