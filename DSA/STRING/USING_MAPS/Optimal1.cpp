/*
* @Author: lenovo
* @Date:   2024-02-24 23:14:17
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-24 23:16:44
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
 * Save the occurences in a map and the respective count array.
 * Find the first occurence of single frequency letter.
 *
 * Time complexity : O(N)
 * Space complexity : O(1)
 */