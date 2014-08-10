/*
Solution for LeetCode problem

Title: Best Time to Buy and Sell Stock
URL: https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
Version: 1.0

Created by Darcy Liu on 8/10/14.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int a = 0, b = 0, m = 0;
        for(int i = 1;i < prices.size();i++){
            if (prices[i] > prices[a]) {
                b = i;
            }

            if (prices[i] < prices[a]){
                a = i;
            }

            if ( a < b && prices[b] - prices[a] > m) {
                m = prices[b] - prices[a];
            }
        }
        return m;
    }
};

int main()
{
    Solution solution;
    vector<int> prices;
    int data[3] = {4,1,2};
    prices.assign(data,data+3);

    cout << solution.maxProfit(prices) << endl;
    return 0;
}