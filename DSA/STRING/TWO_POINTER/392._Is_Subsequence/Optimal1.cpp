/*
* @Author: lenovo
* @Date:   2024-02-19 21:47:58
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-19 21:49:27
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ind = 0;
        for(int i=0;i<t.length();i++){
            if(ind<s.length() && s[ind]==t[i]){
                ind++;
            }
        }
        return ind==s.length();
    }
};

/**
 * Use a pointer to check if the string s is entirely covered or not
 * 
 * Time complexity : O(n)
 * Space complexity : O(1)
 */