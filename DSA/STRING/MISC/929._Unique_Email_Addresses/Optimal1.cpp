/*
* @Author: lenovo
* @Date:   2024-03-08 04:38:27
* @Last Modified by:   lenovo
* @Last Modified time: 2024-03-08 04:40:08
*/

class Solution {
public:
    string process(string s){
        string ans = "";
        int i=0;
        bool cond = true;
        while(i<s.length()){
            if(s[i]=='.' && cond){
                i++;
                continue;
            }
            if(s[i]=='+' && cond){
                while(s[i]!='@'){
                    i++;
                }
            }
            if(s[i]=='@'){
                cond = false;
            }
            ans+=s[i];
            i++;
        }
        return ans;
    }
    int numUniqueEmails(vector<string>& emails) {
        map<string,bool> mp;
        for(auto mail : emails){
            // cout<<process(mail)<<endl;
            mp[process(mail)] = true;
        }
        return mp.size();
    }
};

/**
 * Pure implementation
 *
 * Time complexity : O(N)
 * Space complexity : O(N)
 */