#ifndef NLP_MODEL_H
#define NLP_MODEL_H

#include<string>
#include<iostream>
#include<set>
#include<regex>
#include"utils.hpp"
#include<algorithm>
#include<utility>
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

            // 模型入口
            void predict(std::map<string,string> &input_content){
                std::string content{""};
                std::vector<std::pair<std::string,double>> content_cut{};
                std::vector<std::pair<std::string,double>> content_tags{};
                std::vector<std::pair<std::string,double>> content_dict{};

                std::string title{""};
                std::vector<std::pair<std::string,double>> title_cut{};
                int title_emotion{0};

                std::string debug_type{""};
                double pos_score{0};
                double neg_score{0};
                double pos_threhold{0};
                double neg_threhold{0};
                std::map<std::string,double> show_dict{};

                bool pos_pro{false};
                std::string priority{"recall"};
                std::string cid{"9999"};
                bool debug{false};
                bool show{false};
                std::string type{"null"};
                double threhold{1};
                std::string info{"askr"};
                bool done{false};
                std::string message{""};
                std::vector<std::string> error{};
                int content_weight{1};

                std::map<std::string,double> user_dict{};
                std::map<uint16_t,std::vector<std::string>> user_regexp{};
                std::map<std::string,double> user_config{};
                std::map<std::string,double> tags_dict{};
                
                int emotion{0};

                if (input_content.count("content") && !input_content["content"].empty()){
                    content = input_content["content"];
                    if (input_content.count("title") && !input_content["title"].empty())
                        title = input_content["title"];
                }
                else if(input_content.count("title") && !input_content["title"].empty()){
                    content=input_content["title"];
                }
                
                if (input_content.count("cid") && !input_content["cid"].empty())
                    cid=input_content["cid"];
                if (input_content.count("is_debug"))
                    debug=true;
                if(input_content.count("show"))
                    show=false;
                if (input_content.count("type") && !input_content["type"].empty())
                    type=input_content["type"];
                
                if (this->users_version.count(cid)){
                    user_config = users_config[cid];
                    user_regexp = users_regexp[cid];
                    user_dict = users_dict[cid];
                }

                if ("weibo" == type){
                    if (input_content.count("retweetContent") && !input_content["retweetContent"].empty()){
                        content += input_content["retweetContent"];
                    }
                }

                if("weibo"==type and content.size()<500){
                    pos_threhold = user_config.count("weibo_pos_threhold")?user_config["weibo_pos_threhold"]:this->weibo_pos_threhold;
                    neg_threhold = user_config.count("weibo_neg_threhold")?user_config["weibo_neg_threhold"]:this->weibo_neg_threhold;
                    content_weight=1;
                }
                else {
                    if ("weibo"==type){
                        std::match_results<std::string::iterator> temp_result;
                        std::regex_match(content.begin(),content.end(),temp_result,this->weibo_split);
                        if (temp_result.size()>0){
                            //TODO title = temp[0:] content = temp[1:]
                            type="news";
                        }
                    }
                    pos_threhold = user_config.count("news_pos_threhold")?user_config["news_pos_threhold"]:this->weibo_pos_threhold;
                    neg_threhold = user_config.count("news_neg_threhold")?user_config["news_neg_threhold"]:this->weibo_neg_threhold;
                    content_weight=2;                    
                }
                pos_pro = user_config.count("Tendency")?user_config["Tendency"]:false;
                // priority = user_config.count("Priority")?user_config["Priority"]:"recall";

                //TODO 去除html
                //TODO 去除数字

            }
        private:
            //TODO
            bool load_data(){
                load_dict(this->basewords_filename,tags_dict);
                load_dict(this->inversewords_filename,inverse_words,1,1);
                load_dict(this->machinewords_filename,tags_dict,1,1);
                load_dict(this->modiwords_filename,tags_dict,1,1);
                load_dict(this->modiwords_filename,modi_words,1,1);

                map_to_set(tags_dict,tags_dict_set);
                map_to_set(modi_words,modi_words_set);
                map_to_set(inverse_words,inverse_words_set);

                load_dict(this->stopwords_filename,stop_words);
                load_dict(this->selfwords_filename,self_words);   // TODO add jieba word
                load_dict(this->clearwords_filename,clear_words);
                load_dict(this->sensitivewords_filename,sensitive_words);

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
                    if ((!std::regex_match(word.begin(),word.end(),this->zh)) && word.size() > 1)
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
            std::vector<std::vector<std::string>> keyword(const std::string content,const std::string title,const std::string type=""){                
                std::string toExtractor{};
                std::vector<std::pair<std::string,double>> keyword;
                toExtractor = title+content;
                this->keywordExtractor.Extract(toExtractor,keyword,100);
                for (std::pair<std::string,double> item:keyword){
                    if (this->stop_words.count(item.first) || this->clear_words.count(item.first))
                        continue;
                    if (item.first.size()<=1)
                        continue;
                    if (cppjieba.)
                }
                
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
            const std::string version = "v1.0.0.0";
            const std::string dict_file{"/home/askr/document/github/toys/cpp_nlp/data/selfword.txt"};
            const std::string basewords_filename{"/home/askr/document/github/toys/cpp_nlp/data/base_words.txt"};
            const std::string stopwords_filename{"/home/askr/document/github/toys/cpp_nlp/data/stopwords.txt"};
            const std::string clearwords_filename{"/home/askr/document/github/toys/cpp_nlp/data/clear_words.txt"};
            const std::string modiwords_filename{"/home/askr/document/github/toys/cpp_nlp/data/modi_words.txt"};
            const std::string machinewords_filename{"/home/askr/document/github/toys/cpp_nlp/data/machineEmotion_-0.2.txt"};
            const std::string sensitivewords_filename{"/home/askr/document/github/toys/cpp_nlp/data/sensitive_words.txt"};
            const std::string inversewords_filename{"/home/askr/document/github/toys/cpp_nlp/data/inverse.txt"};
            const std::string triggerwords_filename{};
            const std::string selfwords_filename{"/home/askr/document/github/toys/cpp_nlp/data/selfword.txt"};

            const std::string jieba_dict_path{"./data/dict/jieba.dict.utf8"};
            const std::string jieba_model_path{"./data/dict/hmm_model.utf8"};
            const std::string jieba_user_dict_path{"./data/dict/user.dict.utf8"};
            const std::string jieba_idf_path{"./data/dict/idf.utf8"};
            const std::string jieba_stopWord_path{"./data/dict/stop_words.utf8"};



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
            
            std::map<std::string,uint64_t> users_version;
            std::map<std::string,std::map<std::string,double>> users_dict;
            std::map<std::string,std::map<uint16_t,std::vector<std::string>>> users_regexp;
            std::map<std::string,std::map<std::string,double>> users_config;


            std::regex zh{"[\u4e00-\u9fa5]"};
            std::regex weibo_split{",，.。!！？!;；"};
            cppjieba::TextRankExtractor keywordExtractor{this->jieba_dict_path,this->jieba_model_path,this->jieba_stopWord_path};
            std::regex http{};
            double news_pos_threhold{0.2};
            double news_neg_threhold{-0.14};
            double weibo_pos_threhold{0.12};
            double weibo_neg_threhold{-0.15};
            int length_division{15};


    };
}

#endif