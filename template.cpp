/*
Solution for LeetCode problem

Title: 
URL: 
Version: 1.0

Created by Darcy Liu on 8/2/14.
*/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int example(int x)
    {
        return x;
    }
};

int main()
{
    Solution solution;
    assert(solution.example(1) != 2);
    assert(solution.example(100) == 100);
    return 0;
}