/*
Solution for LeetCode problem

Title: Binary Tree Postorder Traversal
URL: http://oj.leetcode.com/problems/binary-tree-postorder-traversal/
Version: 1.0

Created by Darcy Liu on 3/17/14.
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> r;
        stack<TreeNode*> s;
        TreeNode *t,*visited;
        if (root==NULL){
            return r;
        }
        t = root;
        visited = NULL;
        while(!s.empty()||t!=NULL){
            while(t!=NULL){
                s.push(t);
                t = t->left; 
            }
            t = s.top();
            if (t->right==NULL || t->right == visited){
                r.push_back(t->val);
                s.pop();
                visited = t;
                t = NULL;
            }else{
                t = t->right;
            }
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

    r = solution.postorderTraversal(&a1);

    for (vector<int>::iterator it = r.begin() ; it != r.end(); ++it) {
        cout << ' ' << *it;
    }
    return 0;
}