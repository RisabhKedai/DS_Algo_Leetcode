/*
* @Author: lenovo
* @Date:   2023-10-18 06:08:57
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-18 06:12:38
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = -1;
        int cnt = 0;
        for(auto x : nums){
            if(cnt ==0){
                cand = x;
                cnt =1;
                continue;
            }
            if(x == cand){
                cnt++;
            }else{
                cnt--;
            }
        }
        return cand;
    }
};

/**
 * Follows the Moore voting algorithm
 * If an element is majority it will always have the lead.
 * Take an aribitary number as candidate and count as 0 and iterate as:
 * 1. if count ==0 replace the cand with element
 * 2. if cand == element increase count
 * 3. If not equal to elemtnt decrease count by 1
 * 
 *
 * The algorithm starts by assuming the first element as the majority candidate and sets the count to 1.
 * As it iterates through the array, it compares each element with the candidate:
 * a.If the current element matches the candidate, it suggests that it reinforces the majority element because it appears again. Therefore, the count is incremented by 1.
 * b. If the current element is different from the candidate, it suggests that there might be an equal number of occurrences of the majority element and other elements. Therefore, the count is decremented by 1.
 * Note that decrementing the count doesn't change the fact that the majority element occurs more than n/2 times.
 * If the count becomes 0, it means that the current candidate is no longer a potential majority element. In this case, a new candidate is chosen from the remaining elements.
 * The algorithm continues this process until it has traversed the entire array.
 * The final value of the candidate variable will hold the majority element
 */