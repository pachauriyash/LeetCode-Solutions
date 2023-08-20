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
    ListNode* reverseList(ListNode* head,int k,ListNode* previ) {
        ListNode* start=head;
        ListNode* beg=head;
        // ListNode* nexxt=start->next;
        ListNode* prev=previ;
        int count=0;
        while(count!=k){
            ListNode* temp=start->next;
            start->next=prev;
            prev=start;
            start=temp;
            count++;
        }
        beg->next=start;
        if(previ)previ->next=prev;
        //head=prev;
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int nodes=0;
        ListNode* temp=head;
        while(temp){temp=temp->next;nodes++;}
        head= reverseList(head,k,NULL);
       
        ListNode* head2=head;
        ListNode* prev=NULL;
        int numberoftimes=nodes/k;
        numberoftimes--;
        while(numberoftimes){
            int count=0;
            while(count!=k){
            prev=head2;
            head2=head2->next;
            count++;
            }
            head2=reverseList(head2,k,prev);
            numberoftimes--;
        }
        return head;
    }
};