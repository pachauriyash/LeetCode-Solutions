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
    ListNode* oddEvenList(ListNode* head) {
     ListNode* odd=head;
        if(head==NULL)return head;
        ListNode* even=head->next;
        ListNode* temp=odd;
        ListNode* temp2=even;
        while(temp!=NULL && temp->next!=NULL && temp2!=NULL && temp2->next!=NULL){
            temp->next=temp->next->next;
            temp=temp->next;
            temp2->next=temp2->next->next;
            temp2=temp2->next;
        }
        temp->next=even;
        return odd;
    }
};