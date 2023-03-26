/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void levelorder(Node* &root){
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        Node* prev=NULL;
        Node* temp=NULL;
        while (!q.empty())
        {   
            prev=temp;
            temp=q.front();
            
            q.pop();
            if(prev!=NULL){prev->next=temp;}
         
            if(temp==NULL){//purana level complete traverse hochuka hai
                //cout<<endl;
                if(!q.empty()){//queue still has some child nodes
                    q.push(NULL);
                }
            }
            else{
                //cout<<temp->data <<" ";
                if(temp->left){q.push(temp->left);}
                if(temp->right){q.push(temp->right);}
            }
       
        }  
}
    Node* connect(Node* &root) {
        if(root==NULL){return NULL;}
        levelorder(root);
        return root;
    }
};