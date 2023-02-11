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
        ListNode* temp1;
        temp1=head;
        if(head==NULL){return head;}
        else{
            while(temp1->next!=NULL){
            int temp=0;
            if(temp1->val==temp1->next->val){
                temp=1;
                temp1->next=temp1->next->next;
               
            }
                if(temp==0){temp1=temp1->next;}
            }
            return head;
        }
        
    }
};