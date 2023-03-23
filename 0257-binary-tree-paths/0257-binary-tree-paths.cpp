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
    vector<string> v;
    void traverse(TreeNode* root,string s){
        if(root==NULL){return;}
        //concate string with the element
        if(!s.empty()){s+="->";}
        s+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){v.push_back(s);return;}
        traverse(root->left,s);
        traverse(root->right,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s=""; 
        traverse(root,s);
         return v;
    }
};