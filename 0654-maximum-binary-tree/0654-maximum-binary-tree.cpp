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
    int maxindex(vector<int> nums){
        int maxnum=nums[0];
        int maxi=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>maxnum){maxnum=nums[i];maxi=i;}
        }
        return maxi;
    }
    vector<int> slicing(vector<int> nums,int x, int y)
    {   vector<int> temp;
        for(int i=x;i<=y;i++)
            temp.push_back(nums[i]);
        return temp;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        
        int i=maxindex(nums);
        int data=nums[i];
        TreeNode* root=new TreeNode();
        root->val=data;
        vector<int> templeft,tempright;
        
        templeft=slicing(nums,0,i-1);
        root->left= constructMaximumBinaryTree(templeft);
        tempright=slicing(nums,i+1,nums.size()-1);
        root->right=constructMaximumBinaryTree(tempright);
        
        return root;
    }
};