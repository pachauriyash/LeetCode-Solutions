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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        int cnt=0;
        int n=0;
        ListNode* prev2=NULL;
        if(head->next==NULL){return true;}
        while(fast!=NULL && fast->next!=NULL){
            prev2=slow;
            slow=slow->next;
            fast=fast->next->next;
            cnt++;
        }

        if(fast==NULL){
            n=cnt*2;
            ListNode* start=slow;
        // ListNode* nexxt=start->next;
           ListNode* prev=NULL;
            while(start!=NULL){
                ListNode* temp=start->next;
                start->next=prev;
                prev=start;
                start=temp;
            }
            prev2->next=prev;
        }
        else{
            n=cnt*2+1;
            ListNode* start=slow->next;
            prev2=prev2->next;
        // ListNode* nexxt=start->next;
           ListNode* prev=NULL;
            while(start!=NULL){
                ListNode* temp=start->next;
                start->next=prev;
                prev=start;
                start=temp;
            }
            prev2->next=prev;
        }
        prev2=prev2->next;
        while(prev2!=NULL){
            if(head->val!=prev2->val){return false;}
            head=head->next;
            prev2=prev2->next;
        }

        return true;
    }
};