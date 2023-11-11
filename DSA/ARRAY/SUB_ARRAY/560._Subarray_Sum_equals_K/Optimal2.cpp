/*
* @Author: lenovo
* @Date:   2023-10-27 23:41:09
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-28 00:09:27
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int rs = 0;
        mp[0] = 1;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            rs += nums[i];
            int req = rs-k;
            cnt += mp[req];
            mp[rs] += 1;
        }
        return cnt;
    }
};


/**
 * Store the running sum in a map. 
 * Each time we get a new sum, subtract k from it to get the remaining number. 
 * Use this to find the count of the required prefix sum. 
 * return that count.
 *
 * Time Complexity : O(n)
 * Space Complexity: O(n)
 */