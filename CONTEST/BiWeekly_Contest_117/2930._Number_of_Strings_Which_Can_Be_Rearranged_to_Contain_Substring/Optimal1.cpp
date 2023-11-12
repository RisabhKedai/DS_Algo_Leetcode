/*
* @Author: lenovo
* @Date:   2023-11-12 06:31:53
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-12 06:41:53
*/

class Solution {
public:
    int dp[100001][2][3][2]; // n length , 1l, 2e, 1t
    int n;
    int m;
    int dpUtil(int i, int l, int e, int t){
        if(i==n) return dp[0][0][0][0] = (l==0 && e==0 && t==0);
        if(dp[i][l][e][t] != -1){
            return dp[i][l][e][t];
        }
        long long remain = 26 - (l>0) - (e>0) - (t>0);
        dp[i][l][e][t] = 0;
        if(l>0) dp[i][l][e][t] = (dp[i][l][e][t] + dpUtil(i+1,l-1,e,t))%m;
        if(e>0) dp[i][l][e][t] = (dp[i][l][e][t] + dpUtil(i+1,l,e-1,t))%m;
        if(t>0) dp[i][l][e][t] = (dp[i][l][e][t] + dpUtil(i+1,l,e,t-1))%m;
        dp[i][l][e][t] = (dp[i][l][e][t] + (remain*dpUtil(i+1,l,e,t)))%m;
        return dp[i][l][e][t];
    }
    int stringCount(int n) {
        this->n = n;
        m = 1e9 + 7;
        memset(dp,-1,sizeof(dp));
        return dpUtil(0,1,2,1);
    }
};

/**
 * Reference : https://leetcode.com/problems/number-of-strings-which-can-be-rearranged-to-contain-substring/solutions/4276657/share-my-dp-solution-c/
 * 			   https://leetcode.com/problems/number-of-strings-which-can-be-rearranged-to-contain-substring/solutions/4276683/dp-with-explanation/
 * 
 * Let dp[i][x][y][z] represent the number of strings whose length is i and that have x character l's, y character e's and z character t's.
 * When a string has more than 1 character l, more than 2 character e's and more than 1 character t, we don't care about the exact number of those characters.
 * 
 * So let's tweak the definition of dp[i][x][y][z] a little bit.
 *  x = 0 means no character l.
 *  x = 1 means at least 1 character l.
 *  y = 0 means no character e.
 *  y = 1 means only 1 character e.
 *  y = 2 means at least 2 character e's.
 *  z = 0 means no character t.
 *  z = 1 means at least 1 character t.
 *  
 *  Then the problem is equivalent to solve dp[n][1][2][1].
 *  
 *  When calculating dp[i][x][y][z], we need to think about how the last character affects the value of x, y, or z. With that knowledge, we will be able to derive dp[i][x][y][z] from dp[i-1][...][...][...].
 *  The last character can either contribute to an increment to x or y, or z or have no impact on those values.
 *  
 *  When the last character is not one of l, e, or t, it won't change the value of x, y, or z. 
 *  When the last character is l and x is already 1, it won't change the value of x, y, or z.
 *  When the last character is l and x is less than 1, it will cause the value of x to increase by 1.
 *  When the last character is e and y is already 2, it won't change the value of x, y, or z.
 *  When the last character is e and y is less than 2, it will cause the value of y to increase by 1.
 *  When the last character is t and z is already 1, it won't change the value of x, y, or z.
 *  When the last character is t and z is less than 1, it will cause the value of z to increase by 1.
 *  Also whenever we get the first l, e, t we capture it in the respective counts because we don't want repeated strings having same chars at same position 
 *  Based on these, it should be easy to derive the value of dp[i][x][y][z] from dp[i-1][x][y][z], dp[i-1][x-1][y][z], dp[i-1][x][y-1][z], and dp[i-1][x][y][z-1].
 *  
 *  Also, note that dp[i][...][...][...] only depends on dp[i-1][...][...][...], so it is not necessary to have a 4-dimensional array. You can use two 3-dimensional arrays instead.
 *  
 *  Complexity
 *  Time complexity: O(N∗X∗Y∗Z)O(N*X*Y*Z)O(N∗X∗Y∗Z) where NNN is the required length of the string, XXX is the number of required character l's (in this case, it is fixed to 1), YYY is the number of required character e's (in this case, it is fixed to 2), and ZZZ is the number of required character t's (in this case, it is fixed to 1).
 *  Space complexity: O(X∗Y∗Z)O(X*Y*Z)O(X∗Y∗Z) where XXX is the number of required character l's (in this case, it is fixed to 1), YYY is the number of required character e's (in this case, it is fixed to 2), and ZZZ is the number of required character t's (in this case, it is fixed to 1).
 */