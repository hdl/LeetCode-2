/*
Solution for LeetCode problem

Title: 
URL: 
Version: 1.0

Created by Darcy Liu on 8/2/14.
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
    ListNode *swapPairs(ListNode *head) {
        ListNode *r  = head;
        ListNode *p, *q;
        if (head!=NULL) {
            p = head;
            if (head->next!=NULL) {
                
                head = head->next;

                p->next = head->next;
                head->next = p;
                
                r = head; // the second node is the head
            }
            while(p!=NULL && p->next !=NULL) {
                head = p->next;
                q = head->next;

                if (q!=NULL){
                    p->next = q;
                    head->next = q->next;
                    q->next = head;
                }
                p = head;
            }
        }
        
        return r;
    }
};

int main()
{
    Solution solution;

    ListNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    //n5.next = &n6;

    ListNode *r = solution.swapPairs(&n1);
    while(r!=NULL){
        cout << r->val << endl;
        r = r->next;
    }
    return 0;
}