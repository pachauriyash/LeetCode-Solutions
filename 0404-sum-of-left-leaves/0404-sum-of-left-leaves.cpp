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
    int sum=0;
    void traverse(TreeNode* root,int i){
        if(root==NULL){return;}
        traverse(root->left,1);
        if(root->left==NULL && root->right==NULL && i){sum+=root->val; return;}
        traverse(root->right,0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        traverse(root,0);
        return sum;
    }
};