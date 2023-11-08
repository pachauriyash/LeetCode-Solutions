class Solution {
public:
    long long recur(int indexx,int indexy,int sx,int sy,int fx,int fy){
        if(indexx>fx || indexy>fy){return 1e5;}
        if(indexx==fx && indexy==fy)return 0;
        
        return 1+min(recur(indexx+1,indexy,sx,sy,fx,fy),min(recur(indexx+1,indexy+1,sx,sy,fx,fy),recur(indexx,indexy+1,sx,sy,fx,fy)));
    }
    long long recur2(int indexx,int indexy,int sx,int sy,int fx,int fy){
        if(indexx<fx  || indexy<fy){return 1e5;}
        if(indexx==fx && indexy==fy)return 0;
        
        return 1+min(recur2(indexx-1,indexy,sx,sy,fx,fy),min(recur2(indexx-1,indexy-1,sx,sy,fx,fy),recur2(indexx,indexy-1,sx,sy,fx,fy)));
    }
    long long recur3(int indexx,int indexy,int sx,int sy,int fx,int fy){
        if(indexx<fx || indexy>fy){return 1e5;}
        if(indexx==fx && indexy==fy)return 0;
        
        return 1+min(recur3(indexx-1,indexy,sx,sy,fx,fy),min(recur3(indexx-1,indexy+1,sx,sy,fx,fy),recur3(indexx,indexy+1,sx,sy,fx,fy)));
    }
    long long recur4(int indexx,int indexy,int sx,int sy,int fx,int fy){
        if(indexx>fx ||indexy<fy){return 1e5;}
        if(indexx==fx && indexy==fy)return 0;
        
        return 1+min(recur4(indexx+1,indexy,sx,sy,fx,fy),min(recur4(indexx+1,indexy-1,sx,sy,fx,fy),recur4(indexx,indexy-1,sx,sy,fx,fy)));
    }
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
//         int time=INT_MAX;
//         if(sx==fx && sy==fy){
//             if(t==1)return false;
//             else return true;
//         }
//         if(sx<=fx && sy<=fy){
//             time=recur(sx,sy,sx,sy,fx,fy);
//             //cout<<time;
//         }
//         else if(sx>fx && sy<=fy){
//            time= recur3(sx,sy,sx,sy,fx,fy);
//         }
//         else if(fx<=sx && fy<=sy){
            
//             time=recur2(sx,sy,sx,sy,fx,fy);
//             //cout<<time;
//         }
//         else{
//             time=recur4(sx,sy,sx,sy,fx,fy);
//         }
//         if(time<=t)return true;
//         return false;
        if(sx==fx && sy==fy) {
            if(t==1) return false;
            else return true;
        }
        int x = abs(fx-sx);
        int y = abs(fy-sy);
        
        int time = max(x,y);
        
        if(time<=t) return true;
        return false;
        
    }
};