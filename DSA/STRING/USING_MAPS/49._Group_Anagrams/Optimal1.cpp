/*
* @Author: lenovo
* @Date:   2024-02-25 03:14:17
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-25 03:15:40
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for(auto st : strs){
            string t =st;
            sort(st.begin(), st.end());
            mp[st].push_back(t);
        }
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};

/**
 * Sort each word such that all the anagrams turn to be one common string.
 * Use that as a key to group them all up.
 *
 * Time complexity : O(NMlogM)
 * Space complexity: O(N)
 */