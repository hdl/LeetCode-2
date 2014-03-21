/*
Solution for LeetCode problem

Title: Maximum Depth of Binary Tree 
URL: http://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
Version: 1.0

Created by Darcy Liu on 3/16/14.
*/
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
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
};

int main()
{
    TreeNode a1(1), a2(2), a3(3), a4(4), a5(5);
    a1.left = &a2;
    a2.right = &a3;
    a3.left = &a4;
    a3.right = &a5;

    Solution solution;
    cout << solution.maxDepth(&a1) << endl;
    return 0;
}