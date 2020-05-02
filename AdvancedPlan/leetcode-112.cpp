#include<iostream>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool hasPathSum(TreeNode* root, int sum) {
    if(!root)return false;
    if (!root->left && !root->right){
        if(sum==root->val)return true;
        else return false;  
    }
    if(root->left) if (hasPathSum(root->left,sum-root->val))return true;
    if (root->right) if (hasPathSum(root->right,sum-root->val))return true;
    return false;
}