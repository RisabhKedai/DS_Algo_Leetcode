/*
* @Author: lenovo
* @Date:   2023-10-16 06:23:39
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-16 07:13:14
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n-2; i++){
            int k = i+2;
            for(int j=i+1; j<n-1; j++){
                k = max(j+1,k);
                while(k<n && (nums[i]+nums[j] > nums[k])){
                    k++;
                }
                cnt += (k-j) -1;
            }
        }
        return cnt;
    }
};

/**
 * We can find this right limit by simply traversing the index k's values starting from the index k=j+1 for a pair (i,j)\
 * chosen and stopping at the first value of k not satisfying the above inequality. 
 * Again, the count of elements nums[k] satisfying nums[i]+nums[j]>nums[k]
 * for the pair of indices (i,j) chosen is given by k−j−1 as discussed in the last approach.
 * Note that after increasing the value of j we can start from k where we left it.
 * If k was not updated then in that case we have to make k = j+1;
 */