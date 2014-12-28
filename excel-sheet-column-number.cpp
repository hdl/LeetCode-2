/*
Solution for LeetCode problem

Title: Excel Sheet Column Number
URL: https://oj.leetcode.com/problems/excel-sheet-column-number/
Version: 1.0

Created by Darcy Liu on 12/28/14.
*/
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int r = 0;
		for (int i = 0,count = s.length(); i < count; ++i){
			int t = ((s[count-i-1] - 'A') + 1);
			int x = t*pow(26,i);
			r += x;
		}
		return r;
	}
};

int main()
{
    Solution solution;

    assert(solution.titleToNumber("AA") == 27);
    assert(solution.titleToNumber("AB") == 28);
	assert(solution.titleToNumber("AAA") == 703);

    return 0;
}