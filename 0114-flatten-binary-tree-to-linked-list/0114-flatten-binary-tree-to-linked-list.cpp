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
    void flatten(TreeNode* root,TreeNode* &prev){
        if(root==NULL)return;
        flatten(root->right,prev);
        flatten(root->left,prev);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
    void flatten(TreeNode* root) {
        //recursive  TC O(N) SC O(N)
        // TreeNode* prev=NULL;
        // flatten(root,prev);
        //iterative TC O(N) SC O(N)
//         stack<TreeNode*> st;
//         if(root==NULL)return;
//         st.push(root);
//         while(!st.empty()){
//             TreeNode* curr=st.top();
//             st.pop();
//             if(curr->right)st.push(curr->right);
//             if(curr->left)st.push(curr->left);
//             if(!st.empty()){
//                 curr->right=st.top();
//                 curr->left=NULL;
//             }
            
//         }
        //morris order method to thread  TC O(N) SC O(1)
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left){
                TreeNode* prev=curr->left;
                while(prev->right)prev=prev->right;
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};