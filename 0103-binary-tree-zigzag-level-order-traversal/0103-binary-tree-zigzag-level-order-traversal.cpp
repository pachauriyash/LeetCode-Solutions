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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> an;
        queue<TreeNode*>nums;
        
        nums.push(root);
        int len;
        int level=0;
        while(!nums.empty()){
            len=nums.size();
            vector<int>ans;
            for(int i=0;i<len;i++){
                TreeNode* temp=nums.front();
                nums.pop();
                if(level%2)ans.insert(ans.begin(),temp->val);
                else{ans.push_back(temp->val);}
                if(temp->left!=NULL){nums.push(temp->left);}
                if(temp->right!=NULL){nums.push(temp->right);}
            }
            an.push_back(ans);
            level++;
        }
        // for(int i=0;i<an.size();i++){
        //     if(i%2)reverse(an[i].begin(),an[i].end());
        // }
        return an;
    }
};