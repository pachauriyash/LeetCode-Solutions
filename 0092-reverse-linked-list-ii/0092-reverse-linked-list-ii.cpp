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
    ListNode* reverseList(ListNode* head,int count,ListNode* prevhead) {
        ListNode* start=head;
        // ListNode* nexxt=start->next;
        ListNode* prev=NULL;
        while(count>0){
            ListNode* temp=start->next;
            start->next=prev;
            prev=start;
            start=temp;
            count--;
        }
        
        if(prevhead!=NULL)prevhead->next=prev;
        head->next=start;
        return prev;
        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prevhead=NULL;
            ListNode* temp=head;
        int count=1;
        while(count!=left){
            prevhead=temp;
            temp=temp->next;
            count++;
        }
        ListNode* ans=reverseList(temp,right-left+1,prevhead);
        if(left==1)return ans;
        return head;
    }
};