#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x,TreeNode *l,TreeNode *r):val(x),left(l),right(r){}
};
bool isSymmetric(TreeNode* root) {
    return isSync(root,root);
}
bool isSync(TreeNode *l,TreeNode *r){
    if (!l && !r)return true;
    if (!l || !r) return false;
    if(l->val == r->val)return isSync(l->left,r->right) && isSync(l->right,r->left);
    return false;
}