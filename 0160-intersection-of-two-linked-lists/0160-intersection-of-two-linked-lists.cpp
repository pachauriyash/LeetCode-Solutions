/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //ListNode* tempA=headA;
        //ListNode* tempB=headB;
        /*while(tempA!=NULL){
            while(tempB!=NULL){
                if(tempA==tempB){return tempA;}
                tempB=tempB->next;
            }
            tempB=headB;
            tempA=tempA->next;
        } 
        return NULL */
        /* while(tempA!=tempB){
            if(tempA==NULL){tempA=headA;}
            else{tempA=tempA->next;}
            if(tempB==NULL){tempB=headB;}
            else{tempB=tempB->next;}
            
        }
        return tempA; */
        int n = 0;
		int m = 0;
		ListNode* ptr1 = headA;
		ListNode* ptr2 = headB;
		while(ptr1 != NULL){
			n++;
			ptr1 = ptr1 -> next;
		}
		while(ptr2 != NULL){
			m++;
			ptr2 = ptr2 -> next;
		}
		int t = abs(n - m);
		if(n > m){
			while(t){
				headA = headA -> next;
				t--;
			}
		}
		else{
			while(t){
				headB = headB -> next;
				t--;
			}
		}
		while(headA != NULL and headB != NULL){
			if(headA == headB){
				return headA;
			}
			headA = headA -> next;
			headB = headB -> next;
		}
		return NULL;
    }
};