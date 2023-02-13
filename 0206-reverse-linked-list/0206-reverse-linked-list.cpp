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
    ListNode* reverseList(ListNode* head) {
        /* stack<int> m;
        ListNode* temp=head;
        if(head==NULL){return head;}
        while(temp!=NULL){
            m.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(!m.empty()){
            int x=m.top();
            m.pop();
            temp->val=x;
            temp=temp->next;
        }
        return head; */
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return head;
    }
};