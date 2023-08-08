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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root==NULL)return NULL;
        // if(root==p || root==q){return root;}
        // TreeNode* left=lowestCommonAncestor(root->left,p,q);
        // TreeNode* right=lowestCommonAncestor(root->right,p,q);
        // if((left==p && right==q)||(left==q && right==p)){return root;}
        // if(left==NULL && right!=NULL){return right;}
        // return left;
        if(root==NULL)return NULL;
        if((p->val>=root->val && q->val<=root->val)||(p->val<=root->val && q->val>=root->val)){return root;}
        if(p->val>root->val && q->val>root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(p->val<root->val && q->val<root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
    }
};