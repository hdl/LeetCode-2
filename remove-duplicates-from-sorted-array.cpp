/*
Solution for LeetCode problem

Title: Remove Duplicates from Sorted Array
URL: https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
Version: 1.0

Created by Darcy Liu on 7/13/14.
*/
#include <iostream>
//#include <limits> //INT_MAX

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (0 == n) {
            return 0;
        }

        int p, r = 0;
        p = A[0];
        for (int i = 1 ; i < n; ++i) {
            if (p == A[i]) {
                
            } else {
                p = A[i];
                r ++ ;
            }
            A[r] = A[i];
        }
        return r+1;
    }
};

int main()
{
    Solution solution;
    int test[] = {1,1,2,3,4,4,5};
    int r = solution.removeDuplicates(test,7);
    cout << "length = " << r << endl;
    for (int i = 0; i < r; ++i) {
    	cout << test[i] << endl;
    }
    return 0;
}