/*
* @Author: lenovo
* @Date:   2023-10-16 06:08:07
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-16 06:23:24
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                int l = -1;
                int beg = j+1;
                int end = n-1;
                while(beg<=end){
                    int mid = (beg+end)/2;
                    if(nums[mid] < (nums[i]+nums[j])){
                        beg = mid + 1;
                        l = mid;
                    } else{
                        end = mid-1;
                    }
                }
                if(l!=-1){
                    cnt += l-j;
                }
            }
        }
        return cnt;
    }
};

/** 
 * For any 2 given indices we can find the 3rd side in the sorted array using binary search.
 * Time Complexity: O(n^2.log(n))
 * Space Complexity: O(1)
 */