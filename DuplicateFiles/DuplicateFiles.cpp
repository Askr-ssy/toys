// DuplicateFiles.cpp: 定义应用程序的入口点。
//

#include "DuplicateFiles.h"
#include<filesystem>
#include<iostream>
#include<vector>
#include<map>
#include"openssl/md5.h"
namespace fs = std::filesystem;
using namespace std;
vector<fs::path> find_file_on_dire(const fs::path& dire,vector<fs::path> &allfile) {
	for (const auto& entry : fs::directory_iterator(dire)) {
		allfile.push_back(entry.path());
		try {
			if (fs::is_directory(entry))
				find_file_on_dire(entry,allfile);
		}
		catch (exception err) {
			cerr << entry.path() << " ";
			cerr << err.what() << endl;
			continue;
		}
	}
	return allfile;
}

int main()
{
	std::string path = "D:";
	vector<fs::path> allfile{};
	long long sum_filesize{};

	if (! std::filesystem::exists(path)) {
		cerr << "path error" << endl;
		exit(1);
	}

	try {
		find_file_on_dire(path,allfile);
		cout << "查找完成,共:" << allfile.size() << "个文件 " << endl;;
	}
	catch (exception &err){
		cerr << err.what() << endl;
	}
 	return 0;
}
