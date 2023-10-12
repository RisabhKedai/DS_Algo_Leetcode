/*
* @Author: lenovo
* @Date:   2023-10-12 06:34:11
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-12 06:36:46
*/
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size()<3){
            return 0;
        }
        int N = arr.size();
        int base = 0;
        int ans = 0;
        while(base < arr.size()){
            int end = base;
            if(end<N-1 && arr[end+1]>arr[end]){
                while(end<N-1 && arr[end+1]>arr[end]){
                    end++;
                }
                if(end<N-1 && arr[end+1]<arr[end]){
                    while(end<N-1 && arr[end+1]<arr[end]){
                        end++;
                    }   
                    ans = max(ans,end-base+1);
                }
            }
            base = max(base+1,end);
        }
        return ans;
    }
};

/**
 * We take 2 pointers, 
 * base to mark the starting of the mountain and 
 * end to mark the current point in the mountain starting from base,
 * Then at every point it is checked whther it is up slope or downslope 
 * And upslope has to come before downslope. 
 * Finally once the end is reached we find the total number of points
 */