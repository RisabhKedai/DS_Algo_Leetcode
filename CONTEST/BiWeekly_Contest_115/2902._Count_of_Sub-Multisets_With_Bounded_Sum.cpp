/*
* @Author: lenovo
* @Date:   2023-10-15 19:26:54
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-15 19:40:53
*/
class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        map<int,int> mp;
        int mod = 1e9 + 7;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                mp[nums[i]]++;
            }else{
                cnt++;
            }
        }
        vector<pair<int,int>> mv;
        for(auto x: mp){
            mv.push_back(x);
        }
        int m = mp.size();
        vector<vector<long long>> dp(m+1,vector<long long>(r+1,1));
        for(auto k=m-1; k>=0; k--){
            int freq = mv[k].second;
            int x = mv[k].first;
            for(int j=0; j<=r; j++){
                dp[k][j] = dp[k+1][j];
                if(j>=x){
                    dp[k][j] = (dp[k][j] + dp[k][j-x])%mod;
                    if(j>=((freq+1)*x)){
                        dp[k][j] = (dp[k][j] - dp[k+1][j - ((freq+1)*x)] + mod);
                    }
                }
                dp[k][j] %= mod;
            }
        }
        return ((dp[0][r]-(l<=0?0:dp[0][l-1])+mod)*(1+cnt))%mod;
    }
};

/**
 * Reference : https://leetcode.com/problems/count-of-sub-multisets-with-bounded-sum/solutions/4169304/easy-dp-3d-2d-and-explaining-why-we-use-sliding-window/
 * Intuition
 * Clearly, there can only be root(r) distinct numbers.
 * The way to see this is to notice the smallest possible sum of n distinct numbers is
 * 1+2+3+…+m=m(m+1)2 <= r 
 * therefore if m(m+1)2⩽r
 * then m⩽root(r)
 * With this in mind, let's represent the array as distinct numbers coupled with their frequencies.
 * Anyway, a naive DP idea is
 * dp[i][L][R] represents the number of multisums between L and R considering only [i:] onwards. 
 * (from index i to the end)
 * 
 * 
 * The transitions for this are:
 * dp[i][L][R]=∑(h=0 to freq[ai]) dp[i+1][max(0,L−h⋅ai)][R−h⋅ai]
 * where h basically counts how MUCH of element i we take.
 * and if R−h⋅ai<0R-h \cdot a_i < 0R−h⋅ai​<0 then return 000 as it's not possible to make a sum fit within L⩽S⩽RL \leqslant S \leqslant RL⩽S⩽R (we're only dealing with positive numbers here!)
 * Anyway, this is horribly slow. At least it's polynomial time. The TC of this is O(n⋅r2)O(n \cdot r^2)O(n⋅r2), despite the loop, because it runs once for every element in the original array (including dupes).
 * 
 * Optimization #1
 * ===============
 * 
 * We don't need to track both L and R. We can find it for R and L will automatically be calculated. Then we just do dp[R] - dp[L-1]
 * However, evaluating this is O(nr). We need O(mr). That sum is the annoying part. There's guaranteed to be dupes, so we need to make use of that.
 * 
 * Optimization #2
 * ================
 * 
 * Suppose we are at index 3 with current sum 9, and a[3]=3, freq[a3] = 2
 * Then our sum looks like
 * dp[3][9]=∑(h=0 to 2) dp[4][9−h⋅3] = dp[4][9] + dp[4][6] + dp[4][3]
 * 
 * Okay, nothing special here. NOW! Let's look at the EXACT same scenario but this time R=12R = 12R=12. Just watch what happens.
 * dp[3][12] = ∑(h=0 to 2) dp[4][12−h⋅3] = dp[4][12] + dp[4][9] +dp[4][6]
 * 
 * This is exactly the same as
 * dp[4][12] + dp[4][9] + dp[4][6] = dp[4][12] + dp[4][9] + dp[4][6] + dp[4][3] − dp[4][3]
 * In other words,
 * dp[3][12]=dp[4][12]+dp[3][9]−dp[4][3]\Large \color{white} \text{dp}[3][12] = \color{red} \text{dp}[4][12] \color{white} + \text{dp}[3][9] \color{red} - \text{dp}[4][3]dp[3][12]=dp[4][12]+dp[3][9]−dp[4][3]
 * 
 * Our sum is gone. Just like that. Now, to encapsulate what we have learned, we can write it in this equation.
 * 
 * dp[i][R] = dp[i+1][R] + dp[i][R−ai] − dp[i+1][R−(freq[ai]+1)ai)]
 * 
 * Our base case is quite simple, dp[n][x]=1 
 *  x⩽rx
 *  You can think of it as a reward for reaching the finish line while being less than r.
 *  
 *  Complication
 *  =============
 *  If you have 0's. It breaks
 *  Let's say the answer to the question WITHOUT any 0's is x. Then, adding one zero will double that answer. Why? Because we can add a 0 to each of those subsets that works, and we can leave it alone. So we get the original PLUS the original with a 0 appended to it.
 *  If we have two 0's, you might think it's quadruple. But, we can't have the same multiset (i.e. you can only append nothing, one zero, or both zeroes.). So really it's just the same situation but we add x again.
 *  
 *  Basically, it's (1+number of 0’s)⋅ans
 *  
 *  Time complexity: O(r⋅min(n,r))
 *  Space complexity: O(r⋅min(n,r))