/*
Solution for LeetCode problem

Title: Best Time to Buy and Sell Stock III
URL: https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
Version: 1.0

Created by Darcy Liu on 8/12/14.
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size()==0) {
            return 0;
        }
        
        int a[3] = {0};
        int b[3] = {0};
        int k = 2;
        for(int i = 1;i < prices.size();i++){
            int delta = prices[i] - prices[i-1];
            for (int j = k; j > 0; j--) {
                a[j] = max(b[j-1],a[j])+delta;
                b[j] = max(a[j],b[j]);
            } 
        }
        return b[k];
    }
};

int main()
{
    Solution solution;
    vector<int> prices;
    int data[6] = {6,1,3,2,4,7};//7
    prices.assign(data,data+6);

    cout << solution.maxProfit(prices) << endl;
    return 0;
}