/*
Solution for LeetCode problem

Title: Palindrome Number
URL: https://oj.leetcode.com/problems/palindrome-number/
Version: 1.0

Created by Darcy Liu on 8/1/14.
*/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		int reversed = 0;
		int temp = x, mod;
		while (temp>0) {
			mod = temp % 10;
			temp = temp / 10;
			reversed = reversed * 10 + mod;
		}
		return reversed == x;
	}
};

int main()
{
    Solution solution;
    assert(solution.isPalindrome(100)==false);
    assert(solution.isPalindrome(1)==true);
    assert(solution.isPalindrome(121)==true);
    assert(solution.isPalindrome(-5)==false);
    return 0;
}