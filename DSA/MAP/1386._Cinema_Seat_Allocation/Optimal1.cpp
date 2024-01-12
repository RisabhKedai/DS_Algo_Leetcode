/*
* @Author: lenovo
* @Date:   2024-01-12 22:55:48
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-12 22:57:55
*/

class Solution {
public:
    int check(vector<int>& row) {
        if(accumulate(row.begin()+1,row.begin()+9,0)==8){
            return 2;
        }else if(accumulate(row.begin()+1,row.begin()+5,0)==4){
            return 1;
        }else if(accumulate(row.begin()+5,row.begin()+9,0)==4){
            return 1;
        }else if(accumulate(row.begin()+3,row.begin()+7,0)==4){
            return 1;
        }else{
            return 0;
        }
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end());
        int ans = 0 ;
        int ind = 0;
        map<int,vector<int>> resSeat;
        for(auto x : reservedSeats){
            if(resSeat.contains(x[0]-1)){
                resSeat[x[0]-1][x[1]-1] = 0;
            }else{
                resSeat[x[0]-1] = vector<int>(10,1);
                resSeat[x[0]-1][x[1]-1] = 0;
            }
        }
        int cnt = 0;
        for(auto x : resSeat){
            ans += check(x.second);
            cnt ++;
        }
        ans += 2*(n-cnt);
        return ans;
    }
};

/**
 * M = size of reserved seats
 * create a map that tracks allocated seats for each row where there is at least one seat allocated
 * For all the other rows the anwer will be 2.
 * 
 * Time Compliexity : O(M)
 * Space Complexity : O(M)
 */