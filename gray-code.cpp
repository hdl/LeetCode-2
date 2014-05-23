/*
Solution for LeetCode problem

Title: Gray Code
URL: https://oj.leetcode.com/problems/gray-code/
Version: 1.0

Created by Darcy Liu on 5/23/14.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> r;
		r.push_back(0);
		for (int i = 0; i < n; i++) {
			int m = r.size();
			while (m) {
				int val = r[--m];
				val += (1<<i);
				r.push_back(val);
			} 
		}
		return r;
    }
};

int main()
{
    Solution solution;
	vector<int> list = solution.grayCode(3);
	for ( vector<int>::iterator it = list.begin() ; it != list.end() ; it++ ) {
		cout<<*it<<endl;
	}
    return 0;
}