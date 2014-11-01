/*
Solution for LeetCode problem

Title: String to Integer (atoi)
URL: https://oj.leetcode.com/problems/string-to-integer-atoi/
Version: 1.0

Created by Darcy Liu on 11/1/14.
*/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
	int atoi(const char *str) {
		int flag = 1,overflow = 0;
		long long r = 0;

		while (*str == ' ') {
            str ++;
        }

        if (*str == '+') {
 			flag = 1;
 			str ++;
		} else if (*str == '-') {
			flag = -1;
			str ++;
		}
	
		while(*str) {
			if (isdigit(*str)) {
				r *= 10;
				r += (*str-'0');
				if (r > INT_MAX) {
					overflow = 1;
					break;
				}
			} else {
				break;
			}
			++str;
		}
		if (overflow) {
			r = (flag > 0) ? INT_MAX:INT_MIN;
		} else {
			r *= flag;
		}
		
		return r;
	}
};

int main()
{
    Solution solution;
    assert(solution.atoi("1") == 1); // 1
    assert(solution.atoi("+-2") == 0); // 0
    assert(solution.atoi("  +  413") == 0); // 0
    assert(solution.atoi("    +0a32") == 0); // 
    assert(solution.atoi("-3924x8fc") == -3924); // -3924
    assert(solution.atoi("++c") == 0); // 0
    assert(solution.atoi("++1") == 0); // 0
    assert(solution.atoi("2147483648") == INT_MAX); // 2147483647
    assert(solution.atoi("-2147483649") == INT_MIN); // -2147483648
    assert(solution.atoi("-2147483648") == INT_MIN); // -2147483648
    assert(solution.atoi("") == 0);; // 0
    return 0;
}