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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr=head;
        ListNode* prev=head;
        if(head==NULL){return head;}
        //if(head->val==val){head=head->next;}
        while(curr->next!=NULL){
            curr=curr->next;
            if(curr->val==val){
                prev->next=curr->next;
                curr=prev;
            }
            else{
                //curr=curr->next;
                prev=prev->next;
            }
        }
        if(head->val==val){head=head->next;}
        return head;
    }
};