/*
Solution for LeetCode problem

Title: Same Tree
URL: http://oj.leetcode.com/problems/same-tree/
Version: 1.0

Created by Darcy Liu on 3/17/14.
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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == NULL && q == NULL) {
            return true;
        } else if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
            return false;
        }

        bool left = false, right = false;
        if (p->left != NULL && q->left != NULL) {
            left = this->isSameTree(p->left, q->left);
        } else if (p->left == NULL && q->left == NULL) {
            if (p->val == q->val) {
                left = true;
            } else {
                right = false;
            }
        } else {
            left = false;
        }

        if (p->right != NULL && q->right != NULL) {
            right = this->isSameTree(p->right, q->right);
        } else if (p->right == NULL && q->right == NULL) {
            if (p->val == q->val) {
                right = true;
            } else {
                right = false;
            }
        } else {
            right = false;
        }

        return (left && right);
    }
};

int main()
{
    Solution solution;

    TreeNode a1(1), a2(2), a3(1), a4(2), a5(1);
    a1.left = &a2;
    a3.left = &a4;
    //a3.right = &a5;

    cout << solution.isSameTree(NULL, &a1) << endl;
    return 0;
}