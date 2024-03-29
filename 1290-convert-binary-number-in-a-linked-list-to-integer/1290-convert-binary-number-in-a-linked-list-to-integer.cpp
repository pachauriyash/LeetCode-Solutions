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
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        int count=0;
        int sum=0;
        int pow=1;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        count--;
        while(count!=0){
            pow*=2;
            count--;
        }
        temp=head;
        while(temp!=NULL){
            sum+=(temp->val)*(pow);
            temp=temp->next;
            pow=pow/2;
        }
       return sum;
    }
};