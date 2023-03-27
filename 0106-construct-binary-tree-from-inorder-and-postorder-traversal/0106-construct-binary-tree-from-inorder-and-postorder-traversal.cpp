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
    void createmap(vector<int>ino,map<int,int>&nodetoindex){
        for(int i=0;i<ino.size();i++){
            nodetoindex[ino[i]]=i;
        }
    }
    TreeNode* solve(vector<int> post,vector<int>ino,int &index,int inorderstart,int inorderend,map<int,int>&nodetoindex){
        if(index<0 || inorderstart>inorderend){
            return NULL;
        }
        int element=post[index--];
        TreeNode* temp=new TreeNode(element);
        int position=nodetoindex[element];
        
        //recursion
        temp->right=solve(post,ino,index,position+1,inorderend,nodetoindex);
        temp->left=solve(post,ino,index,inorderstart,position-1,nodetoindex);
        
        return temp;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         int postindex=postorder.size()-1;
        map<int,int> nodetoindex;
        createmap(inorder,nodetoindex);
        TreeNode* ans=solve(postorder,inorder,postindex,0,inorder.size()-1,nodetoindex);
        return ans;
    }
};