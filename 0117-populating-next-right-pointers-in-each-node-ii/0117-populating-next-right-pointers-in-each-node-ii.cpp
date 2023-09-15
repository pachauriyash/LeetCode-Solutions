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
vector<vector<Node*>> levelOrder(Node* root) {
        if(root==NULL) return {};
        vector<vector<Node*>> an;
        queue<Node*>nums;
        
        nums.push(root);
        int len;
        while(!nums.empty()){
            len=nums.size();
            vector<Node*>ans;
            for(int i=0;i<len;i++){
                Node* temp=nums.front();
                nums.pop();
                ans.push_back(temp);
                if(temp->left!=NULL){nums.push(temp->left);}
                if(temp->right!=NULL){nums.push(temp->right);}
            }
            an.push_back(ans);
        }
        return an;
    }
    Node* connect(Node* root) {
        vector<vector<Node*>>level;
        level=levelOrder(root);
        for(int i=0;i<level.size();i++){
            for(int j=0;j<level[i].size()-1;j++){
                level[i][j]->next=level[i][j+1];
            }
            level[i][level[i].size()-1]->next=NULL;
        }
        return root;
    }
};