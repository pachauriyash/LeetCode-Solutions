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
    /*void inorder(TreeNode* root,vector<int>& v){
        if(root==NULL){return;}
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorder(root,v);
        return v[k-1];
    } */
    int inorder(TreeNode* root,int&i,int k){
        if(root==NULL){return -1;}
        //l
        int left=inorder(root->left,i,k);
        if(left!=-1){return left;}
        //n
        i++;
        if(i==k){return root->val;}
        return inorder(root->right,i,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        return inorder(root,i,k);
    } 
};