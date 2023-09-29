/*
* @Author: lenovo
* @Date:   2023-09-28 00:35:21
* @Last Modified by:   lenovo
* @Last Modified time: 2023-09-28 00:43:10
*/
class Solution {
public:
    bool verify(string s, int ind, string src){
        for(int i=0; i<src.length(); i++){
            if(s[ind+i] != src[i]){
                return false;
            }
        }
        return true;
    }
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int k = indices.size();
        int n = s.size();
        string ans = "";
        map<int,pair<string,string>> inp;
        for(int i=0; i<k; i++){
            if(verify(s,indices[i],sources[i]))
            inp[indices[i]] = {sources[i],targets[i]};
        }
        int ind = 0;
        while(ind!=n){
            if((inp.find(ind)!=inp.end())){
                for(int j=0; j<inp[ind].second.size(); j++){
                    ans += inp[ind].second[j];
                }
                ind = ind + inp[ind].first.length();
            }else{
                ans += s[ind];
                ind ++;
            }
        }
        return ans;
    }
};

/**
 * It is a simple implementation problem that uses hashmap, sorting technique.
 * Prepare a hash map with keys as indices and values as valid src and target to the replacable string.
 * For each index we check if this index is in the index table or not. 
 * If it is available then we replace the source with the target and move to an index beyond that source.
 * If not then simply move ahaead.
 *
 * Time complexity : O(SN)
 * Space Complexity: O(N+K)
 */