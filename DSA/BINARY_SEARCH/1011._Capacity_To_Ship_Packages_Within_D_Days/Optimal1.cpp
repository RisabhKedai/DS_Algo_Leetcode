/*
* @Author: lenovo
* @Date:   2024-02-08 01:00:54
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-08 01:01:59
*/

class Solution {
public:
    int checkDays(vector<int>& weights, int capacity){
        int temp = 0;
        int cnt = 0;
        for(int i=0; i<weights.size(); i++){
            temp += weights[i];
            if(temp > capacity){
                temp = weights[i];
                cnt +=1;
            }
        }
        return cnt+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int beg = *max_element(weights.begin(),weights.end());
        int end = accumulate(weights.begin(),weights.end(),0);
        int ans = end;
        while(beg<=end){
            int mid = (beg+end)/2;
            int dreq = checkDays(weights,mid);
            if(dreq <= days){
                ans = mid;
                end = mid-1;
            }else{
                beg = mid+1;
            }
        }
        return ans;
    }
};

/**
 * Use binary search to find the appropriate number of days 
 * The search space is maximum(weights) to sum(weights)
 *
 * Time complexity : O(NlogN)
 * Space complexity: O(1)
 */