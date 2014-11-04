/*
Solution for LeetCode problem

Title: 
URL: 
Version: 1.0

Created by Darcy Liu on 8/2/14.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > r;
	vector<int> s;
	vector<vector<int> > combine(int n, int k) { 
		find(n,k,1);
		return r;
	}
	void find(int n,int k,int x) {
		if (s.size()==k) {
			r.push_back(s);
			return;
		}
		for (int i = x; i <= n; ++i){
			s.push_back(i);
			find(n,k,i+1);
			s.pop_back();
		}
	}
};

int main()
{
    Solution solution;
    vector<vector<int> > r = solution.combine(4,2);
    for (int i = 0; i < r.size(); ++i){
    	for (int j = 0; j < r[i].size(); ++j){
    		cout << r[i][j] << " ";
    	}
    	cout << endl;
    }
    return 0;
}