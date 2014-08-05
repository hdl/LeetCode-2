/*
Solution for LeetCode problem

Title: Divide Two Integers
URL: https://oj.leetcode.com/problems/divide-two-integers/
Version: 1.0

Created by Darcy Liu on 8/2/14.
*/
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long c = 0;
        while (a >= b) {
            long long t = b;
            for (int i = 0; a>=t; i++,t <<= 1) {
                a -= t;
                c += 1 << i;
            }
        }
        return ((dividend^divisor)>>(sizeof(int)*8-1)/*31*/) ? (-c) : (c);
    }
};

int main()
{
    Solution solution;
    assert(solution.divide(1,2) == 0);
    assert(solution.divide(2,2) == 1);
    assert(solution.divide(-2147483648,1) == -2147483648);
    assert(solution.divide(2147483647,1) == 2147483647);
    return 0;
}