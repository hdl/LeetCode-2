/*
Solution for LeetCode problem

Title: Reorder List
URL: http://oj.leetcode.com/problems/reorder-list/
Version: 1.0

Created by Darcy Liu on 3/18/14.
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
	void reorderList(ListNode *head) {
		struct ListNode *position,*first,*last,*tmp;
		if (head==NULL){
			return;
		}
		position = this->midNode(head);
		position = this->reverseList(position);
		first = head;
		last = position;
		while(first!=NULL&&last!=NULL){
			position = first->next;
			first->next = last;
			tmp = last->next;
			last->next = position;

			first = position;
			last = tmp;
		}
	}
	ListNode * midNode(ListNode *head){
		struct ListNode *first,*last,*position;
		first = head;
		last = head;
		position = first;
		while(first!=NULL && last!=NULL){
			position = first;
			first = first->next;
			last = last->next;
			if (last!=NULL){
				last = last->next;
			}
		}
		position->next = NULL;
		return first;
	}
	ListNode * reverseList(ListNode *head) {
		struct ListNode *prev,*position,*next;
		position = head;
		prev = NULL;
		while(position!=NULL){
			next = position->next;
			position->next = prev;
			prev = position;
			position = next;
		}
		return prev;
	}
	/* //Time Limit Exceeded
	void exchange(ListNode *head){
        struct ListNode *first,*last,*position;
		if(head==NULL){
			return;
		}else{
			first = head;
			last = head;
			
			position = head->next;
			while(position!=NULL){
				last = position;
				position = position->next;
				if(position==NULL){
					last = NULL;
				}else if(position->next==NULL){
					last->next = NULL;
					last = position;
					break;
				}
			}
		}
		if (last!=NULL){
			position = first->next;
			first->next = last;
			last->next = position;
			this->exchange(position);
		}
	}*/
	void print(ListNode *head){
		while(head != NULL){
			cout<< head->val<<endl;
			head = head->next;
		}
	}
};

int main()
{
	ListNode a1(1),a2(2),a3(3),a4(4),a5(5),a6(6),a7(7),a8(8);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	//a4.next = &a5;
	a5.next = &a6;
	a6.next = &a7;
	//a7.next = &a8;

	Solution solution;
	solution.reorderList(&a1);
	solution.print(&a1);

	cout<<"---"<<endl;
	solution.reorderList(&a5);
	solution.print(&a5);

	cout<<"---"<<endl;
	solution.reorderList(&a8);
	solution.print(&a8);
    return 0;
}
