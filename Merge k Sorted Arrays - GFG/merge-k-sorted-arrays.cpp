//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class node{
    public:
        int data;
        int i;
        int j;
    node(int data, int row,int col){
        this->data=data;
        i=row;
        j=col;
    }
        
};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data> b->data;
    }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<node*,vector<node*>,compare> minheap;
        //step1: sare arrays ke first element insert krne hai
        for(int i=0;i<K;i++){
            node* temp= new node(arr[i][0],i,0);
            minheap.push(temp);
        }
        vector<int> ans;
        //step2
        while(minheap.size()>0){
            node* tmp= minheap.top();
            ans.push_back(tmp->data);
            minheap.pop();
            
            int i=tmp->i;
            int j=tmp->j;
            
            if(j+1<arr[i].size()){
                node* next= new node(arr[i][j+1],i,j+1);
                minheap.push(next);
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends