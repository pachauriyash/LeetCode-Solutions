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
    int maxDepth(TreeNode* root) {
        int leftheight;
        int rightheight;
        if(root==NULL){return 0;}
        leftheight=maxDepth(root->left);
        rightheight=maxDepth(root->right);
        if(leftheight>rightheight){return leftheight+1;}
        else{return rightheight+1;}
    }
    void levelorder(TreeNode* root,int depth,int &ans){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
        int t=1;
    while (!q.empty())
    {   
        TreeNode* temp=q.front();
        
        q.pop();
        if(temp==NULL){//purana level complete traverse hochuka hai
            //cout<<endl;
            t++;
            if(!q.empty()){//queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            //cout<<temp->data <<" ";
            if(t==depth){ans=temp->val; return;}
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}
        }
       
    }  
}
    int findBottomLeftValue(TreeNode* root) {
        int depth=maxDepth(root);
        int ans=0;
        levelorder(root,depth,ans);
        return ans;
    }
};