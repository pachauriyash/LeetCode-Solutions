class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        if (s.length()<k){
            return false;
        }
        for(int i=0;i<=s.length()-k;i++){
            cout<<i;
            st.insert(s.substr(i,k));
        }
        int temp=pow(2,k);
        if(st.size()==temp)return true;
        return false;
        
    }
};