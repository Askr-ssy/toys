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
bool isSameTree(TreeNode* p, TreeNode* q) {
    //循环不变式: 当前节点
    if (!p && !q) return true;
    else if (!p && q) return false;
    else if (p && !q) return false;
    else if (!p->left && q->left) return false;
    else if (p->left && !q->left) return false;
    else if (!p->right && q->right) return false;
    else if (p->right && !q->right) return false;
    else if (p->val != q->val) return false;
    else if (!isSameTree(p->left,q->left) || !isSameTree(p->right,q->right)) return false;
    return true;
}
int main(void){

}