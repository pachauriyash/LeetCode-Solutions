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
    void preorder(TreeNode* root,string &temp){
        if(root==NULL){return;}
        temp+='('+to_string(root->val);
        if(root->left==NULL && root->right!=NULL){temp+="()";}
        preorder(root->left,temp);
        //if(root->left!=NULL && root->right==NULL){temp+="()";}
        preorder(root->right,temp);
        temp+=')';
}
    string tree2str(TreeNode* root) {
        string temp="";
        preorder(root,temp);
        return temp.substr(1,temp.size()-2);
    }
};