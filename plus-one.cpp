/*
Solution for LeetCode problem

Title: Plus One
URL: https://oj.leetcode.com/problems/plus-one/
Version: 1.0

Created by Darcy Liu on 7/19/14.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int carry = 1;
		for (int i = digits.size() - 1; i>=0; i--) {
			digits[i] += carry;
			if (digits[i]>9) {
				digits[i] %= 10;
				carry = 1;
			} else {
				carry = 0;
			}
		}

		if (carry>0) {
			vector<int>::iterator it = digits.begin();
			digits.insert(it,carry);
		}
		return digits;
	}
};

int main()
{
    Solution solution;
    int mydata[] = {9,9,9};
    vector<int> data(mydata, mydata + sizeof(mydata) / sizeof(int));
    vector<int> r;
    r = solution.plusOne(data);

    for (vector<int>::iterator it = r.begin(); it < r.end(); it++) {
    	cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}