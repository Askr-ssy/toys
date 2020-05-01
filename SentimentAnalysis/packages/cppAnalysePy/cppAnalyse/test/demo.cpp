#include "analyse/nlp.hpp"
#include<string>
#include<iostream>
int main(void){
    nlp::model _model;
    std::map<std::string,std::string> input;
    std::cout<<_model.predict(input)<<std::endl;
}