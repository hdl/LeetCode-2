/*
Solution for LeetCode problem

Title: Excel Sheet Column Title
URL: https://oj.leetcode.com/problems/excel-sheet-column-title/
Version: 1.0

Created by Darcy Liu on 12/28/14.
*/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string s;
		while(n>0) {
			int mod = (n-1) % 26;
			char x = 'A' + mod;
			s.insert(s.begin(),x);

			n = (n-1)/26;
		}
		return s;
	}
};

int main()
{
    Solution solution;
    assert(solution.convertToTitle(1) == "A");
    assert(solution.convertToTitle(25) == "Y");
    assert(solution.convertToTitle(26) == "Z");
    assert(solution.convertToTitle(27) == "AA");
    assert(solution.convertToTitle(28) == "AB");
    assert(solution.convertToTitle(52) == "AZ");
    assert(solution.convertToTitle(53) == "BA");
    assert(solution.convertToTitle(701) == "ZY");
    assert(solution.convertToTitle(703) == "AAA");
    return 0;
}