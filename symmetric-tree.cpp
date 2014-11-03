/*
Solution for LeetCode problem

Title: Symmetric Tree
URL: https://oj.leetcode.com/problems/symmetric-tree/
Version: 1.0

Created by Darcy Liu on 11/3/14.
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
	bool isMirror(TreeNode *left,TreeNode *right) {
		if (left && right) {
			if (left->val == right->val) {
				return isMirror(left->left,right->right) && isMirror(left->right,right->left);
			}
			return false;
		}
		return left == right;
	}
	bool isSymmetric(TreeNode *root) {
		return isMirror(root,root);
	}
};

int main()
{
    Solution solution;
//{2,3,3,4,5,#,4}
//     2
//    / \
//   3   3
//  / \ / \
// 4  5 5  4
    TreeNode root(2),left2(3),left3(4),left4(5),right2(3),right3(5),right4(4);
    root.left = &left2;
    root.right = &right2;
    left2.left = &left3;
    left2.right = &left4;
    right2.left = &right3;
    right2.right = &right4;
    solution.isSymmetric(&root);
    assert(solution.isSymmetric(&root) == true);
    return 0;
}