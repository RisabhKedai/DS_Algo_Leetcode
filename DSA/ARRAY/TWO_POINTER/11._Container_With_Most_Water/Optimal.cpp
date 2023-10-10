/*
* @Author: lenovo
* @Date:   2023-10-07 22:44:09
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-07 22:47:52
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int s = 0;
        int e = n-1;
        int ans = 0;
        while(s<e){
            ans = max(ans,(e-s)*min(height[s],height[e]));
            if(height[s]<height[e]){
                s++;
            }else{
                e--;
            }
        }
        return ans;
    }
};
/**
 * Greedily maintaining 2 pointers each for the first and last
 * Use the pointer pointing to the smaller pole. 
 * This is because, if we move from a larger pole, the total area will alaways decrease,
 * because the height will be min of 2 poles and distance will keep decreasing. 
 * So the aim should be always to move from lower pole to a possibly heigher pole.
 * This can be done if the pointer at lower pole is changed. 
 * 
 * Time Complexity : O(n)
 * Space COmplexity : O(1)  
 */