
#include <openssl/md5.h>

#include <string>
#include <sstream>
#include <iomanip>

#include <fstream>
#include<iostream>
#define BUFFSIZE 16384

using namespace std;
std::string get_md5hash(const std::string &fname)
{

    char buffer[BUFFSIZE];
    unsigned char digest[MD5_DIGEST_LENGTH];

    std::stringstream ss;
    std::string md5string;

    std::ifstream ifs(fname, std::ifstream::binary);

    MD5_CTX md5Context;

    MD5_Init(&md5Context);

    while (ifs.good())
    {

        ifs.read(buffer, BUFFSIZE);

        MD5_Update(&md5Context, buffer, ifs.gcount());
    }

    ifs.close();

    int res = MD5_Final(digest, &md5Context);

    if (res == 0)  // hash failed
        return {}; // or raise an exception

    // set up stringstream format
    ss << std::hex << std::uppercase << std::setfill('0');

    for (unsigned char uc : digest)
        ss << std::setw(2) << (int)uc;

    md5string = ss.str();

    return md5string;
}
int main(int argc,char *argv[]){
    std::string md5str{""};
    if (argc<1)
        exit(1);
    md5str = get_md5hash(string{argv[0]});
    cout<<md5str<<endl;
    return 0;
}