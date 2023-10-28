/*
* @Author: lenovo
* @Date:   2023-10-28 19:33:25
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-28 19:41:22
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int su = 0;
        int n = nums.size();
        mp[0] = -1;
        for(int i=0; i<n; i++){
            su += nums[i];
            if(mp.find(su%k)!=mp.end() ){
                if((i-mp[su%k]>=2))
                return true;
            }else{ 
                mp[su%k]=i;
            }
        }
        return false;
    }
};

/**
 * Let us suppose a and b are array running till index i and j respectively;
 * Now for the subarray sum from i+1 to j to be divisible by k,
 * a%k = b%k
 * So that the remainder is reduced to 0.
 * Now. A running sum uptil a given index might also be divisible by k and it will become a valid answer. 
 *
 * To find for each b if there exist a previouslhy available 'a' we use a hash map to store the index with 
 * remainder as running_sum % k
 * And for each b we can refer that hashmap to check if there is a%k available same as b%k
 *
 * But the 2 conditions have to be checked carefully:
 * 1. Sum uptil there might be divisible by k. evaluated by mp[0] = -1
 * 2. length has to be greater than equal to 2. hence the indices must be 2 indices apart.
 *
 * Time Complexity : O(N)
 * Space Complexity: O(N) 
 */