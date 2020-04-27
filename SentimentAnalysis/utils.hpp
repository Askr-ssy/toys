#ifndef NLP_UTILS_H
#define NLP_UTILS_H
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<set>
#include "include//askr/StringUtil.hpp"

std::map<std::string,double> load_dict(const std::string file_path,std::map<std::string,double> &dict,int flag=3,size_t maxsplit=std::string::npos){
    std:: ifstream file = std::ifstream(file_path,std::ios::in);   // TODO 编码问题
    std::string line;
    std::vector<std::string> res;
    try
    // 增加容错
    {   
        while (std::getline(file,line)){
            std::cout<<line<<std::endl;
            try{
                askr::Trim(line);
                res=askr::Split(line," ",maxsplit);
                dict[res[0]]=std::stod(res[flag]);

            }
            catch(...){
                std::cout<<"error :"<<line<<std::endl;
                continue;
            }
                
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << " error :"<<e.what() << std::endl;

    }
    return dict;
}
std::set<std::string> load_dict(const std::string file_path,std::set<std::string> &dict){
    std:: ifstream file = std::ifstream(file_path,std::ios::in);   // TODO 编码问题
    std::string line;
    try
    {   
        while (std::getline(file,line)){
            askr::Trim(line);
            dict.insert(line);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << " error :"<<e.what() << std::endl;

    }
    return dict;
}

std::set<std::string> map_to_set(const std::map<std::string,double> &_map,std::set<std::string> &_set){
    _set.clear();
    for(auto it=_map.begin();it!=_map.end();++it)_set.insert(it->first);
    return _set;
}

#endif