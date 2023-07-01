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
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        if(size==0){return head;}
        int n=k%size;
        if(n==0){return head;}
        while(normal->next!=NULL){
            size++;
            normal=normal->next;
            count++;
            if(count>n){
                if(delayed==NULL){delayed=head;}
                else{delayed=delayed->next;}
            }
        }
        
        //cout<<delayed->val;
        normal=delayed->next;
        delayed->next=NULL;
        delayed=normal;
        while(delayed->next!=NULL){
            delayed=delayed->next;
        }
        delayed->next=head;
        head=normal;
        return head;
    }
};