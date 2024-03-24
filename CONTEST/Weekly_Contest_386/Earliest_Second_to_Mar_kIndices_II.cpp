/*
* @Author: lenovo
* @Date:   2024-02-25 18:30:33
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-25 18:32:07
*/

class Solution {
public:
    bool isValid(int mid, vector<int>& nums, vector<int>& changeIndices){
        unordered_map<int,int> last;
        for(int i=0; i<mid; i++){
            last[changeIndices[i]]=i;
        }
        if(last.size()!=nums.size()){
            return false;
        }
        int cnt=0;
        for(int i=0; i<mid; i++){
            if(i==last[changeIndices[i]]){
                if(cnt<nums[changeIndices[i]-1]) return false;
                cnt -= nums[changeIndices[i]-1];
            }else{
                cnt++;
            }
        }
        return true;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int m = changeIndices.size();
        int beg = 0, end = m;
        int ans = -1;
        while(beg<=end){
            int mid = (beg+end)/2;
            if(isValid(mid, nums, changeIndices)){
                ans = mid;
                end = mid-1;
            }else{
                beg = mid+1;
            }
        }
        return ans;
    }
};

/*
Intuition
We can use binary search to find the earliest idx which can mark all indices in the given arrays.
In binarySearch fuction, we first find the last occurrence of changeIndices[i] in the array. This is because we need to make nums[changeIndices[i]] zero before this index.
And then, we check whether all the indices are present. If any are missing, it means that it is impossible to mark all the indices.
Next, we use cnt to record the number of times we can do reduce operations. If the current index is the last occurrence of changeIndices[i], then we check if there is a way to make nums[changeIndices[i] - 1] (note the -1, since it is 1-indexed) zero.
If nums[changeIndices[i] - 1] > cnt, it means that it cannot be reduced to zero. In this case, we return False.
Finally, we can use binary search to find the earliest possible index that satisfies the requirements.

If m is the length of changeIndices

Time Complexity = O(m logm)
Space Complexity = O(n)
*/