/*
Solution for LeetCode problem

Title: Search in Rotated Sorted Array
URL: https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
Version: 1.0

Created by Darcy Liu on 6/11/14.
*/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        return this->binary_search(A,target,0,n-1);
    }
    // int normal_search(int A[], int n, int target) {
    //     int found = -1;
    //     for (int i = 0; i < n ; i++) {
    //         if (target == A[i]) {
    //             found = i;
    //             break;
    //         }
    //     }
    //     return found;
    // }
    int binary_search(int A[], int target, int start,int end) {
        while (start<=end) {
        	int mid = (start + end)/2;
        	if (A[mid] == target) {
            	return mid;
        	}
        	if (A[start] <= A[mid]) { // increase
        		if (A[start] <= target && target < A[mid]) {
        			end = mid - 1;
        		} else {
        			start = mid + 1;
        		}
        	} else { // have unknown rotated pivot
        		if (A[mid] < target && target <= A[end]) {
        			start = mid + 1;
        		} else {
        			end = mid - 1;
        		}
        	}
        }
        return -1;
    }
};

int main()
{
    Solution solution;

    int test_case[] = {4,5,6,7,0,1,2};
    assert(solution.search(test_case,7,0)==4); //4
    assert(solution.search(test_case,7,4)==0); //0
    assert(solution.search(test_case,7,8)==-1); //0
    return 0;
}