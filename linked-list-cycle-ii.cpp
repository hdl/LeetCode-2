/*
Solution for LeetCode problem

Title: Linked List Cycle II
URL: https://oj.leetcode.com/problems/linked-list-cycle-ii/
Version: 1.0

Created by Darcy Liu on 8/11/14.
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
    ListNode *detectCycle(ListNode* head)
    {
        ListNode *a, *b;
        if (head == NULL) {
            return NULL;
        }
        a = head;
        b = head;
        while (a != NULL && b!=NULL) {
            a = a->next;
            b = b->next;
            if (b!=NULL){
            	b = b->next;
            }
            if (a == b) {
            	break;
            }
        }
        
        a = head;
        while (a!=b && b!=NULL) {
        	a = a->next;
        	b = b->next;
        }
        return b;
    }
};

int main()
{
    ListNode a1(1), a2(2), a3(3), a4(4), a5(5), a6(6), a7(7), a8(8);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;

    a5.next = &a6;
    a6.next = &a7;
    a7.next = &a5;

    Solution solution;

    if (!solution.detectCycle(&a1)) {
    	cout << "test 1 no cycle" << endl;
    } else {
    	cout << "test 1: " << solution.detectCycle(&a1)->val << endl;
    }

    if (!solution.detectCycle(&a5))
    {
    	cout << "test 2 no cycle" << endl;
    } else {
    	cout << "test 2: " << solution.detectCycle(&a5)->val << endl;
    }
    return 0;
}