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
    
    bool areequal(TreeNode* root,TreeNode* subRoot){
        if(root==NULL || subRoot==NULL){return root==subRoot;}
        return root->val==subRoot->val && areequal(root->left,subRoot->left) && areequal(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       return areequal(root,subRoot)||(root->left && isSubtree(root->left,subRoot))||(root->right && isSubtree(root->right,subRoot));
    }
};