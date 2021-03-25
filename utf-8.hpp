#include<string>

namespace askr
{
  class utf_8:public std::string{
      public:
      utf_8()
      : std::string(){}
      utf_8(const char* __s, const std::allocator<char>& __a = std::allocator<char>()):
      std::string(__s, __a){}

    //   private:
    //   ~utf_8(){

    //   }
  };
  class test_init{
      public:
      test_init(int _a,int _b){
          this->a = _a;
          this->b = _b;
      };
      int get(){
          return this->a;
      }
      private:
        int a = 10;
        int b = 11;
  };
}
// TODO 存放字符中的索引位置
// TODO 改索引 以unicode字符为索引
