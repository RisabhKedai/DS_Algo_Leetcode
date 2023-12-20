/*
* @Author: lenovo
* @Date:   2023-12-21 00:04:24
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-21 00:11:19
*/

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> dist(s.length(),INT_MAX);
        int n = s.length();
        int least = -1;
        for(int i=0; i<n; i++){
            if(s[i] == c){
                least = i;
            }
            if(least != -1){
                dist[i] = min(dist[i],abs(i-least));
            }
        }
        least = n;
        for(int i=n; i>=0; i--){
            if(s[i] == c){
                least = i;
            }
            if(least != n){
                dist[i] = min(dist[i],abs(i-least));
            }
        }
        return dist;
    }
};

/**
 * Left traversal to find right closest
 * Right traversal to find left closest
 *
 * Time Complexity : O(N)
 * Space Complexity : O(N) [considering the return answer]
 */