/*
* @Author: lenovo
* @Date:   2023-11-20 01:09:02
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-20 01:13:43
*/

class SegmentTree {
private:
    int n;
    vector<int> heights;
    vector<int> tree;
    int queryUtil(int x, int st, int en, int ind, int l, int r){
        // cout<<ind<<"\n";
        // cout<<"st="<<st<<" "<<"en="<<en<<endl;
        // cout<<"l="<<l<<" "<<"r="<<r<<endl;
        // cout<<"-----------\n";
        if(r<st || l>en){
            return -1;
        }
        if(l==r){
            return heights[tree[ind]]>x?tree[ind]:-1;
        }
        if(heights[tree[ind]]<=x){
            return -1;
        }
        // if(st<=l && r<=en){
        int mid = (l+r)/2;
        int lh = queryUtil(x, st, en, 2*ind +1, l, mid);
        if(lh != -1)
            return lh;
        int rh = queryUtil(x, st, en, 2*ind + 2, mid+1, r);
        return rh;
        // }
    }
public:
    SegmentTree(vector<int> heights){
        this->heights = heights;
        n = heights.size();
        tree = vector<int>(4*n);
        buildTree(0,0,n-1);
        // this->display();
    }
    void buildTree(int ind, int st, int en){
        if(st == en){
            this->tree[ind] = st;
            return;
        }
        int mid = (st+en)/2;
        buildTree(2*ind + 1, st, mid);
        buildTree(2*ind + 2, mid+1, en);
        if(this->heights[this->tree[2*ind + 1]] >= this->heights[this->tree[2*ind + 2]]){
            this->tree[ind] = this->tree[2*ind + 1];
        } else {
            this->tree[ind] = this->tree[2*ind + 2];
        }
        // cout<<ind<<"->"<<st<<" "<<en<<" "<<tree[ind]<<endl;
    }
    int query(int x, int st, int en){
        int ans =  queryUtil(x, st, en, 0, 0, n-1);
        // cout<<"============================\n";
        return ans;
    }

    void display(){
        for(auto x : tree){
            cout<<x<<" ";
        }
    }
};
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = heights.size();
        SegmentTree segTree = SegmentTree(heights);
        for(auto query: queries){
            int a = min(query[0],query[1]);
            int b = max(query[0],query[1]);
            if(a==b || heights[a]<heights[b]){
                ans.push_back(b);
                continue;
            }
            int ind = b;
            int ma = max(heights[a], heights[b]);
            ans.push_back(segTree.query(ma,ind+1,n-1));
        }
        return ans;
    }
};

/**
 * First determine the relation between alice and bob heights. Assuming alice is on a smaller index always, 
 * Alice can only move right. If bob is on a building of more height than Alice then Alice will go to bob buidling straight away. 
 *
 * If not find the minimum index in the range(bob index + 1, n-1) such that the height is more than maximum of alice and bob heights. 
 * This can be done using segment tree query.
 * Refer to the solution : 
 * https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/solutions/4305120/video-explanation-journey-from-linear-search-to-binary-search-a-interesting-follow-up/
 *
 * Time Complexity : O(Q*(log(n)))
 * Space Complexity : O(4*n + n);
 */