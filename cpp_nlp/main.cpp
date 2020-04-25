// debug file
#include<iostream>
#include<regex>
#include"nlp.hpp"
#include"include/cppjieba/Jieba.hpp"
#include"include/cppjieba/TextRankExtractor.hpp"
const std::string dict_path = "./data/dict/jieba.dict.utf8";
const std::string model_path = "./data/dict/hmm_model.utf8";
const std::string user_dict_path = "./data/dict/user.dict.utf8";
const std::string idf_path = "./data/dict/idf.utf8";
const std::string stopWord_path = "./data/dict/stop_words.utf8";
int main(void){
    std::cout<<"hello"<<std::endl;
    try{
        nlp::model _model;
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