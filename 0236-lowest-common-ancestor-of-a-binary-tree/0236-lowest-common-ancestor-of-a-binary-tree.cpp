/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* root,TreeNode* temp,vector<TreeNode*>&pre){
        if(root==NULL)return;
        pre.push_back(root);
        if(pre.size()>0){
            if(pre.back()==temp)return;
        }
        preorder(root->left,temp,pre);
        preorder(root->right,temp,pre);
        if(pre.size()>0){
            if(pre.back()==temp)return;
        }
        pre.pop_back();
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // vector<TreeNode*>pre1,pre2;
        // preorder(root,p,pre1);
        // preorder(root,q,pre2);
        // TreeNode* prev=NULL;
        // int tt=min(pre1.size(),pre2.size());
        // for(int i=0;i<tt;i++){
        //     if(pre1[i]!=pre2[i])return prev;
        //     prev=pre1[i];
        // }
        // return prev;
        if(root==NULL)return NULL;
        if(root==p || root==q){return root;}
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if((left==p && right==q)||(left==q && right==p)){return root;}
        if(left==NULL && right!=NULL){return right;}
        return left;
    }
};