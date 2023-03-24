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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> an;
        queue<TreeNode*>nums;
        
        nums.push(root);
        int len;
        while(!nums.empty()){
            len=nums.size();
            vector<int>ans;
            for(int i=0;i<len;i++){
                TreeNode* temp=nums.front();
                nums.pop();
                ans.push_back(temp->val);
                if(temp->left!=NULL){nums.push(temp->left);}
                if(temp->right!=NULL){nums.push(temp->right);}
            }
            an.push_back(ans);
        }
        return an;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v,v1;
        v=levelOrder(root);
        for(int i=v.size()-1;i>=0;i--){
            v1.push_back(v[i]);
        }
        return v1;
    }
};