/*
* @Author: lenovo
* @Date:   2024-02-19 22:02:29
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-19 22:07:16
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        string ans= "";
        char curr = chars[0];
        int cnt = 1;
        for(int i=1; i<chars.size(); i++){
            if(chars[i]==curr){
                cnt++;
            }else{
                ans += curr;
                if(cnt>1){
                    ans += to_string(cnt);
                }
                cnt = 1;
            }
            curr = chars[i];
        }
        ans += curr;
        if(cnt>1){
            ans += to_string(cnt);
        }
        chars = vector<char>(ans.begin(),ans.end());
        return ans.length();
    }
};

/**
 * Create an ans string that stores the actual compressed string.
 * Later just return the length of the ans string.
 * 
 * Time complexity : O(N)
 * Space complexity : O(N)
 */                              