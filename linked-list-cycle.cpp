/*
Solution for LeetCode problem

Title: Linked List Cycle 
URL: http://oj.leetcode.com/problems/linked-list-cycle/
Version: 1.0

Created by Darcy Liu on 3/21/14.
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
	bool hasCycle(ListNode *head) {
		ListNode *p,*mark;
		bool _has = false;
		if (head==NULL){
			return false;
		}
		mark = head;
		head = head->next;
		while(head!=NULL){
			if (head->next == mark){
				_has = true;
				break;
			}
			p = head;
			head = head->next;
			p->next = mark;
		}
		return _has;
	}
};

int main()
{
	ListNode a1(1),a2(2),a3(3),a4(4),a5(5),a6(6),a7(7),a8(8);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	
	a5.next = &a6;
	a6.next = &a7;
	a7.next = &a6;
	
    Solution solution;
	cout<< solution.hasCycle(&a1) <<endl;
	cout<< solution.hasCycle(&a5) <<endl;
    return 0;
}