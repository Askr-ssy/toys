#include<iostream>
#include<cmath>
using namespace std;
struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
int maxDepth(TreeNode* root) {
    //循环不变式 返回当前节点最深的层数
    if(!root)return 0;
    if (!root->left) return maxDepth(root->right)+1;
    if (!root->right) return maxDepth(root->left)+1;
    return max(maxDepth(root->left)+1,maxDepth(root->right)+1);
}
int main(void){
    TreeNode *node{};
}