/*
Solution for LeetCode problem

Title: Single Number II
URL: https://oj.leetcode.com/problems/single-number-ii/
Version: 1.0

Created by Darcy Liu on 8/8/14.
*/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int bits[32] = {0};
        int r = 0;
        for (int i = 0; i < 32; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((A[j] >> i) & 1) {
                    bits[i]++;
                }
            }
            r |= ((bits[i] % 3) << i);
        }
        return r;
    }
};

int main()
{
    Solution solution;

    int test_case[10] = {1,1,1,2,2,2,3,4,4,4};
    assert(solution.singleNumber(test_case,10) == 3);
    return 0;
}