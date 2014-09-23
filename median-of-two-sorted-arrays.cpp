/*
Solution for LeetCode problem

Title: Median of Two Sorted Arrays
URL: https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
Version: 1.0

Created by Darcy Liu on 9/23/14.
*/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
	// O(n)
    double _findMedianSortedArrays(int A[], int m, int B[], int n) {
        int a,b,i,j;
        double s = 0;
        if ((m + n)%2 == 0) {
            b = (m+n)/2;
            a = b-1;
        } else {
            a = (m+n)/2;
            b = a;
        }
        for (i = 0,j = 0; i < m && j < n;) {
            if (A[i]<=B[j]) {
                if ((i+j)>=a && (i+j)<=b){
                    s += A[i];
                }
                i ++;
            } else if(A[i]>B[j]){
                if ((i+j)>=a && (i+j)<=b){
                    s += B[j];
                }
                j ++;
            }
        }
        while (i<m) {
            if ((i+j)>=a && (i+j)<=b){
                s += A[i];
            }
            i ++;
        }
        while(j<n) {
            if ((i+j)>=a && (i+j)<=b){
                s += B[j];
            }
            j ++;
        }
        return s/(b-a+1);
    }
    /*
	A -------- m --------
		 m1         m2
	B -------- n --------
	     n1         n2
    */
    double findInSortedArrays(int A[],int m, int B[], int n,int target) {
        if (m<=0) {
            return B[target-1];
        } 
        if (n<=0) {
            return A[target-1];
        }
        if (target <= 1) {
            return min(A[0], B[0]);
        }
        if (B[n/2] >= A[m/2]) {
            if ((m/2 + n/2 + 1) >= target) { // drop n2
                return findInSortedArrays(A,m,B,n/2,target);
            } else {// dopr m1
                return findInSortedArrays(A+m/2+1,m-(m/2+1),B,n,target-(m/2+1));
            }
        } else {
            if ((m/2 + n/2 + 1) >= target) { // drop m2
                return findInSortedArrays(A,m/2,B,n,target);
            } else {//drop n1
                return findInSortedArrays(A,m,B+n/2+1,n-(n/2+1),target-(n/2+1));
            }
        }
        return 0;
    }
    // O(log (m+n))
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    	double s = findInSortedArrays(A,m,B,n,(m+n)/2+1);
        if ((m + n)%2 == 0) {
            s += findInSortedArrays(A,m,B,n,(m+n)/2);
            s /= 2;
        }
    	return s;
    }
};

int main()
{
    Solution solution;
    int a[] = {1,2};
    int b[] = {3,4,5,6};
    cout << solution._findMedianSortedArrays(a,2,b,4) << endl;
    cout << solution.findMedianSortedArrays(a,2,b,4) << endl;
    return 0;
}