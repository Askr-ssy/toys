// debug file
#include<iostream>
#include<regex>
#include"analyse/nlp.hpp"
#include"cppjieba/Jieba.hpp"
#include"cppjieba/TextRankExtractor.hpp"
const std::string dict_path = "./dict/jieba.dict.utf8";
const std::string model_path = "./dict/hmm_model.utf8";
const std::string user_dict_path = "./dict/user.dict.utf8";
const std::string idf_path = "./dict/idf.utf8";
const std::string stopWord_path = "./dict/stop_words.utf8";
int main(void){
    std::cout<<"hello"<<std::endl;
    try{
        nlp::model _model;
        std::map<std::string,std::string> context;
        std::cout<<_model.predict(context) <<std::endl;
    }
    catch (const std::exception& e){
        std::cerr<<e.what()<<std::endl;
    }
    cppjieba::Jieba jieba{dict_path,model_path,user_dict_path,idf_path,stopWord_path};
    std::string str{"热烈欢迎南京市长江大桥先生致词"};
    std::vector<std::string> words;
    std::vector<cppjieba::Word> jiebawords;
    jieba.Cut(str,words,true);
    jieba.CutForSearch(str, jiebawords, true);
    cppjieba::TextRankExtractor textrankExtractor{dict_path,model_path,stopWord_path};
    textrankExtractor.Extract(str,words,10);
    

    
    // _model.load_data();   //debug
    // _model.check_initialized();
    // _model.check_initialized();


    return 0;
}