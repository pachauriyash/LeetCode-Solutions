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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        temp=head;
        if(count==1){head=head->next; return head;}
        if(count==n){head=head->next;return head;}
        
        while(count-n-1>0){
            temp=temp->next;
            count--;
        }
        ListNode* curr=temp->next;
        temp->next=curr->next;
        return head;
    }
};