/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*void inorder(TreeNode* temp,vector<int>& v){
        if(temp==NULL){v.push_back(-1);return;}
        inorder(temp->left,v);
        v.push_back(temp->val);
        inorder(temp->right,v);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>v1,v2;
        inorder(p,v1);
        inorder(q,v2);
        if(v1.size()!=v2.size()){return false;}
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]){return false;}
        }
        return true;
        
        
    } */
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){return true;}
        if((p==NULL && q!=NULL) ||(p!=NULL && q==NULL)){return false;}
        if(p->val!=q->val){return false;}
        bool ans=isSameTree(p->left,q->left);
        if(ans==false){return false;}
        bool ans1=isSameTree(p->right,q->right);
        if(ans1==false){return false;}
        return true;
    }
};