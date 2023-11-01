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
    void traverse(TreeNode* root,map<int,int>&mp){
        if(root==NULL)return;
        mp[root->val]++;
        traverse(root->left,mp);
        traverse(root->right,mp);
    }
    bool static comp(pair<int,int>&a,pair<int,int>&b){
        return a.second>b.second;
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int>mp;
        traverse(root,mp);
        vector<pair<int,int>>ans;
        for(auto it:mp){
            ans.push_back({it.first,it.second});
        }
        sort(ans.begin(),ans.end(),comp);
        vector<int>aans;
        aans.push_back(ans[0].first);
        for(int i=1;i<ans.size();i++){
            if(ans[i].second==ans[0].second){
                aans.push_back(ans[i].first);
            }
            else break;
        }
        return aans;
    }
};