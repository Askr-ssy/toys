#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        vector<TreeNode*> up;
        up.push_back(root);
        while(1){
            vector<TreeNode*> down;
            vector<int> temp;
            for(auto tem : up){
                temp.push_back(tem->val);
                if(tem->left){
                    down.push_back(tem->left);
                }
                if(tem->right){
                    down.push_back(tem->right);
                }
            }
            res.push_back(temp);
            up = down;
            if(down.empty()){
                break;
            }
        }
        reverse(res.begin(),res.end());
        return res;
}

int main(void){
    return 0;
}