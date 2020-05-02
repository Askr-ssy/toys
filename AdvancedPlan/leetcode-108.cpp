#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return _sortedArrayToBST(nums,0,nums.size()-1);
}
TreeNode* _sortedArrayToBST(vector<int>& nums,int l,int r) {
    if (r<l)return NULL;
    int mid = l+ ((r-l)>>1);
    TreeNode * root = new TreeNode(nums[mid]);
    root->left=_sortedArrayToBST(nums,l,mid-1);
    root->right=_sortedArrayToBST(nums,mid+1,r);
    return root;
}