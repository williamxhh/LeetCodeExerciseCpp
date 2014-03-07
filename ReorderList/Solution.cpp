#include<iostream>
#include<stack>
#include<queue>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	void reorderList(ListNode *head) {
		if(head == NULL){
			return;
		}
		ListNode* n = head;
		int len = 0;
		queue<ListNode*> nodeQueue;
		stack<ListNode*> nodeStack;
		while(n != NULL){
			len++;
			nodeQueue.push(n);
			nodeStack.push(n);
			n = n->next;
		}
		if(len < 3)
			return;
			
		int newlen  = len/2;
		ListNode* p = NULL;
		ListNode* q = NULL;
		while(newlen-- != 0){
			p = nodeQueue.front();
			nodeQueue.pop();
			if(q != NULL){
				q->next = p;
			}
			q = nodeStack.top();
			nodeStack.pop();
			p->next = q;
			q->next = NULL;
		}
		if(len & 1 != 0){
			p = nodeQueue.front();
			q->next = p;
			p->next = NULL;
		}
	}
};

int main()
{
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(3);
	p1->next = p2;
	p2->next = p3;

	Solution so;
	so.reorderList(p1);
}
