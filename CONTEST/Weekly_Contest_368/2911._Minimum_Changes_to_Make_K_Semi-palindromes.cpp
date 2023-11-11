/*
* @Author: lenovo
* @Date:   2023-10-22 13:24:15
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-22 13:29:26
*/
class Solution {
public:
    vector<vector<int>> opsreq;
    int calculate(string s, int i, int j){
        int len = j-i+1;
        int ans = INT_MAX;
        for(int d=1; d<len; d++){
            if(len%d==0){
                int ford = 0;
                int numchar = len/d;
                for(int offset = 0; offset<d; offset++){
                    for(int k=0; k<numchar/2; k++){
                        ford += s[i+offset + (d*k)] != s[i+offset+((numchar-k-1)*d)];
                    }
                }
                ans = min(ans,ford);
            }
        }
        return ans;
    }
    void calcreq(string s){
        int l = s.length();
        for(int i=0; i<l; i++){
            for(int j=i+1; j<l; j++){
                opsreq[i][j] = calculate(s,i,j);
            }
        }
    }
    int util(string s, int ind, int k, vector<vector<int>>& dp){
        if(k==0){
            if(ind == -1){
                return dp[ind+1][k] = 0;
            }else{
                return dp[ind+1][k] = 10000;
            }
        }
        if( 2 > (ind+1)/k){
            return dp[ind+1][k] = 10000;
        }
        if(dp[ind+1][k] != INT_MAX){
            return dp[ind+1][k];
        }
        for(int i = ind-1; i>=0; i--){
            dp[ind+1][k] = min(dp[ind+1][k],opsreq[i][ind] + util(s,i-1,k-1,dp));
        }
        return dp[ind+1][k];
    }
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(k+1,INT_MAX));
        opsreq = vector<vector<int>>(n,vector<int>(n,INT_MAX));
        calcreq(s);
        util(s,n-1,k,dp);
        return dp[n][k];
    }
};

/**
 * The code follows a simple approach of 1 precomputation and 1 DP. 
 * The first Pre-Comp is used to calculate the number of changes required to
 * make a string semi-palindrome from i to j. 
 *
 * This is done by calculating the offset for every d which divides (j-i+1)
 * [length of substring] and then finding the inequalities.
 *
 * Finally, the second DP is used to calculate the changes required for the string s[:i] 
 * (string till i) when there are only k operations left. 
 * This is stored in DP table of height n and width k. 
 *
 * Time complexity : O(n^3) + O(nk)
 * Space Complexity : O(N^2) 
 */