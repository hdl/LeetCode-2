/*
Solution for LeetCode problem

Title: Two Sum
URL: https://oj.leetcode.com/problems/two-sum/
Version: 1.0

Created by Darcy Liu on 8/5/14.
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> r;
		map<int, int> hashmap;
		for(int i = 0;i < numbers.size();i++) {
			if (hashmap.count(target-numbers[i]) > 0) {
				r.push_back(hashmap[target-numbers[i]]);
				r.push_back(i+1);
				break;
			} else {
				hashmap[numbers[i]]=i+1;
			}
		}
		return r;
	}
};

int main()
{
    Solution solution;
    int numbers[] = {2, 7, 11, 15};
    vector<int> num(numbers, numbers + 4);
    vector<int> r = solution.twoSum(num,9);

	for(vector<int>::iterator it = r.begin();it != r.end();it++) {
		cout << *it << " ";
	}
	cout << endl;
    return 0;
}