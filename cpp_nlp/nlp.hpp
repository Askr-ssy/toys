#ifndef NLP_MODEL_H
#define NLP_MODEL_H

#include<string>
#include<iostream>
#include<set>
#include<regex>
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
            ){}
            model(){
                this->check_initialized();
            }
            ~model(){}
            //TODO
            bool initialize(){
                this->load_data();
                std::cout<<"initialize end"<<std::endl;
                return true;
            }

            bool check_initialized(){
                std::cout<<"check_initialized "<<this->initialized<<std::endl;
                if(!this->initialized){
                    this->initialize();
                }
                std::cout<<"check_initialized "<<this->initialized<<std::endl;
                return true;
            }

            //TODO
            void predict(){
                // 模型入口
            }
        private:
            //TODO
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

                // TODO tags_dict 弹出所有单字

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

                for (auto temp:this->clear_words){
                    try{
                        // TODO 删除分词
                        this->tags_dict.erase(temp);
                    }catch (...) {
                        std::cout<<"错误词语未在词典中 "<<temp<<std::endl;
                    }
                }

                // 敏感词 指针

                //辞典加入分词
                for (auto word :this->modi_words_set){
                    std::match_results<std::string::iterator> results1;
                    if ((!std::regex_match(word.begin(),word.end(),results1,this->zh)) && word.size() > 1)
                        (void)0;
                        // add_word(word)   // 添加分词              
                }
                return true;

            }

            //TODO
            void zoom(){
                //TODO 缩放权重
            }
            
            //TODO
            void keyword(){
                //关键词提取
            }

            //TODO
            void trigger(){
                // 虚拟语气 关键词触发
            }

            //TODO
            void subjunctive(){
                // 虚拟语态 假设词
            }

            //TODO
            void cut_words(){
                // 补充分词
            }

            //TODO 
            void participle(){
                // 分词
            }

            //TODO
            void correlation(){
                // 文章相关性分析
            }

            //TODO
            void start_end(){
                //首尾加强
            }

            //TODO
            void check_peak(){
                //检查峰值
            }

            //TODO
            void sign_compute(){
                //符号处理
            }

            //TODO
            void keyword_match(){
                //关键词加强
            }

            //TODO
            void attach_model(){
                //附加模型处理
            }

            //TODO
            void title_predict(){
                //TODO 标题处理
            }

            //TODO
            void regexp_match(){
                //正则匹配
            }

            //TODO
            void score_mark(){
                //分数标记
            }

            //TODO
            void title_pro(){
                //标题加强
            }

            //TODO
            void sensitive_match(){
                //敏感词匹配
            }

            //TODO
            void log_generate(){
                //日志生成
            }

            //TODO
            void no_repeat(){
                //重复词语清零
            }


            //TODO
            void score(){
                //分数生成
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

            std::regex zh{"[\u4e00-\u9fa5]"};

    };
}

#endif