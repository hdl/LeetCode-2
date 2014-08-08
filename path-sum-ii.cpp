/*
Solution for LeetCode problem

Title: Path Sum II
URL: https://oj.leetcode.com/problems/path-sum-ii/
Version: 1.0

Created by Darcy Liu on 8/8/14.
*/
#include <iostream>
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > results;
		vector<int> path;
        if (root==NULL){
            return results;
        }
        this->dfs(root,sum,path,results);
        return results;
    }
    void dfs(TreeNode *root, int sum,vector<int> &path,vector<vector<int> > &results) {
    	if (root->left==NULL && root->right==NULL) {
    		if (root->val == sum) {
    			path.push_back(root->val);
          		results.push_back(path);
          		path.pop_back();
    		}
        } else {
        	path.push_back(root->val);

	        if (root->left!=NULL){
	        	this->dfs(root->left,(sum - root->val),path,results);
	        }
	        
	        if (root->right!=NULL){
	        	this->dfs(root->right,(sum - root->val),path,results);
	        }
	        path.pop_back();
        }
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > r;
    TreeNode n1(5),n2(4),n3(8),n4(11),n5(13),n6(4),n7(7),n8(2),n11(5),n12(1);
    
    n1.left = &n2;
    n1.right = &n3;

    n2.left = &n4;

    n3.left = &n5;
    n3.right = &n6;

    n6.left = &n11;
    n6.right = &n12;

    n4.left = &n7;
    n4.right = &n8;

    r = solution.pathSum(&n1,22);

 	for (vector<vector<int> >::iterator p = r.begin() ; p != r.end(); ++p) {
 		vector<int> path = *p;
		for (vector<int>::iterator it = path.begin() ; it != path.end(); ++it) {
			cout << ' ' << *it;
		}
		cout << endl;
	}
    return 0;
}