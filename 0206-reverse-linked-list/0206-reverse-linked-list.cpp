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
        ListNode* start=head;
        // ListNode* nexxt=start->next;
        ListNode* prev=NULL;
        while(start!=NULL){
            ListNode* temp=start->next;
            start->next=prev;
            prev=start;
            start=temp;
        }
        head=prev;
        return head;
    }
};