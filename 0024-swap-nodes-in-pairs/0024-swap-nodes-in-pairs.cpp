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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev=head;
        ListNode* nex=head;
        ListNode* curr=head;
        if(head==NULL){return head;}
        if(curr->next==NULL){return head;}
        
        nex=nex->next;
        ListNode* temp=nex;
        curr->next=nex->next;
        nex->next=prev;
        prev=curr;
        head=temp;
        if(curr->next!=NULL){nex=curr->next->next;}
        else{nex=NULL;return head;}
        curr=curr->next;
        while(nex!=NULL && prev!=NULL){
            ListNode* temp=nex;
            curr->next=nex->next;
            nex->next=curr;
            prev->next=temp;
            prev=prev->next->next;
            nex=curr;
            curr=temp;
            if(nex->next!=NULL){nex=nex->next->next;}
            else{nex=NULL;}
            curr=curr->next->next;
        }
        return head;
    }
};