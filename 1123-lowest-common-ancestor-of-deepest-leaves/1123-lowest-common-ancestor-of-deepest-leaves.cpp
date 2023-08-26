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
    int maxDepth(TreeNode* root) {
        int leftheight;
        int rightheight;
        if(root==NULL){return 0;}
        leftheight=maxDepth(root->left);
        rightheight=maxDepth(root->right);
        if(leftheight>rightheight){return leftheight+1;}
        else{return rightheight+1;}
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)return NULL;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        if(l==r)return root;
        else if(l>r){
            return lcaDeepestLeaves(root->left);
        }
        else{
            return lcaDeepestLeaves(root->right);
        }
        return NULL;
    }
};