/*
Solution for LeetCode problem

Title: Populating Next Right Pointers in Each Node
URL: http://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
Version: 1.0

Created by Darcy Liu on 5/02/14.
*/
#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root != NULL){
            TreeLinkNode *visited = root;
			while(visited != NULL){
				if (visited->left != NULL){
					visited->left->next = visited->right;
				}
				
				if (visited->next != NULL && visited->right != NULL){
					visited->right->next = visited->next->left;
				}
				visited = visited->next;
			}
			root = root->left;
        }
    }
};

int main()
{
    Solution solution;
    TreeLinkNode a1(1),a2(2),a3(3),a4(4),a5(5),a6(6),a7(7);

    a1.left = &a2;
    a1.right = &a3;
    a2.left = &a4;
    a2.right = &a5;
    a3.left = &a6;
    a3.right = &a7;
	
	solution.connect(&a1);    
    return 0;
}
