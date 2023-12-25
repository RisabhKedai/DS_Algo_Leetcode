/*
* @Author: lenovo
* @Date:   2023-12-25 21:44:12
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-25 21:51:05
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int tot = 0;
        int cnt = flowerbed[0]==0;
        for(int i=0; i<flowerbed.size(); i++){
            if(flowerbed[i] == 0){
                cnt += 1;
            } else{
                tot += (cnt-1)/2;
                cnt = 0;
            }
        }
        cnt += flowerbed[flowerbed.size()-1]==0;
        tot += (cnt-1)/2;
        return (tot >=n);
    }
};

/**
 * Count the number of empty places between each pair of ones. 
 * Then the number of fillable gaps is total gap - 1 / 2
 * But in case the gap is in the prefix or suffix ,
 * then the number of flowers is cnt / 2;
 * In that case I added one gap so that the -1 gets cancelled. 
 *
 * Time complexity : O(N)
 * Space complexity : O(1)  
 */