/*
Solution for LeetCode problem

Title: Find Minimum in Rotated Sorted Array 
URL: https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
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
    	int test[] = {5};
		vector<int> data(test, test + sizeof(test) / sizeof(int));
    	assert(solution.findMin(data)==5);
    }

	{
    	Solution solution;
    	int test[] = {1,2};
		vector<int> data(test, test + sizeof(test) / sizeof(int));
    	assert(solution.findMin(data)==1);
    }

    {
    	Solution solution;
    	int test[] = {2,1};
		vector<int> data(test, test + sizeof(test) / sizeof(int));
    	assert(solution.findMin(data)==1);
    }

    {
    	Solution solution;
    	int test[] = {3,4,5};
		vector<int> data(test, test + sizeof(test) / sizeof(int));
    	assert(solution.findMin(data)==3);
    }

    {
    	Solution solution;
    	int test[] = {3,4,2};
		vector<int> data(test, test + sizeof(test) / sizeof(int));
    	assert(solution.findMin(data)==2);
    }

    {
    	Solution solution;
    	int test[] = {3,1,2};
		vector<int> data(test, test + sizeof(test) / sizeof(int));
    	assert(solution.findMin(data)==1);
    }

    {
    	Solution solution;
    	int test[] = {6,1,2,3,4};
		vector<int> data(test, test + sizeof(test) / sizeof(int));
    	assert(solution.findMin(data)==1);
    }

    {
    	Solution solution;
    	int test[] = {4,5,6,1,2};
		vector<int> data(test, test + sizeof(test) / sizeof(int));
    	assert(solution.findMin(data)==1);
    }
    return 0;
}