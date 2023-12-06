/*
* @Author: lenovo
* @Date:   2023-12-07 00:17:39
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-07 00:22:32
*/
bool comp(string a, string b) {
  return (a+b)>(b+a);
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
      int n = nums.size();
        vector<string> cas(n);
        for(int i=0; i<n; i++){
            cas[i] = to_string(nums[i]);
        }
        sort(cas.begin(),cas.end(),comp);
        string ans = "";
        int flag = 0;
        for(auto x : cas){
          if(x != "0") flag = 1;
            ans += x;
        }
        if(flag == 0)
        return "0";

        return ans;
    }
};

/**
 * A simple comparison problem but the trick actually lies with comparison sorting. 
 *
 * The numbers are converted to the string form.
 * The sorting is done on the basis of the position of the strings in the final string. 
 *
 * Consider two strings [3,30]. They both have same place values if we see from the perspective of 
 * 3- and 30. Now there are 2 possibilities 330 and 303. So we can just compare 330 and 303 to find which of 3 and 30 will come first
 *
 * Time complexity : O(9n.log(9n))
 * Space complexity : O(1)
 */