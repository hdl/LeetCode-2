/*
Solution for LeetCode problem

Title: Remove Nth Node From End of List
URL: https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
Version: 1.0

Created by Darcy Liu on 11/3/14.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	ListNode *start = head,*root = head;
    	while(n--){
    		start = start->next;
    	}
    	if (start!=NULL) {
    		while(start!=NULL&&start->next!=NULL){
    			root = root->next;
    			start = start->next;
    		}
    		root->next = root->next->next;
    	} else {
    		head = head->next;
    	}
    	return head;
    }
};

int main()
{
    Solution solution;
    ListNode n1(1),n2(2),n3(3),n4(4),n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    ListNode *r = solution.removeNthFromEnd(&n1,2);
    while(r!=NULL) {
    	cout << r->val << " ";
    	r = r->next;
    }
    cout << endl;
    return 0;
}