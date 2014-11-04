/*
Solution for LeetCode problem

Title: Longest Common Prefix
URL: https://oj.leetcode.com/problems/longest-common-prefix/
Version: 1.0

Created by Darcy Liu on 11/4/14.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string s;
        if (strs.size()==1) {
        	return strs[0];
        }
        for (int j = 0,skip = strs.size()==0; skip==0 ; ++j) {
        	for (int i = 0, count = strs.size()-1; i < count; ++i){
        		if (j<strs[i].size() && j < strs[i+1].size() && strs[i][j] == strs[i+1][j]) {
        			
        		}else{
        			skip = 1;
        			break;
        		}
        	}
        	if (skip==0) {
        		s.append(strs[0].substr(j,1));
        	}
        }
        return s;
    }
};

int main()
{
    Solution solution;

    vector<string> strs;
    strs.push_back("abcdefg");
    strs.push_back("abcxdefg");
    cout << solution.longestCommonPrefix(strs) << endl;
    return 0;
}