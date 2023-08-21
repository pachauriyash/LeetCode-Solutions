class Solution {
public:
    string month(string mm){
        if(mm=="Jan"){
            return "01";

        }
        else if(mm=="Feb"){
            return "02";

        }
        else if(mm=="Mar"){
            return "03";

        }
        else if(mm=="Apr"){
            return "04";

        }
        else if(mm=="May"){
            return "05";

        }
        else if(mm=="Jun"){
            return "06";

        }
        else if(mm=="Jul"){
            return "07";

        }
        else if(mm=="Aug"){
            return "08";

        }
        else if(mm=="Sep"){
            return "09";

        }
        else if(mm=="Oct"){
            return "10";
       
        }
        else if(mm=="Nov"){
            return "11";

        }
        else if(mm=="Dec"){
            return "12";
   
        }
        
        return "0";
    }
    string reformatDate(string date) {
        string ans="";
        ans+=date.substr(date.size()-4,4)+"-";
        ans+=month(date.substr(date.size()-8,3))+"-";
        int index=0;
        while(date[index]!=' '){index++;}
        if(index==4){
            ans+=date.substr(0,2);
        }
        else{
            ans+="0"+date.substr(0,1);
        }
        return ans;
    }
};