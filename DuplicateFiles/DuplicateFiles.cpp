// DuplicateFiles.cpp: 定义应用程序的入口点。
//

#include "DuplicateFiles.h"
#include <filesystem>
#include <iostream>
#include <vector>
#include <map>
#include <iostream>
namespace fs = std::filesystem;
using namespace std;

std::vector<fs::path> find_all_file(const fs::path &path, vector<fs::path> &allfile)
{
    for (auto &p : fs::recursive_directory_iterator(path))
    {
        // cout<<p.path()<<endl;
        allfile.push_back(p.path());
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
    std::string path{argv[1]};

    vector<fs::path> allfile{};
    long long sum_filesize{};

    if (!fs::exists(path))
    {
        cerr << "path error:not found" << endl;
        exit(1);
    }
    if (!fs::is_directory(path))
    {
        cerr << "path is a file" << endl;
        exit(1);
    }

    try
    {
        find_all_file(path, allfile);
        cout << "查找完成,共:" << allfile.size() << "个文件 " << endl;
        ;
    }
    catch (exception &err)
    {
        cerr << err.what() << endl;
    }
    return 0;
}
