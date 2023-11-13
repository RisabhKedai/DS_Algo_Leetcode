/*
* @Author: lenovo
* @Date:   2023-11-13 21:46:07
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-13 21:48:14
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row(matrix.size(),1);
        vector<int> col(matrix[0].size(),1);
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                matrix[i][j] = (row[i]==0 || col[j]==0)?0:matrix[i][j];
            }
        }
    }
};

/**
 * Use 2 arrays row and column to mark if the current row number has a 0. 
 * Use col to mark if current column number is 0.
 * Traverse the martix again and make cell 0 if either row[i] is 0 or col[j] = 0
 *
 * Time Complexity : O(mn)
 * Space Complexity : O(n+m)
 */