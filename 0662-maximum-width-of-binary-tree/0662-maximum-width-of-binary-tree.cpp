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
    int widthOfBinaryTree(TreeNode* root) {
        //this version in case of too many nodes so to avoid overflow
        if(root==NULL){return 0;}
        int ans=0;
        queue<pair<TreeNode*,int>>qq;
        qq.push({root,0});
        while(!qq.empty()){
            int size=qq.size();
            int first,last;
            int mini=qq.front().second;
            for(int i=0;i<size;i++){
                int currindex=qq.front().second-mini;
                TreeNode* curr=qq.front().first;
                qq.pop();
                if(i==0)first=currindex;
                if(i==size-1)last=currindex;
                if(curr->left!=NULL){qq.push({curr->left,(long long)currindex*2+1});}
                if(curr->right!=NULL){qq.push({curr->right,(long long)currindex*2+2});}
            }
            ans=max(ans,last-first+1);
        }
        return ans;
        
    }
};