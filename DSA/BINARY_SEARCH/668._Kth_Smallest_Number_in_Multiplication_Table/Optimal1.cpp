/*
* @Author: lenovo
* @Date:   2024-02-13 21:51:59
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-13 21:56:33
*/

class Solution {
public:
    int count(int m, int n, int k){
        int cnt = 0;
        for(int i=1; i<=m; i++){
            cnt += min(n,k/i);
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        if(n<m){
            return findKthNumber(n,m,k);
        }
        int beg = 1, end = k;
        int ans;
        while(beg<=end){
            int mid = (beg+end)/2;
            if(count(m,n,mid) < k){
                beg = mid+1;
            }else{
                end = mid-1;
                ans = mid;
            }
        }
        return ans;
    }
};

/**
 * Since k<=m*n, binary search space is 1..m*n. 
 * For a number go on each row and check number of elements less that equal to that number.
 * If that is greater than equal to k, that can be a potential answer. 
 * This is because there are repeated elements as well. Since we are also reducing the possible answer to minimum,
 * eventually we get real close to k.
 *
 * Another optimization is to take n or m which is a lower number to represent rows and other is column.
 *
 * Time complexity : O(min(m*n)log(k))
 * Space complexity : O(1)
 */