/*
Solution for LeetCode problem

Title: Length of Last Word
URL: http://oj.leetcode.com/problems/length-of-last-word/
Version: 1.0

Created by Darcy Liu on 3/15/14.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char* s)
    {
        int length = 0, last = 0;
        while (*s) {
            if (*s == ' ') {
                last = length > 0 ? length : last;
                length = 0;
            } else {
                length++;
            }
            ++s;
        }
        return length > 0 ? length : last;
    }
};

int main()
{
    Solution solution;
    cout << solution.lengthOfLastWord("Hello World") << endl;
    return 0;
}