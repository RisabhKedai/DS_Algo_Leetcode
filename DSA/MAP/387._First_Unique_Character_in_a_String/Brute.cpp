/*
* @Author: lenovo
* @Date:   2024-01-09 00:15:27
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-09 00:17:10
*/


class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(123,0);
        for(auto c : s){
            freq[c]++;
        }
        for(int i=0; i<s.length(); i++){
            if(freq[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};

/**
 * 2 traversals across the string.
 * One to make the frequency array
 * 2nd to find the first index with frequency 1
 *
 * Time complexity : O(2*N)
 * Space complexity : O(1)
 */