/*
Solution for LeetCode problem

Title: Single Number
URL: http://oj.leetcode.com/problems/single-number/
Version: 1.0

Created by Darcy Liu on 3/15/14.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        while(--n!=0){
            A[n-1] ^= A[n];
        }
        return A[0];
    }
};

int main()
{
    Solution solution;
    int test_data[9] = {1,1,2,2,3,4,4,5,5};
    cout<< solution.singleNumber(test_data,9)<<endl;
    return 0;
}