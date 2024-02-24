/*
* @Author: lenovo
* @Date:   2024-02-25 02:55:28
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-25 02:56:24
*/

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string,int> mp;
        vector<string> ans;
        for(int i=0; i<cpdomains.size(); i++){
            string cpdomain = cpdomains[i];
            int cnt = 0;
            string dom1;
            int space;
            for(int j=0; j<cpdomain.length(); j++){
                if(cpdomain[j]==' '){
                    space = j;
                    cnt = stoi(cpdomain.substr(0,j));
                    dom1 = cpdomain.substr(j+1,cpdomain.length());
                    mp[dom1] += cnt;
                }
                if(cpdomain[j]=='.'){
                    dom1 = cpdomain.substr(j+1,cpdomain.length());
                    mp[dom1]+=cnt;
                }
            }
        }
        for(auto x: mp){
            ans.push_back(to_string(x.second)+" "+x.first);
        }
        return ans;
    }
};

/**
 * Simple implementation of string manipulation and hash maps
 *
 * Time complexity : O(N)
 * Space complexity : O(N)
 */