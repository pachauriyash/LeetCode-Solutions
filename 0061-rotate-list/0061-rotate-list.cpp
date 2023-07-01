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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* delayed=NULL;
        ListNode* normal=head;
        int count=1;
        int size=0;
        ListNode* temp=head;
        //taking the size of the linked list
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        //edge cases
        if(size==0){return head;}
        //so that we don't have to repeat it multiple times as after size times the list becomes same
        int n=k%size;
        if(n==0){return head;}
        //going to the n nodes back from end
        while(normal->next!=NULL){
            size++;
            normal=normal->next;
            count++;
            if(count>n){
                if(delayed==NULL){delayed=head;}
                else{delayed=delayed->next;}
            }
        }
        
        //now just pointing them to correct position
        normal=delayed->next;
        delayed->next=NULL;
        delayed=normal;
        //going to the end of the separate linked list section so that it can be made to point to the head
        while(delayed->next!=NULL){
            delayed=delayed->next;
        }
        delayed->next=head;
        head=normal;
        return head;
    }
};