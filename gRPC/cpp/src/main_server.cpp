#include"time.pb.h"
#include<iostream>
#include<ctime>
#include<grpc/grpc.h>


class GetTime final:public HelloReply::service{

}
char* ping(){
    std::time_t result = std::time(nullptr);
    return std::asctime(std::localtime(&result));
}
int main(void){ 
    cout<<test();
    return 0;
}