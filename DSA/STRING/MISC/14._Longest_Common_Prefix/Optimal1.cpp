/*
* @Author: lenovo
* @Date:   2024-03-11 19:03:18
* @Last Modified by:   lenovo
* @Last Modified time: 2024-03-11 19:05:01
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int i=0;
        while(true){
            // cout<<i<<endl;
            for(int j=1; j<strs.size(); j++) {
                if(i>=strs[j].length() || strs[j][i]!=strs[j-1][i]) {
                    return ans;
                }
            }
            if(i>=strs[0].length())
            return ans;
            
            ans += strs[0][i];
            i++;
        }
        return ans;
    }
};

/*
Check the 1st letters of each word,
then check 2nd letter of each word ,
3rd letter and so on till you all the nth letters match

Time complexity : O(N)
Space complexity : O(1)
*/
