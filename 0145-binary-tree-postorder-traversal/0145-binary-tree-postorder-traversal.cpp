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
    //vector<int>nums;
    vector<int> postorderTraversal(TreeNode* root) {
       //recursive
        /*if(root==NULL){return nums;}
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        nums.push_back(root->val);
        return nums; */
        //iterative
       
        stack<TreeNode*> st;
        stack<int> ss;
        vector<int> v;
        if(root==NULL){return v;}
        st.push(root);
        while(!st.empty()){
            TreeNode* curr=st.top();
            st.pop();
            ss.push(curr->val);
            if(curr->left){
                st.push(curr->left);
            }
            if(curr->right){
                st.push(curr->right);
            }
        }
        while(!ss.empty()){
            v.push_back(ss.top());
            ss.pop();
        }
        return v;
    }
};