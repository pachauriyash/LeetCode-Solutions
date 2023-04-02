class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int size=s.size();
        char arr[size];
        for(int i=0;i<size;i++){
            arr[indices[i]]=s[i];
        }
        string temp="";
        for(int i=0;i<size;i++){
            temp+=arr[i];
        }
        return temp;
    }
};