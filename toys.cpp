#include <iostream>
#include "utf-8.hpp"
using namespace std;
// void say_hello(){
//     std::cout << "Hello, from toys!\n";
// }


#include<string>
typedef std::basic_string<char32_t> unicode;
int main(void){
    // askr::utf_8 u8 {"hello,world"};
    std::u32string str{"hello,world"};

    // std::string u8;
    // cout<<str.c_str()<<endl;

}