/*
* @Author: lenovo
* @Date:   2024-02-11 15:08:42
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-11 15:14:13
*/


class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long su=0;
        int ma=-1;
        for(auto x : nums){
            su += x;
            ma = max(ma,x);
        }
        int ans = -1;
        int beg=ma,end=su;
        while(beg<=end){
            int mid = (beg+end)/2;
            int subs = countSubs(nums,mid);
            cout<<mid<<" "<<subs<<endl;
            if(subs<=k){
                end = mid-1;
                ans = mid;
            }else{
                beg = mid+1;
            }
        }
        return ans;
    }
    int countSubs(vector<int> nums, long target) {
        int count = 1;
        long total = 0;
        for(int num : nums) {
            total += num;
            if (total > target) {
                total = num;
                count++;
            }
        }
        return count;
    }
};

/**
 * For all the possibilities between maximum to sum(array).
 * Find the minimum one with the number of slots less than equal to k. 
 * That is the answer.
 *
 * Time complexity : O(N*log(sum(array)))
 * Space complexity : O(1)
 */