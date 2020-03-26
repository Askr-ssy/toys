#include<vector>
#include<cmath>
using namespace std;
int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int flag = 0; //0,1,2,3 北 东，南，西
    int max = 0;
    int x=0,y=0;
    for (int _ =0;_<commands.size();++_){
        if (commands[_]<0){
            switch (commands[_])
            {
            case -1:
                flag++;
                break;
            case -2:
                flag--;
                break;
            default:
                break;
            }
        }
        if (commands[_]>=1 && commands[_]<=9){
            switch (flag%4)
            {
            case 0:
                y+=commands[_];
                break;
            case 1:
                x+=commands[_];
                break;
            case 2:
                y-=commands[_];
                break;
            case 3:
                x-=commands[_];
                break;
            default:
                break;
            }
        }

        
    }
}