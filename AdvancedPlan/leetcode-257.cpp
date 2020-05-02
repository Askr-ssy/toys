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
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> arr;
    if (!root)return arr;
    binaryTreePaths(arr,"",root);
    return arr;
}
void binaryTreePaths(vector<string> & arr,string his,TreeNode * root){
    his += to_string(root->val);
    if (!root->left && !root->right){
        arr.push_back(his);
        return;
    }
    if(root->left)binaryTreePaths(arr,his+"->",root->left);
    if(root->right)binaryTreePaths(arr,his+"->",root->right);
}