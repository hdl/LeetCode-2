/*
Solution for LeetCode problem

Title: ZigZag Conversion
URL: https://oj.leetcode.com/problems/zigzag-conversion/
Version: 1.0

Created by Darcy Liu on 12/4/14.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string _convert(string s, int nRows) {
		vector<string> mylist;
		for (int i = 0; i < nRows; ++i){
			string str = ""; 
			mylist.insert(mylist.end(),str);
		}
		for (int i = 0, j = 0, back = 1, count = s.length(); i < count; ++i){
			string str = mylist[j];

			str.append(s.substr(i, 1));
			mylist[j] = str;
			//cout << i << " "<< j << " " << str << endl;
			if (j==(nRows-1)){
				back = -1;
			}
			if (j==0) {
				back = 1;
			}
			if (back>0){
				j++;
			} else {
				j --;
			}
		}
		string r = "";
		for (int i = 0; i < nRows; ++i){
			string str = mylist[i];
			r.append(str);
		}
		return r;
	}
	string convert(string s, int nRows) {
		if (nRows<2) {
			return s;
		}
		string r;
		int step = 2*nRows - 2;
		for (int i = 0; i < nRows; ++i) {
			for (int pos = i, row = 0, fold = 0; pos < s.size(); row++,pos = step * row + i) {
				r.append(1,s[pos]);
				if(i==0 || i == (nRows-1)){
					continue;
				}
				fold = pos + (nRows-i-1)*2;// in the same row
				if (fold < s.size()) {
					r.append(1, s[fold]);  
				}
			}
		}
		return r;
	}
};

int main()
{
    Solution solution;
    cout << solution.convert("PAYPALISHIRING", 3) << endl;
    cout << solution._convert("PAYPALISHIRING", 3) << endl;
    cout << solution.convert("ABCDE", 4) << endl;
    cout << solution.convert("AB", 2) << endl;
    return 0;
}