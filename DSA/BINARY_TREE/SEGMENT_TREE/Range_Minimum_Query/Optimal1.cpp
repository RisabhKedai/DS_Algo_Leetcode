/*
* @Author: lenovo
* @Date:   2023-11-07 23:09:31
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-07 23:11:52
*/

// Problem Link : https://practice.geeksforgeeks.org/problems/range-minimum-query/1

 int segTree[4*1001];
void build(int* segTree, int* arr, int ind, int st, int en) {
    if(st == en){
        segTree[ind] = arr[st];
        return;
    }
    int mid = (st+en)/2;
    build(segTree, arr, 2*ind + 1, st, mid);
    build(segTree, arr, 2*ind + 2, mid+1, en);
    segTree[ind] = min(segTree[2*ind + 1], segTree[2*ind + 2]);
}

/* The functions which 
builds the segment tree */
int *constructST(int arr[],int n)
{
  build(segTree, arr, 0, 0, n-1);
  return segTree;
}


int queryUtil(int *segTree, int ind, int st, int en, int l, int r) {

    if((l<=st) && (en<=r)){
        return segTree[ind];
    }
    if(r<st || en<l) return INT_MAX;
    int mid = (st+en)/2;
    return min(
        queryUtil(segTree, 2*ind + 1, st, mid, l, r),
        queryUtil(segTree, 2*ind + 2, mid+1, en, l, r)
    );
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b)
{
    return queryUtil(st,0, 0, n-1, a, b);
}

/**
 * Simple Segment tree implementation
 *
 * Time complexity : O(logN) to build + O(logN) to query
 * Space Complexity : O(4*n)
 */