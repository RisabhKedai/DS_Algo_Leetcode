/*
* @Author: lenovo
* @Date:   2024-01-07 11:43:42
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-07 12:15:46
*/

class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        map<int,bool> cnt1,cnt2;
        map<int,bool> added;
        for(auto x: nums1){
            cnt1[x] = true;
        }
        for(auto x: nums2){
            cnt2[x] = true;
        }
        int i=0;
        vector<int> ans1, ans2;
        while(i<nums1.size() && ans1.size()<nums1.size()/2){
            if(cnt1[nums1[i]] && !(cnt2[nums1[i]]) && !added[nums1[i]]){
                ans1.push_back(nums1[i]);
                added[nums1[i]] = true;
            }
            i++;
        }
        i=0;
        while(i<nums2.size() && ans2.size()<nums2.size()/2 ){
            if(!cnt1[nums2[i]] && cnt2[nums2[i]] && !added[nums2[i]]){
                ans2.push_back(nums2[i]);
                added[nums2[i]] = true;
            }
            i++;
        }
        vector<int> comm;
        for(int i=0; i<nums1.size(); i++){
            if(cnt1[nums1[i]] && cnt2[nums1[i]]){
                comm.push_back(nums1[i]);
            }
        }
        // for(auto x: ans1){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x: ans2){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x: comm){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        int ind = 0;
        while(ind<comm.size() && ans1.size()<nums1.size()/2){
            if(!added[comm[ind]]){
                ans1.push_back(comm[ind]);
                added[comm[ind]] = true;
            }
            ind++;
        }
        while(ind<comm.size() && ans2.size()<nums2.size()/2){
            if(!added[comm[ind]]){
                ans2.push_back(comm[ind]);
                added[comm[ind]] = true;
            }
            ind++;
        }
        return ans1.size()+ans2.size();
    }
};

/**
 * The 2 arrays has to be reduced to n/2 size. 
 * Thus create 2 arrays with n/2 sizes.
 * In the nums1 array if the element is there in nums1 and not in nums2 add it.
 * In the nums2 array if the element is there in nums2 and not in nums1 add it.
 * Finally find common elements in both the arrays and fill the empty space in 
 * The n/2 arrays.
 *
 * Time complexity : O(N)
 * Space complexity : O(N)
 */