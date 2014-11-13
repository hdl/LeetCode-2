/*
Solution for LeetCode problem

Title: Min Stack
URL: https://oj.leetcode.com/problems/min-stack/
Version: 1.0

Created by Darcy Liu on 11/13/14.
*/
#include <iostream>
#include <deque>

using namespace std;


class Solution {
public:
	deque<int> s;
	deque<int> min;
	void push(int x) {
		s.push_back(x);
		if (min.empty() || x <= min.back()){
			min.push_back(x);
		}
	}

	void pop() {
		if (s.back() == min.back()){
			min.pop_back();
		}
		s.pop_back();
	}

	int top() {
		return s.back();
	}

	int getMin() {
		return min.back();
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