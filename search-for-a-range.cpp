/*
Solution for LeetCode problem

Title: Search for a Range
URL: https://oj.leetcode.com/problems/search-for-a-range/
Version: 1.0

Created by Darcy Liu on 8/16/14.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> r;
		int last = -1;
		for (int i = 0; i < n; ++i) {
			if (A[i] == target ) {
				if (r.size() == 0) {
					r.push_back(i);
				}
				last = i;
			}
		}
		if (r.size() == 0) {
			r.push_back(-1);
		}
		r.push_back(last);
		return r;
	}
};

int main()
{
    Solution solution;
    int test[] = {5, 7, 7, 8, 8, 10};
    vector<int> r = solution.searchRange(test,6,8);
    for (std::vector<int>::iterator i = r.begin(); i != r.end(); ++i){
    	cout << *i << " ";
    }
    cout << endl;
    return 0;
}