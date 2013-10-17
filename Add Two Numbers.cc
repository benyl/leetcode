/*
Add Two Numbers

http://leetcode.com/onlinejudge#question_2

You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain 
a single digit. Add the two numbers and return it as a linked list.

Input (2 - 4 - 3) + (5 - 6 - 4)
Output 7 - 0 - 8
*/

#include <stdio.h>
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1==NULL) return l2;
		if(l2==NULL) return l1;
        
		ListNode *head = l1;
		
		int carry = 0;
		while(true) {
			l1->val += l2->val + carry;
			carry = l1->val / 10;
			l1->val %= 10;
				
			if(!l1->next || !l2->next) break;
            l1=l1->next;
            l2=l2->next;
		}
		
		if(l2->next!=NULL)
			l1->next = l2->next;
			
		while(carry) {
			if(l1->next == NULL)
				l1->next = new ListNode(0);
			l1 = l1->next;

			l1->val += carry;
			carry = l1->val / 10;
			l1->val %= 10;
		}
		
		return head;
    } // end of: addTwoNumbers(ListNode *l1, ListNode *l2)
};

// ========================================================
// test code

void PrintList(ListNode* head)
{
	while(head != NULL)
	{
		cout << head->val;
		if(head->next != NULL)
			cout << " -> ";
		head = head->next;
	}
	cout << endl;
}

void main()
{
	ListNode n1(2);
	ListNode n2(5);
	ListNode n3(5);
	ListNode n4(5);
	ListNode n5(6);
	ListNode n6(4);

	n1.next = &n2;
	n2.next = &n3;
	n4.next = &n5;
	n5.next = &n6;
	
	ListNode* l1 = &n1;
	ListNode* l2 = &n4;

	cout << "l1: ";
	PrintList(l1);
	cout << "l2: ";
	PrintList(l2);
	
	Solution sol;
	
	ListNode* result = sol.addTwoNumbers(l1, l2);
	
	cout << "result: ";
	PrintList(result);
	
	getchar();
}