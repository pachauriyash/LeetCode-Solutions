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
    //storing preorder and then giving diff SC O(N+H)
    // void traverse(TreeNode* root,vector<int>&preorder){
    //     if(root==NULL)return;
    //     traverse(root->left,preorder);
    //     preorder.push_back(root->val);
    //     traverse(root->right,preorder);

    // }
    // int getMinimumDifference(TreeNode* root) {
    //     vector<int>preorder;
    //     traverse(root,preorder);
    //     int ans=INT_MAX;
    //     for(int i=1;i<preorder.size();i++){
    //         ans=min(ans,preorder[i]-preorder[i-1]);
    //     }
    //     return ans;
    // }
    // A little better way
    int traverse(TreeNode* root,int&ans,int&prevval){

        if(root->left)traverse(root->left,ans,prevval);
        if(prevval>=0)ans=min(ans,root->val-prevval);
        prevval=root->val;
        if(root->right)traverse(root->right,ans,prevval);
        return ans;
    }
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX,val=-1;
        traverse(root,ans,val);
        return ans;
    }
};