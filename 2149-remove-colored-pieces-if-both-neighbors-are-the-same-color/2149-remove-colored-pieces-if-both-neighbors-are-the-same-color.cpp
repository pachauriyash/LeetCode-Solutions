class Solution {
public:
    bool winnerOfGame(string colors) {
        int count1=0,count2=0;
        for(int i=1;i<colors.size()-1;i++){
            if(colors[i-1]==colors[i] && colors[i]==colors[i+1]){
                if(colors[i]=='A')count1++;
                if(colors[i]=='B')count2++;
            }
        }
        return count1>count2;
    }
};