/*
* @Author: lenovo
* @Date:   2024-02-11 15:28:04
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-11 15:45:32
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 < N2) return findMedianSortedArrays(nums2, nums1);	// Make sure A2 is the shorter one.
        
        int lo = 0, hi = N2 * 2;
        while (lo <= hi) {
            int mid2 = (lo + hi) / 2;   // Try Cut 2 
            int mid1 = N1 + N2 - mid2;  // Calculate Cut 1 accordingly
            
            double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];	// Get L1, R1, L2, R2 respectively
            double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
            double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
            double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];
            
            if (L1 > R2) lo = mid2 + 1;		// A1's lower half is too big; need to move C1 left (C2 right)
            else if (L2 > R1) hi = mid2 - 1;	// A2's lower half too big; need to move C2 left.
            else return (max(L1,L2) + min(R1, R2)) / 2;	// Otherwise, that's the right cut.
        }
        return -1;
    }
};

/**
 * Reference : https://leetcode.com/problems/median-of-two-sorted-arrays/solutions/2471/very-concise-o-log-min-m-n-iterative-solution-with-detailed-explanation/
 * Now how do we decide if this cut is the cut we want? Because L1, L2 are the greatest numbers on the left halves and R1, R2 are the smallest numbers on the right, we only need
 *
 * Basically Decide the cut on array 1 as C1 based on C1 decide where the cut needs to be made to C2.
 * The number of elements on both the halves should remain equal (L1+L2)==(R1+R2).
 * But another condition must be maintained :
 *  L1 <= R1 && L1 <= R2 && L2 <= R1 && L2 <= R2
 * 
 * Time complexity : O(min(n,m))
 * Space complexity : O(1)
 */