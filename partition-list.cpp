/*
Solution for LeetCode problem

Title: Partition List
URL: https://oj.leetcode.com/problems/partition-list/
Version: 1.0

Created by Darcy Liu on 8/17/14.
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
    ListNode *partition(ListNode *head, int x) {
    	ListNode *p,*q,*t;
    	ListNode left(0),right(0);

    	p = &left;
    	q = &right;

    	while(head!=NULL) {
    		if(head->val < x) {
    			p->next = head;
    			p = p->next;
    		} else {
    			q->next = head;
    			q = q->next;
    		}
    		head = head->next;
    		p->next = NULL;
    		q->next = NULL;
    	}
    	p->next = right.next;
        return left.next;
    }
};

int main()
{
    Solution solution;
    ListNode n1(1),n2(4),n3(3),n4(2),n5(5),n6(2);//1->4->3->2->5->2
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    ListNode a2(2),a1(1);
    a2.next = &a1;

    ListNode *r = solution.partition(&n1,3);
    while(r!=NULL) {
    	cout << r->val << " ";
    	r = r->next;
    }
    cout << endl;

    return 0;
}