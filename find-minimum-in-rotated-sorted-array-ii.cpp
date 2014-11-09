/*
Solution for LeetCode problem

Title: Find Minimum in Rotated Sorted Array II
URL: https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
Version: 1.0

Created by Darcy Liu on 11/9/14.
*/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
		return binary_search(num,0,num.size()-1);
    }
    int binary_search(vector<int> &num,int start,int end) {
    	while(start < end) {
    		while (start < end && num[start] == num[end]){
    			start ++;
    		}
    		int mid = (start + end)/2;
    		if (num[start] < num[end]){ //ascending 3 4 5
        		return num[start];
        	} 
    		if (num[start] > num[mid]) {
    			end = mid;
    		} else if (num[end] < num[mid]) { 
    			start = mid+1;
    		}
    	}
    	return num[start];
    }
    int normal_search(vector<int> &num) {
    	int min = INT_MAX;
    	for (int i = 0, count = num.size(); i < count; ++i) {
    		if (num[i]<min) {
    			min = num[i];
    		}
    	}
		return min;
    }
};

int main()
{
    {
    	Solution solution;
    	int test[] = {3,1,3};
		vector<int> data(test, test + sizeof(test) / sizeof(int));
    	assert(solution.findMin(data)==1);
    }

    {
    	Solution solution;
    	int test[] = {3,3,1,3};
		vector<int> data(test, test + sizeof(test) / sizeof(int));
    	assert(solution.findMin(data)==1);
    }
    return 0;
}