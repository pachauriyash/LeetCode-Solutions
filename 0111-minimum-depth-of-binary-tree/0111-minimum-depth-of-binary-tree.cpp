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
    
    int minDepth(TreeNode* root) {
        int leftheight;
        int rightheight;
        if(root==NULL){return 0;}
        leftheight=minDepth(root->left);
        rightheight=minDepth(root->right);
        if(leftheight<rightheight){
            if(leftheight==0){
                return rightheight+1;}
            else{return leftheight+1;}
        }
        else{if(rightheight==0){
                return leftheight+1;}
            else{return rightheight+1;}}
    }
};