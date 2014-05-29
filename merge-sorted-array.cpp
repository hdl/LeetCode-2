/*
Solution for LeetCode problem

Title: Merge Sorted Array 
URL: https://oj.leetcode.com/problems/merge-sorted-array/
Version: 1.0

Created by Darcy Liu on 5/30/14.
*/
#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        for (int i = (m+n-1); n>0 && i>=0 ; i--){
            if (m==0) {
                A[i] = B[--n];
            } else if(A[m-1]>B[n-1]){ /*put the max one at the last*/
                A[i] = A[--m];
            } else {
                A[i] = B[--n];
            }
        }
    }
};

int main()
{
    Solution solution;
    int a[] = {1,5,7,9,11};
    int b[] = {2,4,6,8};
    solution.merge(a,5,b,4);
    
    for(int i=0;i<9;i++){
        cout<< a[i] << endl;
    }
    
    return 0;
}