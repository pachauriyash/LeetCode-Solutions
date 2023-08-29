class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        if(n==0)return true;
        if(flowerbed.size()==1){
            if(flowerbed[0]==0 && n==1)return true;
            else return false;
        }
        for(int i=0;i<flowerbed.size();i++){
            if(i==0 && flowerbed[i]==0 && flowerbed[i+1]==0){flowerbed[i]=1;count++;}
            else if(i==flowerbed.size()-1 && flowerbed[i]==0 && flowerbed[i-1]==0){flowerbed[i]=1;count++;}
            else if(i!=0 && i!=flowerbed.size()-1 && flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
                flowerbed[i]=1;count++;
            }
        }
        return count>=n;
    }
};