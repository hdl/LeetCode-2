/*
Solution for LeetCode problem

Title: Sort Colors
URL: https://oj.leetcode.com/problems/sort-colors/
Version: 1.0

Created by Darcy Liu on 6/11/14.
*/
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        for (int i = 0, j=0; i < n; i++) {
            if (A[i] == 0) {
                swap(A[i],A[j++]);
            } else if (A[i] == 2) {
                swap(A[i--],A[--n]);
            }
        } 
    }
};

int main()
{
    Solution solution;
    int colors[] = {0,1,2,0,1,2,0};
    solution.sortColors(colors,7);
    for (int i = 0; i < 7; ++i)
    {
        cout << colors[i] << endl;
    }
    return 0;
}