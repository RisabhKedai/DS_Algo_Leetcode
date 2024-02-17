/*
* @Author: lenovo
* @Date:   2024-02-17 08:43:08
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-17 08:43:59
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i=0; i<n/2; i++){
            swap(s[i],s[n-i-1]);
        }
    }
};

/**
 * Keep swaping the first element and last element while decreasing both
 *
 * Time complexity : O(N)
 * Space complexity : O(1)
 */