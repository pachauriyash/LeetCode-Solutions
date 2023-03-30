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
    TreeNode* traverse(vector<int>& nums,int start,int end){
        if(start<=end){
            int mid=(end+start)/2;
            TreeNode* temp=new TreeNode(nums[mid]);
            temp->left=traverse(nums,start,mid-1);
            temp->right=traverse(nums,mid+1,end);
            return temp;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==1){TreeNode* temp=new TreeNode(nums[0]); return temp;}
        return traverse(nums,0,nums.size()-1);
    }
};