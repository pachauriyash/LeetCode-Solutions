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
    int findpos(vector<int>ino,int element){
        for(int i=0;i<ino.size();i++){
            if(ino[i]==element){return i;}
        }
        return -1;
    }
    TreeNode* solve(vector<int> pre,vector<int>ino,int &index,int inorderstart,int inorderend){
        if(index>=ino.size() || inorderstart>inorderend){
            return NULL;
        }
        int element=pre[index++];
        TreeNode* temp=new TreeNode(element);
        int position=findpos(ino,element);
        
        //recursion
        temp->left=solve(pre,ino,index,inorderstart,position-1);
        temp->right=solve(pre,ino,index,position+1,inorderend);
        return temp;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex=0;
        TreeNode* ans=solve(preorder,inorder,preindex,0,inorder.size()-1);
        return ans;
    }
};