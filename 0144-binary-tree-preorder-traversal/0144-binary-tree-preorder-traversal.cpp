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
/*vector<int>nums;
vector<int> preorder(TreeNode* root){
    if(root==NULL){return nums;}
        nums.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
        return nums;
} */

class Solution {
    public:
    //vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
        /*if(root){
            ans.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return ans; */
        vector<int> v;
        stack<TreeNode*> st;
        TreeNode* curr=root;
        while(!st.empty() || curr!=NULL){
            if(curr!=NULL){
                st.push(curr);
                v.push_back(curr->val);
                curr=curr->left;
            }
            else{
                curr=st.top();
                st.pop();
                curr=curr->right;
            }
        }
        return v;
    }
};