/*
* @Author: lenovo
* @Date:   2024-01-11 22:25:32
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-13 14:08:14
*/


class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> table(26,vector<int>(votes[0].length()+1,0));
        for(int i=0; i<26; i++){
            table[i][votes[0].length()] = i;
        }
        for(auto vote : votes) {
            for(int i=0; i<vote.length(); i++) {
                table[vote[i]-'A'][i]--;
            }
        }
        sort(table.begin(), table.end());

        string ans = "";
        for(int i=0; i<26; i++) {
            ans += (char)('A' + table[i][votes[0].length()]);
        }
        
        return ans.substr(0,votes[0].length());
    }
};

/**
 * For each letter have the frequency of votes they have for each position. 
 * Sort individial letters according to the data 
 * form a sequence accoring to this table. 
 * 
 * Time complexity : O(N * size of each string), O(26 * size of each string)
 * Space complexity : O(26 * size of each string)
 */