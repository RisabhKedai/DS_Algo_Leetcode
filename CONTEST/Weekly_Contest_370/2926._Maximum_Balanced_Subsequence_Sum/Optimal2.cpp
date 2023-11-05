/*
* @Author: lenovo
* @Date:   2023-11-06 01:36:07
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-06 01:57:50
*/

typedef long long int ll;
struct SegTree {
    vector<ll> tree;
    int n;
    
    SegTree (int _n) : n (_n) {
        tree.resize(4*n);
    }
    
    void update (int ind, ll val, int l = 0, int r = -1, int i = 0) {
        if (r == -1) r += n;
        if (l == r) {
            tree[i] = val;
            return;
        }
        
        int m = (l+r) >> 1;
        if (m >= ind) update (ind, val, l, m, i*2+1);
        else update (ind, val, m+1, r, i*2+2);
        
        tree[i] = max(tree[i*2+1], tree[i*2+2]);
    }
    
    ll query (int x, int y, int l = 0, int r = -1, int i = 0) {
        if (r == -1) r += n;
        
        if (r < x || l > y) return 0;
        if (l >= x && r <= y) return tree[i];
        
        int m = (l+r) >> 1;
        return max (
            query (x, y, l, m, i*2+1),
            query (x, y, m+1, r, i*2+2)
        );
    }
};

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        SegTree tree(nums.size());
        vector<pair<int,int>> val_ind;
        for(int i=0; i<n; i++){
            val_ind.push_back({nums[i]-i,i});
        }
        sort(val_ind.begin(),val_ind.end());
        unordered_map<int,int> sorted_ind;
        for(int i=0; i<n; i++){
            sorted_ind[val_ind[i].second] = i; 
        }
        for(int i=n-1; i>=0; i--){
            int j = sorted_ind[i];
            long long max_sum = tree.query(j+1,n-1) + nums[i];
            tree.update(j,max_sum);
        }
        return tree.query(0,n-1);
    }
};

/**
 * Refernce video : https://www.youtube.com/watch?v=W04cD_iFvfU
 *
 * The inequation in the problem can be simplified to:
 * nums[i]-i >= nums[j]-j
 * Thus, we can precompute and save these values.
 *
 * For each of the values, save the indexes where they belong to for reference;
 * Thus creating an array of pairs containg {nums[i]-i, i}
 *
 * Sort this array so that the values greater than a given value can be found quickly.
 * But not all the values right to a given index in the sorted array form a valid index. 
 * This is because some might have a lesser index in the actual array. 
 *
 * To solve this entire calculation is done on the original array from right to left. 
 * For each index find the maximum value occurring to the right of it in the sorted index and is activated / 
 * already encountered. Since the traversal is done from right to left the activated ones will always contained
 * the indexes which are to the right of the current index in the original array. 
 *
 * To find the maximum value within a given range Segment tree is the way forward. 
 * Thus for each current index find the position in the sorted array and for query the segment tree
 * from that position to the end to find the maximum value among the activated index to find the max value for current index. 
 *
 * Update the same in the seg tree. 
 *
 * Finally query the seg tree from 0 to n-1 to find the answer / maximum sum value
 *
 * Time complexity : O(NlogN)
 * Space complexity : O(N)
 *
 * Other approaches : Brute approach to check all possibilities of indices
 * Using DP to find LIS after simplifying the inequality 
 */