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
    int count=0;
    /* //brute force solution
    
    int heightt(TreeNode* root){
        int leftheight;
        int rightheight;
        if(root==NULL){return 0;}
        leftheight=heightt(root->left);
        rightheight=heightt(root->right);
        if(leftheight>rightheight){return leftheight+1;}
        else{return rightheight+1;}
    }
    int height(TreeNode* root){
        int leftheight=heightt(root->left);
        int rightheight=heightt(root->right);
        return leftheight+rightheight;
    }
    void diameter(TreeNode* temp){
        if(temp==NULL){return;}
        diameter(temp->left);
        int h=height(temp);
        if(h>count){count=h;}
        diameter(temp->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        int ans=count;
        count=0;
        return ans;
    } */
    //optimised solution
    int heightt(TreeNode* root){
        int leftheight;
        int rightheight;
        if(root==NULL){return 0;}
        leftheight=heightt(root->left);
        rightheight=heightt(root->right);
        if(count<leftheight+rightheight){count=leftheight+rightheight;}
        if(leftheight>rightheight){return leftheight+1;}
        else{return rightheight+1;}
    }
    int diameterOfBinaryTree(TreeNode* root) {
        heightt(root);
        int ans=count;
        count=0;
        return ans;
    } 
};