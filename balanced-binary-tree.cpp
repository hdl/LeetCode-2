/*
Solution for LeetCode problem

Title: Balanced Binary Tree
URL: https://oj.leetcode.com/problems/balanced-binary-tree/
Version: 1.0

Created by Darcy Liu on 8/14/14.
*/
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if (root == NULL) {
            return 0;
        }
        int left = this->maxDepth(root->left);
        int right = this->maxDepth(root->right);
        return left > right ? left + 1 : right + 1;
    }
    bool isBalanced(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        if (root->left==NULL && root->right== NULL) {
            return true;
        }
        int left = this->maxDepth(root->left);
        int right = this->maxDepth(root->right);
        if (abs(left - right)>1) {
            return false;
        }
        return this->isBalanced(root->left) && this->isBalanced(root->right);
    }
};

int main()
{
    /*
        1
       / \
      2   3
     /     \
    4       5
    */
    TreeNode a1(1), a2(2), a3(3), a4(4), a5(5),a6(6),a7(7);
    a1.left = &a2;
    a1.right = &a3;
    a2.left = &a4;
    a3.right = &a5;

    //a4.left = &a6;
    //a5.right = &a7;

    Solution solution;
    cout << solution.isBalanced(&a1) << endl;
    return 0;
}