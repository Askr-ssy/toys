#include<cmath>
#include<vector>
#include<iostream>
std::vector<bool> fpn(int n){
    std::vector<bool> flag (n+1,true);  // is prime number
    flag[0] = flag[1] = false;
    for (int i=2;i<n;++i){
        if (flag[i])
            for (int j=i*i;j<=n;j+=i)
                flag[j]=false;
    }
    return flag;
}

bool ispn(int n){
    int y = (int)sqrt(n);
    for(int x = 2;x<y;++x){
        if (n%x==0){
            return false;
        }
    }
    return true;
}
int main(void){
    std::vector<bool> result = fpn(100);
    int count = 0;
    for (bool x:result){
        if( x==true)
            std::cout<<count<<std::endl;
        ++count;
    }
    std::cout<<ispn(97)<<std::endl;
    
}