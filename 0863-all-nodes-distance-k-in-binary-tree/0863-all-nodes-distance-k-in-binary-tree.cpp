/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void traverseallnodes(TreeNode* root,int k,vector<int>&ans){
        if(root==NULL)return;
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        traverseallnodes(root->left,k-1,ans);
        traverseallnodes(root->right,k-1,ans);
    }
    int traverse(TreeNode* root, TreeNode* target, int k,vector<int>&ans){
        if(root==NULL)return 0;
        if(root==target){
            traverseallnodes(root,k,ans);
            return 1;
        }
        int leftdistance=traverse(root->left,target,k,ans);

        if(leftdistance!=0){
            //means we found the target and at first it will enter start giving values for node just above target

            if(leftdistance==k){
                //that means it's just the root node which is there so no need to check or right
                ans.push_back(root->val);
            }else if(leftdistance<k){
                //which means there is possibility of finding on right
                traverseallnodes(root->right,k-leftdistance-1,ans);
            }
            return 1+leftdistance;
        }
        int rightdistance=traverse(root->right,target,k,ans);
        
        if(rightdistance!=0){
            if(rightdistance==k){
                //that means it's just the root node which is there so no need to check or right
                ans.push_back(root->val);
            }else if(rightdistance<k){
                //which means there is possibility of finding on right
                traverseallnodes(root->left,k-rightdistance-1,ans);
            }
            return 1+rightdistance;
        }
        
        return 0;//means no target here
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        traverse(root,target,k,ans);
        return ans;
    }
};