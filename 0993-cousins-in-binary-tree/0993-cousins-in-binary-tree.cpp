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
   
    int traverse(TreeNode* root,int x,int height,int &parent){
        if(root==NULL){return 0;}
        
        if(root->val==x){return height;}
        parent=root->val;
        int left=traverse(root->left,x,height+1,parent);
        if(left){return left;}
        parent=root->val;
        int right=traverse(root->right,x,height+1,parent);
        return right;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        
       
        int xparent=-1,yparent=-1;
        int xheight=traverse(root,x,0,xparent);
         int yheight=traverse(root,y,0,yparent);
        if(xparent!=yparent && xheight==yheight){return true;}
        else{return false;}
    }
};