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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=head;
        if(head==NULL){return head;}
        
        while(curr->next!=NULL){
            if(curr->next->val==curr->val){
                int temp=curr->val;
                
                if(curr==head){
                    while(curr->val==temp){
                        curr=curr->next;
                        if(curr==NULL){
                            head=NULL;
                            return head;}
                    }
                    ;
                    head=curr; 
                    continue;
                }
                while(curr->val==temp){curr=curr->next;if(curr==NULL){prev->next=curr;return head;}}
                prev->next=curr;    
            }
            else{
                prev=curr;
                curr=curr->next;
            }
            
        }
        return head;
    }
};