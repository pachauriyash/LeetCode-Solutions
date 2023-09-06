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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        int groupsize=size/k;
        int remsize=size%k;
        vector<ListNode*>ans;
        temp=head;
        ListNode* temhead=head;
        int tempsize=0;
        if(size<k){
            while(k>0){                
                if(temp!=NULL){
                    temp=temp->next;
                    temhead->next=NULL;
                    ans.push_back(temhead);
                    temhead=temp;
                }else{
                    ans.push_back(temp);
                }
                k--;
            }
        }else{
            while(temp!=NULL){
            tempsize++;
            if(tempsize==groupsize){
                if(remsize!=0){
                    temp=temp->next;
                    remsize--;
                }
                ListNode* sec=temp;
                temp=temp->next;
                sec->next=NULL;
                ans.push_back(temhead);
                temhead=temp;
                tempsize=0;
            }
            else{temp=temp->next;}
        }
        }
        
        return ans;
    }
};