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
    void insertattail(ListNode* &tail, int d){
    //new node create
    ListNode* temp= new ListNode(d);
    tail->next=temp;
    tail=temp;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* temp = head;

        while(temp1 != NULL && temp2 !=NULL){
            int sum = temp1->val+temp2->val +carry;
            carry=0;
            if(sum>9){
                carry=1;
                sum=sum-10;
            }
            insertattail(temp,sum);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp2 != NULL){
            int sum = temp2->val + carry;
            carry = 0;
            if(sum>9){
            carry=1;
            sum=sum-10;
            }

            insertattail(temp,sum);
            temp2 = temp2->next;
        }
        while(temp1 != NULL){
            int sum = temp1->val + carry;
            carry = 0;
            if(sum>9){
            carry=1;
            sum=sum-10;
            }

            insertattail(temp,sum);
            temp1 = temp1->next;
        }
        if(carry == 1){
            insertattail(temp,carry);
        }
    return head->next;
    }
};