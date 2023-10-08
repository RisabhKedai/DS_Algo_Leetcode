/*
* @Author: lenovo
* @Date:   2023-10-08 22:31:35
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-08 22:38:54
*/
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> idx(31,0);
        vector<int> ans(nums.size()+1,0);
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<31; j++){
                if(nums[i]%2 == 1){
                    idx[j] += 1;
                    ans[idx[j]] += 1<<j;
                    
                }
                nums[i] >>= 1;
            }
        }
        long int res = 0;

        for(int i=1; i<=k; i++){
            // cout<<ans[i]<<endl;
            res += (long)ans[i]*ans[i];
            res %= (int) 1e9 + 7;
        }
        return res;
    }
};

/**
 * Maybe difficult to observe but we just rearrange ones in each number
 * Example:-
 * 2 = 0 0 1 0
 * 6 = 0 1 1 0
 * 5 = 0 1 0 1
 * 8 = 1 0 0 0
 *
 * Suppose all ones fall down:
 *
 * 0 0 0 0 = 0 
 * 0 0 0 0 = 0
 * 0 1 1 0 = 6
 * 1 1 1 1 = 15
 *
 * This works because when we do the And or replacement,
 * we are just shifting the ones to the Or from the And number. 
 *
 * We take the lower K layers and form numbers from them and calculate the squares sum. 
 * This can be done efficiently using the above code.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */