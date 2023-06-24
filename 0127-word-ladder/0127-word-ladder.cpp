class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({startWord,1});
        st.erase(startWord);
        while(!q.empty()){
            string word=q.front().first;
            int level=q.front().second;
            q.pop();
            if(word==targetWord){return level;}
            for(int i=0;i<word.length();i++){
                string temp=word;
                int index=0;
                while(index<26){
                    temp[i]='a'+index;
                    if(st.find(temp)!=st.end()){
                        q.push({temp,level+1});
                        st.erase(temp);
                    }
                    index++;
                }
            }
            
        }
        return 0;
    }
};