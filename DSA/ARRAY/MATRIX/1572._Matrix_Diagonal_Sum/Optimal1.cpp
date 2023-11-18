/*
* @Author: lenovo
* @Date:   2023-11-13 21:32:24
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-13 21:34:04
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += mat[i][i];
            if(i != n-i-1)
            ans += mat[i][n-i-1];
        }
        return ans;
    }
};

/**
 * For every row add the 2 diagonal elements to the sum. 
 * If the 2 elements are same i.e., the crossing element then add only once. 
 *
 * Return the sum
 *
 * Time complexity : O(N)
 * Space Complexity : O(1)
 */