/*
Solution for LeetCode problem

Title: Binary Tree Level Order Traversal II
URL: https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
Version: 1.0

Created by Darcy Liu on 11/3/14.
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	queue<TreeNode*> q;
	vector<vector<int> > r;
	void visit() {
		queue<TreeNode*> t;
		vector<int> line;
		while (!q.empty()) {
			TreeNode *root = q.front();
			line.push_back(root->val);
			if (root->left) {
				t.push(root->left);
			}
			if (root->right) {
				t.push(root->right);
			}
			q.pop();
		}
		r.insert(r.begin(),line);
		q = t;
		while (!q.empty()) {
			visit();
		}
	}
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		if (root) {
			q.push(root);
			visit();
		}
		return r;
	}
};

int main()
{
    Solution solution;
    //{3,9,20,#,#,15,7}
    TreeNode n3(3),n9(9),n20(20),n15(15),n7(7);
    n3.left = &n9;
    n3.right = &n20;
    n20.left = &n15;
    n20.right = &n7;
    vector<vector<int> > r = solution.levelOrderBottom(&n3);
    for (vector<vector<int> >::iterator it = r.begin(); it != r.end(); ++it) {
        vector<int> line = *it;
        for (vector<int>::iterator item = line.begin(); item != line.end(); ++item) {
            cout << *item << " ";
        }
        cout << endl;
    }
    return 0;
}