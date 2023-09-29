class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto x: nums)
            ans ^= x;
        return ans;
    }
};

/**
  * This works because the xor of a number with itself is 0.
  * As each number occura twice, we can say that A^A = 0
  * A number B is unique and doesn't occur twice. In that case A^B = somethine
  * A^B^A = A^A^B = 0^B = B.
  * Thus tthe unique element is procured
  * This method only works when the number of repertition for each element is even
  * 
  * Time complexity : O(N)
  * Space complexity : O(1)
*/