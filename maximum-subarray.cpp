/*
Solution for LeetCode problem

Title: Maximum Subarray
URL: https://oj.leetcode.com/problems/maximum-subarray/
Version: 1.0

Created by Darcy Liu on 8/9/14.
*/
#include <iostream>
#include <limits>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int s = 0, m = INT_MIN;
        for (int i = 0; i < n; ++i) {
            s += A[i];
            m = max(s,m);
            s = max(s,0);
        }
        return m;
    }
};

int main()
{
    Solution solution;
    int test_case[] ={-2,1,-3,4,-1,2,1,-5,4};
    assert(solution.maxSubArray(test_case,9)==6);
    return 0;
}