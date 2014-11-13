/*
Solution for LeetCode problem

Title: Implement strStr()
URL: https://oj.leetcode.com/problems/implement-strstr/
Version: 1.0

Created by Darcy Liu on 11/13/14.
*/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
    	int index = -1, find = 0, len = 0;
    	char *n = needle;
    	if (*haystack == *n && *haystack=='\0') {
    		index = 0;
    	}
    	while(haystack!=NULL) {
    		len ++;
    		if (*n=='\0') {
    			index = find;
    			break;
    		}
    		if (*haystack=='\0') {
    			break;
    		}
    		
    		if (*n == *haystack) {
    			n ++;
    		} else {
    			n = needle;
    			haystack -= (len-find-1);
    			len -= (len-find-1);
    			find = len;
    		}
    		haystack++;
    	}
        return index;
    }
};

int main()
{
	Solution solution;
	{
		char haystack[] = "a";
		char needle[] = "a";
		cout << solution.strStr(haystack,needle) << endl;
	}
	
	{
		char haystack[] = "mississippia";
		char needle[] = "issip";
		cout << solution.strStr(haystack,needle) << endl;
	}
    return 0;
}