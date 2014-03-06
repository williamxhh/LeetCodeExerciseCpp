#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL)
            return NULL;
        
        ListNode* tail = head;
        ListNode* toBeDelete = head;
        ListNode* preDelete = NULL;
        
        while(--n > 0){
            tail = tail->next;
        }
        
        while(tail != NULL && tail->next != NULL){
            tail = tail->next;
            preDelete = toBeDelete;
            toBeDelete = toBeDelete->next;
        }
        
		//这里是考虑删除头结点的情况
        if(preDelete == NULL){
            head = head->next;
            delete toBeDelete;
        }else{
            preDelete->next = toBeDelete->next;
            delete toBeDelete;
        }
        
        return head;
    }
};