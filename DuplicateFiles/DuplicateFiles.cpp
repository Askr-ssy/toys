// DuplicateFiles.cpp: 定义应用程序的入口点。
//

#include "DuplicateFiles.h"
#include "md5.hpp"
#include <filesystem>
#include <iostream>
#include <vector>
#include <unordered_set>
#include<map>
#include<unordered_map>
#include<thread>


#include <iostream>
namespace fs = std::filesystem;
using namespace std;

std::vector<fs::path> find_all_file(const fs::path &path, vector<fs::path> &allfile)
{
    for (auto &p : fs::recursive_directory_iterator(path, fs::directory_options::skip_permission_denied))
    {
        try
        {
            if (fs::is_directory(p)){
                continue;
            }
            // cout << p.path() << endl;
            allfile.push_back(p.path());
        }
        catch (const std::exception &err)
        {
            cout << p.path() << endl;
            cout << err.what() << endl;
            continue;
        }
    }
    return allfile;
}
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cerr << "path not found" << endl;
        exit(1);
    }
    fs::path findpath{argv[1]};

    if (!fs::exists(findpath))
    {
        cerr << "path error:not found" << endl;
        exit(1);
    }
    if (!fs::is_directory(findpath))
    {
        cerr << "path is a file" << endl;
        exit(1);
    }

    std::unordered_map<std::string,std::string> md5_to_path{};
    std::map<string,string> Df{};
    fs::path path = fs::canonical(findpath);
    vector<fs::path> allfile{};
    // long long sum_filesize{};
    try
    {
        find_all_file(path, allfile);
    }
    catch (exception &err)
    {
        cerr << err.what() << endl;
    }
    for (fs::path &path : allfile)
    {
        std::string _md5 = get_md5hash(path.string());
        if (md5_to_path.contains(_md5)){
            Df[path.string()] = md5_to_path[_md5];
        }
        else
        {
            md5_to_path[_md5]=path.string();
        }
        
    }
    for (auto &p : Df){
        cout<<"DuplicateFiles"<<endl;
        cout<<p.first<<endl<<p.second<<endl;
    }
    return 0;
}
