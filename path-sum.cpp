/*
Solution for LeetCode problem

Title: Path Sum
URL: https://oj.leetcode.com/problems/path-sum/
Version: 1.0

Created by Darcy Liu on 7/24/14.
*/
#include <iostream>
#include <cassert>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return false;
        }

        if (root->left==NULL && root->right==NULL) {
            if (sum == root->val) {
                return true;
            }
            return false;
        }
        
        bool leftHas = this->hasPathSum(root->left,sum - root->val);
        bool rightHas = this->hasPathSum(root->right,sum - root->val);
        
        return leftHas||rightHas;
    }
};

int main()
{
    Solution solution;

    TreeNode n1(5),n2(4),n3(8),n4(11),n5(13),n6(4),n7(7),n8(2),n12(1);
    TreeNode t1(1),t2(-2),t3(-3),t4(1),t5(3),t6(-2),t8(-1);
    n1.left = &n2;
    n1.right = &n3;

    n2.left = &n4;

    n3.left = &n5;
    n3.right = &n6;

    n6.right = &n12;

    n4.left = &n7;
    n4.right = &n8;

    t1.left = &t2;
    t1.right = &t3;

    t2.left = &t4;
    t2.right = &t5;

    t3.left = &t6;
    t4.left = &t8;

    assert(solution.hasPathSum(&n1,22)==true);
    assert(solution.hasPathSum(&n1,21)==false);
    assert(solution.hasPathSum(&n1,26)==true);
    assert(solution.hasPathSum(&n12,1)==true);
    assert(solution.hasPathSum(&n6,5)==true);

    assert(solution.hasPathSum(&t1,-1)==true);

    return 0;
}