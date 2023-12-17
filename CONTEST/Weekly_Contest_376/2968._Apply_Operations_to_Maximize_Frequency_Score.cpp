/*
* @Author: lenovo
* @Date:   2023-12-17 13:58:23
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-17 14:00:22
*/
class Solution {
public:
    long long operations(int index, int L, int R, vector<int>& nums, vector<long long>& prefix) {
        return (((index-L+1)*1LL*nums[index]) - (prefix[index]-(L!=0?prefix[L-1]:0))) + ((prefix[R]-prefix[index]) - ((R-index)*1LL*nums[index])); 
    }
    bool possible(vector<long long>& prefix, vector<int>& nums, int length, long long k) {
        for(int i=0; i+length<=nums.size(); i++){
            int L = i;
            int R = i+length-1;
            if(operations(L+(length/2), L, R, nums, prefix) <= k){
                return true;
            }
            if(length%2==0 && operations(L+(length/2)-1,L,R,nums,prefix)<=k){
                return true;
            }
        }
        return false;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        int ans = 0;
        int l=1, r=n;
        while(l<=r){
            int mid = (l+r)/2;
            if(possible(prefix, nums, mid, k)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return ans;
    }
};

/**
 * Reference : https://leetcode.com/problems/apply-operations-to-maximize-frequency-score/solutions/4415420/easy-implementation-binary-search-sliding-window-prefix-sum/ 
 *
 * Reason behind sorting to bring the closest elements together so that the operations spent is minimum.
 * 
 * Assume the answer is x.
 * Firstly we sort the array now take window of x and try to make elements in that window equal.
 * We can make each element in that window to the median because median will take the minimum operations.
 * Hence we need to maximize the value of x.
 * For that I have done the Binary Search on window and search for each window in the given array.
 * That can be done using some manipulation.
 * Suppose elements are {a1, a2, a3, a4, a5}
 * mid element = a3 and we try to make every element in this window to a3
 * so, left part from position 3 have total operations will be =>
 * (a3 - a3) + (a3 - a2) + (a3 - a1).
 * so, right part from position 3 have total operations will be =>
 * (a5 - a3) + (a4 - a3).
 * Total number of operations = left + right.
 * 
 * Time complexity: O(nlogn)
 * Space complexity: O(n)
 */