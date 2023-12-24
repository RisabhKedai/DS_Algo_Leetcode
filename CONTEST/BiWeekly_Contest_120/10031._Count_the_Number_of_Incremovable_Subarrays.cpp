/*
* @Author: lenovo
* @Date:   2023-12-23 23:30:43
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-23 23:37:39
*/


class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if(n==1){
            return 1;
        }
        int linc = 0;
        while(linc<n-2 && nums[linc+1]>nums[linc]){
            linc++;
        }
        int rinc = n-1;
        while(rinc>1 && nums[rinc-1]<nums[rinc]){
            rinc--;
        }
        ans += n - rinc;
        ans += linc +1;
        for(int i=0; i<=linc; i++){
            int fnd = -1;
            int beg = max(i+1,rinc);
            int end = n-1;
            while(beg <= end){
                int mid = (beg+end)/2;
                if(nums[mid]>nums[i]){
                    fnd = mid;
                    end = mid-1;
                }else{
                    beg = mid+1;
                }
            }
            // cout<<nums[i]<<" "<<fnd<<endl;
            if(fnd!=-1){
                int numb = n-fnd;
                ans += numb;
                ans -= (fnd-i==1);
            }
        }
        return ans+1;
    }
};


/**
 * Take 3 scenarios: 
 * 1. The subarray removed will be from the beginning of the array
 * 2. The subarray removed will br form the end of the array
 * 3. The subarray will have elements (at least one on either side of the array)
 *
 * For 1. determine the number of elements in the increasing prefix. We have to keep at least one and delete rest.
 * FInd the number of ways to do that. 
 *
 * Repeat the same for 2 but with the suffix array
 *
 * For 3:
 * For each element in the increasing prefix determine the first element strictly greater in the suffix. 
 * Find number of ways to have a proper suffix for a given prefix. 
 * Add all of them up and add 1 for deleting the entire array
 *
 * Time Complexity : O(N) + O(NlogN)
 * Space Complexity : O(1) 
 */
