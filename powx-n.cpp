/*
Solution for LeetCode problem

Title: Pow(x, n)
URL: https://oj.leetcode.com/problems/powx-n/
Version: 1.0

Created by Darcy Liu on 8/7/14.
*/
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        double r = 1;
        for (long long m = abs((double)n); m>0; x*=x, m>>=1) {
            if (m&1) { // if m>>=1 is odd, multiply x again
                r *= x;
            }
        }
        return n>0? r : 1.0/r;
    }
};

int main()
{
    Solution solution;
    assert(solution.pow(2,10) == 1024);
    return 0;
}