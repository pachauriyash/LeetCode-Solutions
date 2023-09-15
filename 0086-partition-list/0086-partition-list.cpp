/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* first=NULL;
        ListNode* second=NULL;
        ListNode* firsthead=NULL;
        ListNode* secondhead=NULL;
        ListNode* temp=head;
        if(head==NULL)return head;
        while(temp!=NULL){
            if(temp->val<x){
                if(first==NULL){
                    first=temp;
                    firsthead=first;
                }else{
                    first->next=temp;
                    first=temp;
                }
            }else{
                if(second==NULL){
                    second=temp;
                    secondhead=second;
                }else{
                    second->next=temp;
                    second=temp;
                }
            }
            temp=temp->next;
        }
        if(second!=NULL){second->next=NULL;}
        if(firsthead==NULL){return secondhead;}
        first->next=secondhead;
        
        return firsthead;
    }
};