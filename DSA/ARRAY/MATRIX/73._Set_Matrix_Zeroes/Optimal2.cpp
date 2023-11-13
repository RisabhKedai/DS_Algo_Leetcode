/*
* @Author: lenovo
* @Date:   2023-11-13 21:46:07
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-13 22:05:01
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(matrix.size(),1);
        vector<int> col(matrix[0].size(),1);
        bool row0 = false;
        bool col0 = false;
        for(int i=0; i<n; i++){
            if(matrix[i][0] == 0){
                col0 = true;
            }
        }
        for(int j=0; j<m; j++){
            if(matrix[0][j] == 0){
                row0 = true;
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                matrix[i][j] = (matrix[0][j]==0 || matrix[i][0]==0)?0:matrix[i][j];
            }
        }
        if(row0)
        for(int j=0; j<m; j++){
            matrix[0][j] = 0;
        }
        if(col0)
        for(int i=0; i<n; i++){
            matrix[i][0] = 0;
        }
    }
};

/**
 * Use the same approach as previous Optimal1 solution but in this case just use the top row 
 * and left column ans row and col arrays respectively. 
 * However we also need to track the 1st row and left column. This can be done in 2 variables  only.
 * row0 and col0 are the variables. 
 *
 * After getting the information from row 0 and left column we can use the 2 reference variables 
 * to make the row and column 0 accrodingly
 *
 * Time Complexity: O(mn)
 * Space Complexity : O(1) 
 */