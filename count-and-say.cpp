/*
Solution for LeetCode problem

Title: Count and Say
URL: https://oj.leetcode.com/problems/count-and-say/
Version: 1.0

Created by Darcy Liu on 8/2/14.
*/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string say,r;
        if (n < 1) {
            return say;
        }
        say = "1";
        while (n>1) {
            r.clear();
            int pos = 1,count = 1;
            while (pos < say.length()){
                if (say[pos] != say[pos-1]) {
                    r.append(to_string(count));
                    r.append(to_string(say[pos-1]-'0'));
                    count = 1;
                } else {
                    count ++;
                }
                pos ++;
            }
            r.append(to_string(count));
            r.append(to_string(say[pos-1]-'0'));
            say = r;
            n --;
        }
        return say;
    }
};

int main()
{
    Solution solution;
    assert(solution.countAndSay(0).compare("") == 0);
    assert(solution.countAndSay(1).compare("1") == 0);
    assert(solution.countAndSay(2).compare("11") == 0);
    assert(solution.countAndSay(3).compare("21") == 0);
    assert(solution.countAndSay(4).compare("1211") == 0);
    assert(solution.countAndSay(5).compare("111221") == 0);
    return 0;
}