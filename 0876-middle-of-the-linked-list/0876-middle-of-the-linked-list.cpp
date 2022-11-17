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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int middle;
        if(head==NULL){return 0;}
        int count=1;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        if(count%2==0){
            middle=(count/2)+1;
        }
        else{
            middle=(count+1)/2;
        }
        temp=head;
        while(middle>1){
            middle--;
            temp=temp->next;
        }
        return temp;
    }
};