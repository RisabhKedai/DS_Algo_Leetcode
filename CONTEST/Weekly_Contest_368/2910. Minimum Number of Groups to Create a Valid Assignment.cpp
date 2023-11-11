/*
* @Author: lenovo
* @Date:   2023-10-22 14:04:43
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-22 14:07:53
*/
class Solution {
public:
    int check(int siz,vector<int>& freq){
        int ans = 0;
        for(auto x: freq){
            if(x/siz < x%siz){
                return INT_MAX;
            }
            ans += ceil((double)x/(siz+1));
        }
        return ans;
    }
    int minGroupsForValidAssignment(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<int> freq;
        for(auto x: mp){
            freq.push_back(x.second);
        }
        sort(freq.begin(),freq.end());
        int ctr = 0;
        int mino = freq[0];
        int ans = INT_MAX;
        for(int i=mino; i>=1; i--){
            ans = min(ans, check(i,freq));
        }
        return ans;
    }
};
/**
 * Scan from 1 to min(c.values()) and search among each number in the Counter
 * The search function checks if there is a viable split for either index or index + 1 group size,
 * since the maxsize - minsize needs to be less than or equal to 1. 
 * 
 * This means if we're checking for a split size of 3, 3 or 4 are both accepted as a viable solution.
 * We check this by testing the viability of each number in our Counter.values(), meaning the frequency of each number in the input array.
 *  If the current (frequency % split_size) > (frequency // split_size), 
 *  it means there is no way to form a viable split since there is guaranteed to be a remained, and that remainder can not be eliminated by adding 1 to each group 
 *  (for example, if our split size is 7 and our frequency is 17, there's no way to evenly split 17 into groups of either 7 or 8 without a remainder).
 * You could also reverse the range and loop backwards, immediately returning the answer if you find a viable split. The worst case of each solution is still the same though, 
 * and I think this method provides a bit more clarity
 * .
 * Time Complexity : O(Min_element * N)
 * Space Complexity : O(N) 
 */
