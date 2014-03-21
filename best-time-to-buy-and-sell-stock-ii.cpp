/*
Solution for LeetCode problem

Title: Best Time to Buy and Sell Stock II
URL: http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
Version: 1.0

Created by Darcy Liu on 3/17/14.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int s = 0, t;
		for(int i=1,j = prices.size();i<j;i++){
			t = prices[i]-prices[i-1];
			if (t>0){
				s += t;
			}
		}
		return s;
	}
};

int main()
{
    Solution solution;
	vector<int> prices(10);
	for(int i=0;i<10;i++){
		prices[i] = i;
		//cout<<prices[i]<<endl;
	}
	cout<< solution.maxProfit(prices) <<endl;
    return 0;
}