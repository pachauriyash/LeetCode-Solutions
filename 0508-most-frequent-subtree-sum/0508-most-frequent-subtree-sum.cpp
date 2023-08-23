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
    int recur(TreeNode* root,map<int,int>&mp,int &maxi){
        //base
        if(root==NULL)return 0;
        int leftsum=recur(root->left,mp,maxi);
        int rightsum=recur(root->right,mp,maxi);
        int totsum=leftsum+rightsum+root->val;
        mp[totsum]++;
        maxi=max(maxi,mp[totsum]);
        return totsum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int>mp;
        int maxi=0;
        recur(root,mp,maxi);
        vector<int>vt;
        for(auto it:mp){
            if(it.second==maxi){
                vt.push_back(it.first); 
            }
        
        }
        return vt;
    }
};