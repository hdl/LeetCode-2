/*
Solution for LeetCode problem

Title: Rotate List
URL: https://oj.leetcode.com/problems/rotate-list/
Version: 1.0

Created by Darcy Liu on 11/11/14.
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
	ListNode *rotateRight(ListNode *head, int k) {
		ListNode *root = head, *last = head;
		
		while(k-- && last!=NULL ) {
			last = last->next;
			// if k is biger than list size
			// rotate k = k % size
			// this solution is very slowly.
			if (last==NULL) { 
				last = head;
			}
		}
		
		while(last!=NULL&&last->next!=NULL) {
			root = root->next;
			last = last->next;
		}

		if (last) {
			last->next = head;
			head = root->next;
			root->next = NULL;
		}
		return head;
	}
};

int main()
{
	{
		Solution solution;
		// 1->2->3->4->5->NULL
		ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
		n1.next = &n2;
		n2.next = &n3;
		n3.next = &n4;
		n4.next = &n5;

		ListNode *r = solution.rotateRight(&n1,2);
		while(r!=NULL) {
			cout << r->val << "->";
			r = r->next;
		}
		cout << "NULL" << endl;
	}

	{
		Solution solution;
		// 1->2->NULL
		ListNode n1(1), n2(2);
		n1.next = &n2;

		ListNode *r = solution.rotateRight(&n1,3);
		while(r!=NULL) {
			cout << r->val << "->";
			r = r->next;
		}
		cout << "NULL" << endl;
	}
	
	return 0;
}