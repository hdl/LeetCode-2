/*
Solution for LeetCode problem

Title: Minimum Depth of Binary Tree
URL: https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
Version: 1.0

Created by Darcy Liu on 8/13/14.
*/
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        if (root->left != NULL && root->right!=NULL) {
            int left = this->minDepth(root->left);
            int right = this->minDepth(root->right);
            return left < right ? left + 1 : right + 1; 
        }
        
        if (root->left != NULL) {
            return 1 + this->minDepth(root->left);
        }
        if (root->right != NULL)
        {
            return 1 + this->minDepth(root->right);
        }
        return 1; // both NULL
    }
};

int main()
{
    TreeNode a1(1), a2(2), a3(3), a4(4), a5(5);
    a1.left = &a2;
    a1.right = &a3;
    a2.left = &a4;
    a3.right = &a5;

    Solution solution;
    cout << solution.minDepth(&a1) << endl;
    return 0;
}