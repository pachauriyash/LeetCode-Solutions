/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    Node* copyRandomList(Node* head) {
       Node* temp=head;
        while(temp!=NULL){
            Node* temp1=new Node(temp->val);
            temp1->next=temp->next;
            temp->next=temp1;
            temp=temp1->next;
        }
        temp=head;
        if(head==NULL)return NULL;
        Node* temp2=head->next;
        while(temp!=NULL){
            Node* randomm=temp->random;
            if(randomm==NULL)temp2->random=NULL;
            else temp2->random=randomm->next;
            temp=temp2->next;
            if(temp!=NULL)temp2=temp->next;
        }
        temp=head->next;
        temp2=head;
        Node* newhead=head->next;
        while(temp->next!=NULL){
            temp2->next=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
            temp2=temp2->next;
        }
        temp2->next=NULL;
        return newhead;
    }
};