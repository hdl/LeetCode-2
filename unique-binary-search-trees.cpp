/*
Solution for LeetCode problem

Title: Unique Binary Search Trees 
URL: http://oj.leetcode.com/problems/unique-binary-search-trees/
Version: 1.0

Created by Darcy Liu on 3/21/14.
*/
#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n)
    {
        return this->subTrees(1, n);
    }
    int subTrees(int a, int b)
    {
        int s = 0, x, y;
        if (a >= b) {
            return 1;
        }
        for (int k = a; k <= b; k++) {
            x = this->subTrees(a, k - 1);
            y = this->subTrees(k + 1, b);
            s += x * y;
        }
        return s;
    }
};

int main()
{
    Solution solution;
    for (int i = 0; i < 10; i++) {
        cout << solution.numTrees(i) << endl;
    }
    return 0;
}