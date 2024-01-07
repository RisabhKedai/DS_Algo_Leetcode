/*
* @Author: lenovo
* @Date:   2024-01-07 11:11:01
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-07 11:13:38
*/
class Solution {
public:
    vector<int> dp;
    int util(int x, int y){
        if(dp[x] != -1){
            return dp[x];
        }    
        int res= abs(x-y); //case 1
        if(x<=y){
            return dp[x] = res;
        }
        res = min(res,(11-(x%11) + 1 + util(x/11 + 1,y)));
        res = min(res,x%11 + 1 + util(x/11, y));
        res = min(res,(5-(x%5) + 1 + util(x/5 + 1,y)));
        res = min(res,x%5 + 1 + util(x/5, y));
        dp[x] = res;
        return res;
    }
    int minimumOperationsToMakeEqual(int x, int y) {
        dp = vector<int>(10011,-1);
        return util(x,y);
        
    }
};

/**
 * We need to check for 5 ways in our recursive calls :
 * Just abs diff of x & y can be ans. So initialise res = abs(x - y)
 * 
 * We may go to multiple of 5 which is smaller than x. This can be achieved by just subtracting x%5 from x and divide x by 5. Here total operations = x%5 ( this many time decreament ) + 1( for division by 5).
 * We may go to multiple of 5 which is larger than x. This can be achieved by just adding (5 - x%5) to x and then divid x by 5. Here total operations = 5 - x%5 ( this many time increment ) + 1( for division by 5).
 * We may go to multiple of 11 which is smaller than x. This can be achieved by just subtracting x%11 from x and divide x by 11. Here total operations = x%11 ( this many time decreament ) + 1( for division by 11).
 * We may go to multiple of 11 which is larger than x. This can be achieved by just adding (11 - x%11) to x and then divid x by 11. Here total operations = 11 - x%11 ( this many time increment ) + 1( for division by 11).
 *
 * 
 * With considereing above cases we need to write recursive code to find the min operations.
 * 
 * Complexity
 * Time : O(N)
 * Space : O(N)
 */