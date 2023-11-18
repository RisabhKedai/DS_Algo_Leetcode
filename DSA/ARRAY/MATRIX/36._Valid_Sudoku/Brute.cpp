/*
* @Author: lenovo
* @Date:   2023-11-16 23:36:56
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-16 23:38:17
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // verify correct rows
        for(int i=0; i<9; i++){
            vector<bool> arr(9,false);
            for(int j=0; j<9; j++){
                if(board[i][j]!='.' && arr[board[i][j]-48]){
                    return false;
                }
                if(board[i][j]!='.')
                arr[board[i][j]-48] = true;
            }
        }
        // verify columns
        for(int i=0; i<9; i++){
            vector<bool> arr(9,false); 
            for(int j=0; j<9; j++){
                if(board[j][i]!='.' && arr[board[j][i]-48]){
                    return false;
                }
                if(board[j][i]!='.')
                arr[board[j][i]-48] = true;
            }
        }
        // verify cells
        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                vector<bool> arr(9,false); 
                for(int a=i; a<i+3; a++){
                    for(int b=j; b<j+3; b++){
                        if(board[a][b]!='.' && arr[board[a][b]-48]){
                            return false;
                        }
                        if(board[a][b]!='.')
                        arr[board[a][b]-48] = true;
                    }
                }
            }
        }
        return true;
    }
};


/** 
 * Check row wise
 * Coulumn wise 
 * For each box
 *
 * Time Complexity : O(1)
 * Space Complexity : O(1)
 */