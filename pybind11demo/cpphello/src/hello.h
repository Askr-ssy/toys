#ifndef CPPHELLO_HELLO_H
#include<string>
class Hello{
    private:
        std::string str;
    public:
        std::string getStr(){
            return str;
        }
        int setStr(std::string _str){
            str = _str;
            return 1;
        }
        Hello(std::string _str){
            str = _str;
        }
        Hello(){
            
        }
        ~Hello(){

        }
};
#endif