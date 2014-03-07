#include<iostream>
#include<stack>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if(head == NULL || k <= 1){
			return head;
		}
		
		int len = getListLen(head);
		if(len<k)
			return head;
		else{
			return reverseKGroupHelper(head,len,k);
		}
	}
	
	ListNode* reverseKGroupHelper(ListNode* head,int len,int k){
		if(len<k){
			return head;
		}else{
			stack<ListNode*> nodeStack;
			int temp = k;
			while(temp--){
				nodeStack.push(head);
				head = head->next;
			}
			ListNode* p = reverseKGroupHelper(head,len-k,k);
			head = nodeStack.top();
			ListNode* q = NULL;
			while(!nodeStack.empty()){
				q = nodeStack.top();
				nodeStack.pop();
				 if(!nodeStack.empty()){
					q->next = nodeStack.top();
				}
			}
			q->next = p;
			return head;
		}
	}
	
	int getListLen(ListNode* head){
		ListNode* p = head;
		int len = 0;
		while(p != NULL){
			len++;
			p = p->next;
		}
		return len;
	}
};

int main()
{
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	p1->next = p2;
	Solution so;
	so.reverseKGroup(p1,2);
}
