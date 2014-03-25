/*
Solution for LeetCode problem

Title: Binary Tree Inorder Traversal
URL: http://oj.leetcode.com/problems/binary-tree-inorder-traversal/
Version: 1.0

Created by Darcy Liu on 3/25/14.
*/
#include <iostream>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> r;
        stack<TreeNode*> s;
        TreeNode *t;
        if (root==NULL){
            return r;
        }
        t = root;
        while(!s.empty()||t!=NULL){
            while(t!=NULL){
                s.push(t);
                t = t->left; 
            }
            t = s.top(); s.pop();
            r.push_back(t->val);
            t = t->right;
        }
        return r;
    }
};

int main()
{
    Solution solution;
    vector<int> r;
    
    TreeNode a1(1),a2(2),a3(3);
    a1.right = &a2;
    a2.left = &a3;
    
    r = solution.inorderTraversal(&a1);
    
    for (vector<int>::iterator it = r.begin() ; it != r.end(); ++it) {
        cout << ' ' << *it;
    }
    return 0;
}