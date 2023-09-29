/*
* @Author: lenovo
* @Date:   2023-09-29 22:11:57
* @Last Modified by:   lenovo
* @Last Modified time: 2023-09-29 22:19:52
*/
class Solution {
public:
    void util(int r, int c, vector<vector<int>>& board){
      int liv = 0;
      int dea = 0;
      int n = board.size();
      int m = board[0].size();
      if(r>=n || c>=m){
          return;
      }
      int nr,nc;
      nr = r+1;
      nc = c;
      if(nr == n){
          nr = 0;
          nc += 1;
      }
      int ctr=0;
      for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
          if(!(i==0 && j==0))
          if((r+i)>=0 && (r+i)<n && (c+j)>=0 && (c+j)<m){
              ctr++;
            liv += board[r+i][c+j];
          }
        }
      }
      dea = ctr-liv;
      if(board[r][c] && (liv<2 || liv>3)){
          util(nr,nc,board);
          board[r][c] = 0;
      }else if(!board[r][c] && liv==3){
          util(nr,nc,board);
          board[r][c] = 1;
      }else{
          util(nr,nc,board);
      }
    }
    void gameOfLife(vector<vector<int>>& board) {
        util(0, 0, board);
    }
};

/**
 * The question can be simply solved by creating a copy vector.
 * But this can be done using recursion where in the editing happens in place.
 * At each step we check the status of the cell whether it is going to change or not.
 * Accordingly first a recurrsive call is made for the next cell before actually changing the cell value. 
 * The recursive call helps us store the status in the current call.
 * And on the backtracking path we change the values accordingly.
 */