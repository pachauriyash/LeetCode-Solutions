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
    void levelorder(TreeNode* root,vector<double>&v){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
        long sum=0;
        int count=0;
    while (!q.empty())
    {   
        TreeNode* temp=q.front();
        
        q.pop();
        if(temp==NULL){//purana level complete traverse hochuka hai
            //cout<<endl;
            double avg=sum/double(count);
            v.push_back(avg);
            sum=0;count=0;
            if(!q.empty()){//queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            //cout<<temp->data <<" ";
            sum+=temp->val;
            count++;
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}
        }
       
    }  
}
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>v;
        levelorder(root,v);
        return v;
    }
};