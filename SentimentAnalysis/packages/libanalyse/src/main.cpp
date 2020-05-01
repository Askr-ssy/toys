#ifndef SITE_PACKAGE_PATH
#define SITE_PACKAGE_PATH STR_VALUE(SITE_PACKAGE_PATH)
#endif

#include<pybind11/pybind11.h>
#include<pybind11/complex.h>
#include<pybind11/stl.h>
#include "analyse/nlp.hpp"
#include<iostream>
#include<map>
using std::string;

const string DICT_PATH = string(SITE_PACKAGE_PATH) + string("analyse/dict/jieba.dict.utf8");
const string HMM_PATH = string(SITE_PACKAGE_PATH) + string("analyse/dict/hmm_model.utf8");
const string IDF_PATH = string(SITE_PACKAGE_PATH) + string("analyse/dict/idf.utf8");
const string STOP_WORD_PATH = string(SITE_PACKAGE_PATH) + string("analyse/dict/stop_words.utf8");

struct model{
    nlp::model _model;
    bool predict(std::map<string,string> data){
        _model.predict(data);
    }
};



namespace analyse{
    std::map<string,string> input_data;

    model *_model;
    bool predict(){
        std::map<string,string> input_data;
        return _model->predict(input_data);
    }
}

string ping(){
    return string{"pong"};
}
PYBIND11_MODULE(libanalysepy,m){
    m.doc() = "python extension for cppanalyse";

    m.def("predict",(void(*)()) & analyse::predict);
    m.def("ping",& ping);
}