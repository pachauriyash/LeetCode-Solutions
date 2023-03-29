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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> ds;
        queue<pair<TreeNode*,pair<int,int>>> qq;
        qq.push({root,{0,0}});
        while(!qq.empty()){
            auto temp=qq.front();
            qq.pop();
            TreeNode* curr=temp.first;
            int vertical=temp.second.first, level=temp.second.second;
            ds[vertical][level].insert(curr->val);
            if(curr->left){
                qq.push({curr->left,{vertical-1,level+1}});
            }
            if(curr->right){
                qq.push({curr->right,{vertical+1,level+1}});
            }
        }
        vector<vector<int>> ans;
        for( auto p : ds){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};