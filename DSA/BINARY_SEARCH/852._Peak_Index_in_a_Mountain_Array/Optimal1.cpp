/*
* @Author: lenovo
* @Date:   2024-02-01 22:18:26
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-01 22:20:12
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int beg = 1, end = arr.size()-2;
        while(beg <= end){
            int mid = (beg+end)/2;
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
                return mid;
            }
            if(arr[mid-1]>=arr[mid] && arr[mid]>=arr[mid+1]){
                end = mid - 1;
            }else{
                beg = mid + 1;
            }
        }
        return -1;
    }
};

/**
 * Do a binary search to find the maximum element possible. 
 * The search criteria would be the downward or the upward descent.
 *
 * Time complexity : O(log N)
 * Space complexity : O(1)
 */