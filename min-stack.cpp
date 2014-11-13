/*
Solution for LeetCode problem

Title: Min Stack
URL: https://oj.leetcode.com/problems/min-stack/
Version: 1.0

Created by Darcy Liu on 11/13/14.
*/
#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
	stack<int> s;
	stack<int> min;
	void push(int x) {
		s.push(x);
		if (min.empty() || x <= min.top()){
			min.push(x);
		}
	}

	void pop() {
		if (s.top() == min.top()){
			min.pop();
		}
		s.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return min.top();
	}
};

int main()
{
    {
    	Solution solution;
    	solution.push(2147483646);
    	solution.push(2147483646);
    	solution.push(2147483647);
    	cout << solution.top() << endl;
    	solution.pop();
    	cout << solution.getMin() << endl;
    	solution.pop();
    	cout << solution.getMin() << endl;
    	solution.pop();
    	solution.push(2147483647);
    	cout << solution.top() << endl;
    	cout << solution.getMin() << endl;
    	solution.push(-2147483648);
    	cout << solution.top() << endl;
    	cout << solution.getMin() << endl;
    	solution.pop();
    	cout << solution.getMin() << endl;
    }

    {
    	Solution solution;
    	solution.push(-2);
	    solution.push(0);
	    solution.push(-1);

	    cout << solution.getMin() << endl;
	    cout << solution.top() << endl;
	    solution.pop();
	    cout << solution.getMin() << endl;
    }
    
    return 0;
}