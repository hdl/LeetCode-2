/*
Solution for LeetCode problem

Title: Valid Parentheses
URL: https://oj.leetcode.com/problems/valid-parentheses/
Version: 1.0

Created by Darcy Liu on 11/1/14.
*/
#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
    	stack<char> bottle;
    	for (int i = 0,count = s.size(); i < count; ++i) {
    		if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
    			bottle.push(s[i]);
    		} else if (!bottle.empty()){
    			if (bottle.top() == '{' && s[i] == '}'){
    				bottle.pop();
    			} else if (bottle.top() == '[' && s[i] == ']'){
    				bottle.pop();
    			} else if (bottle.top() == '(' && s[i] == ')'){
    				bottle.pop();
    			}
    		} else { // make it tidy
    			bottle.push(s[i]);
    		}
    	}
        return bottle.empty();
    }
};

int main()
{
    Solution solution;
    assert(solution.isValid("()[]{}") == true);
    assert(solution.isValid("([)]") == false);
    return 0;
}