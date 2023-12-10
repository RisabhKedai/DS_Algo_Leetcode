/*
* @Author: lenovo
* @Date:   2023-12-04 01:39:31
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-04 01:48:14
*/
class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        int reachable = 0;
        int ans = 0;
        for(auto coin : coins){
            while(coin > reachable+1){
                ans+=1;
                reachable += reachable +1;
                
                if(reachable >= target){
                    return ans;
                }
            }
            
            reachable += coin;
            
            if(reachable>=target){
                return ans;
            }
        }
        while(reachable<target){
           reachable += reachable+1;
           ans += 1;
        }
        return ans;
    }
};

/**
 * Time complexity: O(N)
 * Space complexity : O(1)
 */