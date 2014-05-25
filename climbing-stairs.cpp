/*
Solution for LeetCode problem

Title: Climbing Stairs
URL: https://oj.leetcode.com/problems/climbing-stairs/
Version: 1.0

Created by Darcy Liu on 5/25/14.
*/
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 2 , c = 3;
        if (n<3) {
            return n;
        }
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main()
{
    Solution solution;
    for (int i = 0; i< 10; i++) {
        cout << solution.climbStairs(i) << endl;   
    }
    return 0;
}