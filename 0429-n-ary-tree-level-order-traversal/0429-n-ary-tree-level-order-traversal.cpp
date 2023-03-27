/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> qq;
        if(root==NULL){return qq;}
        vector<int> t;
        queue<Node*> q;
        Node* temp=root;
        q.push(temp);
        int count=1;
        int sum=0;
        while(!q.empty()){
            temp=q.front();
            if(count>0){sum+=temp->children.size();t.push_back(temp->val);}
            count--;
            if(count==0){qq.push_back(t);t.clear();count=sum;sum=0;}
           
            q.pop();
            for(int i=0;i<temp->children.size();i++){
                q.push(temp->children[i]);
               
            }
        }
        
        
        return qq;
        
    }
};