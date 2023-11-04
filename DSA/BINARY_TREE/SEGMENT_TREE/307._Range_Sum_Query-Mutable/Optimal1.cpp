/*
* @Author: lenovo
* @Date:   2023-11-05 00:12:56
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-05 00:17:33
*/

class NumArray {
private:
vector<int> arr;
vector<int> nums;
public:
    void build(vector<int>& nums, int ind, int st, int en){
        if(st>en || st>=nums.size()){
            return;
        }
        if(st == en){
            arr[ind] = nums[st];
            return;
        }
        int mid = (st+en)/2;
        build(nums,2*ind + 1,st,mid);
        build(nums, 2*ind + 2,mid+1,en);
        arr[ind] = arr[2*ind + 1] + arr[2*ind + 2]; 
    }
    NumArray(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        arr = vector<int>(4*n, 0);
        build(nums,0,0,n-1);

    }
    void update_util(int st, int en,int index, int diff, int ind){
        if(st==en && st==index){
            arr[ind]+= diff;
            return;
        } else if(st<=index && index<=en){
            arr[ind] += diff;
        }else{
            return;
        }
        if(st>en){
            return;
        }
        int mid = (st+en)/2;
        update_util(st,mid,index,diff,2*ind + 1);
        update_util(mid+1,en,index,diff,2*ind + 2);
    }
    void update(int index, int val) {
        int n = nums.size();
        update_util(0,n-1,index,val - nums[index],0);
        nums[index] = val;
    }
    int sum_util(int ind, int left, int right, int st, int en){
        if(left<=st && en<=right){
            return arr[ind];
        }
        if(en<st || st>right || en<left){
            return 0;
        }
        int mid = (st+en)/2;
        return sum_util(2*ind + 1, left, right, st, mid) + 
        sum_util(2*ind + 2, left, right, mid+1, en);
    }
    int sumRange(int left, int right) {
        int n = nums.size();
        int ans = sum_util(0,left,right,0,n-1);
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

/**
 * Segment Tree is used to solve the problem.
 * Reference Blog : https://www.codingninjas.com/studio/library/segment-tree-428
 * Reference Video : https://youtu.be/-dUiRtJ8ot0?si=jpjYKGpbFP8bG9BU
 *
 * Time Complexity : O(logN)
 * Space Complexity : O(4*n)
 */