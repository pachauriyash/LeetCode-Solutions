/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len=mountainArr.length();
        int low=0;
        int high=len-1;
        int index=-1;
        while(low<high){
            int mid=(high+low)/2;
            //cout<<mid<<" ";
            int ele=mountainArr.get(mid);
            int ele2=mountainArr.get(mid+1);
            if(ele<ele2){
                index=mid+1;
                low=mid+1;
            }else{
                high=mid;
            }
        }
        cout<<endl<<index;
        if(index==-1)return -1;
        low=0;
        high=index;
        while(low<=high){
            int mid=(low+high)/2;
            int ele=mountainArr.get(mid);
            if(ele==target){return mid;}
            if(ele<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        low=index;
        high=len-1;
        while(low<=high){
            int mid=(low+high)/2;
            int ele=mountainArr.get(mid);
            if(ele==target){return mid;}
            if(ele<target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return -1;
    }
};