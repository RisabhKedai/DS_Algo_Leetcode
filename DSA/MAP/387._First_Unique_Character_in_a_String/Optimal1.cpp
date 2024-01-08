/*
* @Author: lenovo
* @Date:   2024-01-09 00:17:20
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-09 00:18:41
*/


class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int,int>> freq(123,{0,-1});
        for(int i=0; i<s.length(); i++){
            freq[s[i]].first++;
            freq[s[i]].second = i;
        }
        int mi = INT_MAX;
        for(auto x : freq){
            if(x.first == 1){
                mi = min(mi, x.second);
            }
        }
        return mi == INT_MAX?-1 : mi;
    }
};

/**
 * 1 traversal across the string to store the frequency of each character
 * and last index where it occured.
 *
 * Time complexity : O(N)
 * Space complexity : O(1)
 */