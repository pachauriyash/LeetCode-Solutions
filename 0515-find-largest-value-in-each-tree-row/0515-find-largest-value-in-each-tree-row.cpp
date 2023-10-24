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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>v;
        q.push(root);
        q.push(NULL);
        if(root==NULL){return v;}
        int max=root->val;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            
            if(temp==NULL){
                v.push_back(max);
                
                if(!q.empty()){
                   q.push(NULL);
                    max=q.front()->val;
                }
            }
            else{
                if(temp->val>max){max=temp->val;}
                if(temp->left){q.push(temp->left);}
                if(temp->right){q.push(temp->right);}
            }
        }
        return v;
    }
};