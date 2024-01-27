/*
* @Author: lenovo
* @Date:   2024-01-28 00:19:17
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-28 00:21:50
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int beg = 0, end = n-1;
        while(beg<=end){ 
            int mid = (beg+end)/2;
            if(arr[mid]-mid-1 < k){
                beg = mid + 1;
            }else{
                end = mid-1;
            }
        }
        return beg+k;
    }
};

/**
 * For the first i numbers in A, the count of missing numbers in these i numbers is A[i-1] - i.
 * Example:
 * A=[1,4,5,8]
 * i=3
 * A[i-1]-i = 5-3 = 2 // There are two missing numbers in [1,4,5]
 * We can binary search the maximum i which satisfies A[i-1] - i < k. Assume it's L, then L + k is the answer.
 * 
 * A=[1,4,5,8]
 * k=3
 * i=3 is the maximum number which satisfies `A[i-1]-i = 2 < k = 3`, so the answer is 3 + k = 6
 * 
 * A special case of i is when i == 0, then there is 0 missing number in this empty subarray. This is a valid case because for example A=[2], k=1, the maximum number of i which satisfies count of missing number < k is 0.
 * So the range of the binary search should be [0, N].
 * 
 * So initially let L = 0, R = N, and M be the middle value. To avoid infinite loop, let M = (L + R + 1) / 2.
 * When count of missing number is less then k, M might be too small or exactly the index we are looing for, we let L = M.
 * Otherwise, M is too large, let R = M - 1.
 *
 * Time complexity : O(LogN)
 * Space Complexity : O(1)
 */