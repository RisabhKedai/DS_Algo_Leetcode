/*
* @Author: lenovo
* @Date:   2024-02-19 22:07:26
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-19 22:13:48
*/


class Solution {
public:
    int compress(vector<char>& chars) {
        int ind = 0;
        int curr = chars[0];
        int cnt = 1;
        for(int i=1; i<chars.size(); i++){
            if(chars[i]==chars[i-1]){
                cnt++;
            }else{
                chars[ind++] = curr;
                if(cnt>1)
                for(int j=0; j<to_string(cnt).length(); j++){
                    chars[ind++] = to_string(cnt)[j];
                }
                cnt = 1;
            }
            curr = chars[i];
        }
        chars[ind++] = curr;
        if(cnt>1)
        for(int j=0; j<to_string(cnt).length(); j++){
            chars[ind++] = to_string(cnt)[j];
        }
        return ind;
    }
};

/**
 * One pointer to maintain the last modified index.
 * One pointer to traverse the original string. 
 * 
 * Time complexity: O(N)
 * Space complexity : O(1)
 */