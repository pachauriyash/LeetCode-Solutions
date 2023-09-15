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
    void traverse(TreeNode* root,vector<int>&preorder){
        if(root==NULL)return;
        traverse(root->left,preorder);
        preorder.push_back(root->val);
        traverse(root->right,preorder);

    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>preorder;
        traverse(root,preorder);
        int ans=INT_MAX;
        for(int i=1;i<preorder.size();i++){
            ans=min(ans,preorder[i]-preorder[i-1]);
        }
        return ans;
    }
};