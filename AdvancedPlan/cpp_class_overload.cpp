#include<vector>
#include<iostream>

class VectorOut{
public:
    const char *_string = "str";
    void out(const char * str){
        std::cout<<_string<<std::endl;
    }
};
class cpp_class_overload:VectorOut
{
private:
    /* data */
public:
    cpp_class_overload(/* args */);
    ~cpp_class_overload();
    void out(){
        std::cout<<_string<<std::endl;
    }
};

cpp_class_overload::cpp_class_overload(/* args */)
{
}

cpp_class_overload::~cpp_class_overload()
{
}

int main(void){
    cpp_class_overload ver;
    ver.out();
}