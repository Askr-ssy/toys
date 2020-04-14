#ifndef NLP_MODEL_H
#define NLP_MODEL_H

#include<string>
#include<iostream>
#include<set>
#include"utils.hpp"
#include<algorithm>

namespace nlp{
    using std::string;

    class model{
        private:
            bool initialized = false;
        public:
            model(const string &dict_path,
                  const string &base_path,
                  const string &stop_path,
                  const string &clear_path,
                  const string &modi_path,
                  const string &sensitives_path,
                  const string &inverse_path
            ){

            }
            model(){
                this->check_initialized();
            }
            ~model(){

            }
            bool initialize(){
                std::cout<<"initialize"<<std::endl;
                return true;
            }            
            bool check_initialized(){
                if(!this->initialized){
                    this->initialize();
                    this->initialized=true;
                }
                else return true;
            }
            bool load_data(){
                load_dict("/home/askr/document/github/toys/cpp_nlp/data/base_words.txt",tags_dict);
                load_dict("/home/askr/document/github/toys/cpp_nlp/data/inverse.txt",inverse_words,1,1);
                load_dict("/home/askr/document/github/toys/cpp_nlp/data/machineEmotion_-0.2.txt",tags_dict,1,1);
                load_dict("/home/askr/document/github/toys/cpp_nlp/data/modi_words.txt",tags_dict,1,1);
                load_dict("/home/askr/document/github/toys/cpp_nlp/data/modi_words.txt",modi_words,1,1);

                map_to_set(tags_dict,tags_dict_set);
                map_to_set(modi_words,modi_words_set);
                map_to_set(inverse_words,inverse_words_set);

                load_dict("/home/askr/document/github/toys/cpp_nlp/data/stopwords.txt",stop_words);
                load_dict("/home/askr/document/github/toys/cpp_nlp/data/selfword.txt",self_words);   // TODO add jieba word
                load_dict("/home/askr/document/github/toys/cpp_nlp/data/clear_words.txt",clear_words);
                load_dict("/home/askr/document/github/toys/cpp_nlp/data/sensitive_words.txt",sensitive_words);

                
                std::set_difference(stop_words.begin(),stop_words.end(),inverse_words_set.begin(),inverse_words_set.end(),std::inserter(temp_dict,temp_dict.begin()));
                stop_words = temp_dict;
                temp_dict.clear();

                std::set_difference(clear_words.begin(),clear_words.end(),inverse_words_set.begin(),inverse_words_set.end(),std::inserter(temp_dict,temp_dict.begin()));
                clear_words=temp_dict;
                temp_dict.clear();
                std::set_difference(clear_words.begin(),clear_words.end(),modi_words_set.begin(),modi_words_set.end(),std::inserter(temp_dict,temp_dict.begin()));
                clear_words=temp_dict;
                temp_dict.clear();

                //TODO AC tree trigreetree 触发词

                
                return true;
            }
        public:
            std::map<std::string,double> tags_dict;
            std::map<std::string,double> inverse_words;
            std::map<std::string,double> modi_words;
            std::set<std::string> temp_dict;
            std::set<std::string> tags_dict_set;
            std::set<std::string> inverse_words_set;
            std::set<std::string> modi_words_set;
            std::set<std::string> self_words;
            std::set<std::string> stop_words;
            std::set<std::string> clear_words;
            std::set<std::string> sensitive_words;
    };
}

#endif