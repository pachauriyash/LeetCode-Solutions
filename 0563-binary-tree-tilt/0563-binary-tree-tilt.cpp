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
    int traverse(TreeNode* root){
        int leftsum=0;
        int rightsum=0;
        if(root==NULL){return 0;}
        leftsum=traverse(root->left);
        rightsum=traverse(root->right);
        //sum+=findTilt(root->right);}
        sum+=abs(leftsum-rightsum);
        return root->val+leftsum+rightsum;
    }
    int findTilt(TreeNode* root) {
        traverse(root);
        return sum;
    }
};