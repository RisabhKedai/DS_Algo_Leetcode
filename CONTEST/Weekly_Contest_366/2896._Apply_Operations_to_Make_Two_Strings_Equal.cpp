/*
* @Author: lenovo
* @Date:   2023-10-08 17:41:04
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-08 22:40:36
*/

class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        vector<int> diff;
        int n = s1.size();
        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]){
                diff.push_back(i);
            }
        }
        if(diff.size()%2!=0){
            return -1;
        }
        if(diff.size()==0){
            return 0;
        };
        vector<double> dp(diff.size()+1);
        dp[0] = 0;
        dp[1] = (double)x/2;
        for(int i=2; i<dp.size(); i++){
            dp[i] = dp[i-1] + (double)x/2;
            dp[i] = min(dp[i],dp[i-2] + diff[i-1] - diff[i-2] );
        }
        return dp[dp.size()-1];
    }
};

/**
 * Impossible if there are odd number of inequalities
 * If we want to solve 2 inequalities by method 2 that is using adjacent characters,
 * then must solve 2 adjacent ones only for minimum cost. 
 * Example: if 3 and 5 bit are different then we, flip 3 and 4 for cost 1 and 4 and 5 for total cost 2.
 * Thus by this method cost is diff[i] - diff[j]
 * Otherwise we can directly flip both of them using x. In that case to solve 1 the cost is x/2
 *
 * Using this approach for every i find the cost of using adjacent solve + cost of remaining diffs
 * Or delete the current diff using x/2 and find solution for rest diffs
 *
 * If we have only the 0th diff left then cost is x/2.
 * So dp[first diff] = x/2
 * dp[no diff] = 0
 *
 * Time Complexity: O(m)
 * Space Complexity: O(m)
 *
 * m = number of mismatching bit positions
 */