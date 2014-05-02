/*
Solution for LeetCode problem

Title: Remove Element
URL: http://oj.leetcode.com/problems/remove-element/
Version: 1.0

Created by Darcy Liu on 5/2/14.
*/
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int count = 0, i;
        for (i=0;i<n;i++){
            if(A[i] == elem){ 
                count ++;
            }else {
                A[i-count] = A[i];
            }
        }
        return n-count;
    }
};

int main()
{
    Solution solution;
    int test_data[3] = { 1, 2, 3 };
    cout << solution.removeElement(test_data, 3, 2) << endl;
    return 0;
}