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
class BSTIterator {
public:
    stack<TreeNode*>st;
    bool reverse=true;
    //reverse->true->before
    //reverse->false->next
    BSTIterator(TreeNode* root,bool isreverse) {
        reverse=isreverse;
        pushall(root);
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        if(!reverse)pushall(temp->right);
        else{pushall(temp->left);}
        return temp->val;
       
    }
    //returns whether we have a next smallest or largest number
    bool hasNext() {
       return !st.empty();
    }
    void pushall(TreeNode* node){
        while(node){
            st.push(node);
            if(reverse){
                node=node->right;
            }else{
                node=node->left;   
            }
        }
    }
};
class Solution {
public:
    void traverse(TreeNode* root,vector<int>&vt){
        if(root==NULL)return;
        traverse(root->left,vt);
        vt.push_back(root->val);
        traverse(root->right,vt);
    }
    bool findTarget(TreeNode* root, int k) {
        //bruteforce solution
        vector<int>vt;
        traverse(root,vt);
        int i=0;
        int j=vt.size()-1;
        while(i<j){
            if(vt[i]+vt[j]==k)return true;
            else if(vt[i]+vt[j]<k)i++;
            else{j--;}
        }
        return false;
        // if(!root)return false;
        // BSTIterator leftt(root,false);
        // BSTIterator rightt(root,true);
        // int i=leftt.next();
        // int j=rightt.next();
        // while(i<j){
        //     if(i+j==k)return true;
        //     else if(i+j<k){i=leftt.next();}
        //     else{j=rightt.next();}
        // }
        // return false;
        
    }
};