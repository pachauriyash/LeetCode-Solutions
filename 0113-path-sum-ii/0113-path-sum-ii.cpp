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
    void traverse(TreeNode* root,int sum,vector<int> vect,vector<vector<int>>&vg,int target){
        if(root==NULL){return;}
        sum+=root->val;
        vect.push_back(root->val);    
        if(root->left==NULL && root->right==NULL && sum==target){vg.push_back(vect); return;}
        traverse(root->left,sum,vect,vg,target);
        traverse(root->right,sum,vect,vg,target);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> vect;
        vector<vector<int>> vg;
        traverse(root,0,vect,vg,targetSum);
        return vg;
    }
};