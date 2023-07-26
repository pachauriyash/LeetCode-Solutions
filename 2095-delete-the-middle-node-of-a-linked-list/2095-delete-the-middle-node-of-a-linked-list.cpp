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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL ){
            fast=fast->next->next;
            slow=slow->next;
        }
        if(slow==fast)return NULL;
        if(slow->next==NULL){head->next=NULL; return head;}
        slow->val=slow->next->val;
        fast=slow->next;
        slow->next=fast->next;
        fast->next=NULL;
        return head;
    }
};