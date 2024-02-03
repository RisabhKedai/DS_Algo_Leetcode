/*
* @Author: lenovo
* @Date:   2024-01-09 20:05:04
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-03 10:10:21
*/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2!=0){
            return {};
        }
        sort(changed.begin(), changed.end());
        map<int,int> isDouble;
        vector<int> ans;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(isDouble[changed[i]]) {
                isDouble[changed[i]]--;
                cnt++;
            }else{
                ans.push_back(changed[i]);
                isDouble[2*changed[i]]++;
            }
        }
        if(cnt == n/2){
            return ans;
        }else{
            return {};
        }
    }
};

/**
 * Copy a solution from 954. Array of Doubled Pairs 
 * [https://leetcode.com/problems/array-of-doubled-pairs/discuss/203183/JavaC%2B%2BPython-Match-from-the-Smallest-or-Biggest-100] 
 * There can be 2 types of numbers in the array. 
 * Number and its double
 * The smallest number in the array will always be a number
 * Start from the left take a number and add its double to a map.
 *
 * Next when you encounter a number check if it is someone's double and reduce count in map.
 * If not it is again a normal number and add its double to a map.
 *
 * 0 won't fail this  test case because :
 * In case count[0] is odd, it won't get matched in the end.
 * In case count[0] is even, we still have c[0] <= c[2 * 0].
 * 
 * Time complexity : O(NlogN)
 * Space complexity : O(N)
 */ 