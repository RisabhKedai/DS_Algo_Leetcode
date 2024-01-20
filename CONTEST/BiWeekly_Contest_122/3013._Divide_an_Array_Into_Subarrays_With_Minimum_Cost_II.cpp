/*
* @Author: lenovo
* @Date:   2024-01-21 00:36:58
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-21 00:39:29
*/

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long ans = INT_MAX;
        k--;
        multiset<int> taken, rem;
        long long curr = nums[0];
        for(int i=1; i<=dist+1; i++){
            taken.insert(nums[i]);
            curr += nums[i];
        }
        while(taken.size() > k){
            curr -= *taken.rbegin();
            rem.insert(*taken.rbegin());
            taken.erase(taken.find(*taken.rbegin()));
        }
        ans = curr;
        for(int i=dist+2; i<n; i++){
            // deleting an element from the front
            if(taken.find(nums[i-dist-1])!=taken.end()){
                curr -= nums[i-dist-1];
                taken.erase(taken.find(nums[i-dist-1]));
                // cout<<" erase "<<nums[i-dist-1]<<"\n";
            }else{
                rem.erase(rem.find(nums[i-dist-1]));            
            }

            // inserting the new element into remains first
            rem.insert(nums[i]);

            // balancing the elements incase taken has less
            int del = *rem.begin();
            taken.insert(*rem.begin());
            curr += *rem.begin();
            rem.erase(rem.find(del));

            while(taken.size()>k){
                curr -= *taken.rbegin();
                rem.insert(*taken.rbegin());
                taken.erase(taken.find(*taken.rbegin()));
            }
            ans = min(ans, curr);
        } 
        return ans;
    }
};

/**
 * Intuition
 * =========
 * The problem can be simplified into finding the minimum of the sum of the smallest (k−1)th
 * elements in a continuous subarray of length dist+1.
 * 
 * Approach
 * ========
 * We can use two sets, one storing first (k−1)th smallest element, 
 * while the second set storing the rest. 
 * When itterating through the array, we can remove an element and insert an element 
 * into one of these sets in O(log n) time. 
 * Then we can use another variable to store the sum of the first set, 
 * updating it each time an element is inserted or erased.
 * 
 * Time complexity: O(NlogN)
 * Space complexity : O(N)
 */