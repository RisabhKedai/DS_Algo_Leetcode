/*
* @Author: lenovo
* @Date:   2024-02-08 22:21:06
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-08 22:22:14
*/


class Solution {
public:
    long long check(int mid, vector<int> piles){
        long long d = 0;
        for(auto x: piles){
            d += (x-1)/mid;
            d += 1;
        }
        return d;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = -1;
        int beg = 1, end = *max_element(piles.begin(), piles.end());
        while(beg<=end){
            int mid = (beg+end)/2;
            if(check(mid,piles)<=h){
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
 * Use binary search to find the appropriate eat size
 * The search space is 1 to max_element size
 *
 * Time complexity : O(NlogN)
 * Space complexity: O(1)
 */