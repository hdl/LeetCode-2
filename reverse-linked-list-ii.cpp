/*
Solution for LeetCode problem

Title: Reverse Linked List II
URL: https://oj.leetcode.com/problems/reverse-linked-list-ii/
Version: 1.0

Created by Darcy Liu on 11/8/14.
*/
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
    	ListNode *root = head, *start=NULL, *end, *next, *last = NULL;
    	n -= m;
    	while(--m) {
    		start = root;
    		root = root->next;
    	}

    	while(n>=0) {
    		next = root->next;
    		root->next = last;
    		last = root;
    		root = next;
    		n --;
    	}
    	
    	if (start!=NULL){
    		end = start->next;
    		start->next = last;
    		end->next = root;
    	} else{
    		end = head;
    		end->next = root;
    		head = last;
    	}

    	return head;
    }
};

int main()
{
    Solution solution;

    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    ListNode *r = solution.reverseBetween(&n1,2,4);
    while(r!=NULL) {
    	cout << r->val << "->";
    	r = r->next;
    }
    cout << "NULL" << endl;
    return 0;
}