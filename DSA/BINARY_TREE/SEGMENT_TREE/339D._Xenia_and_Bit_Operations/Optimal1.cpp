/*
* @Author: lenovo
* @Date:   2023-11-08 01:15:02
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-12 00:30:59
*/

#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
private:
	int *segTree;
	int siz;
	void buildTree(int *arr, int st, int en, int ind);
public:
	void update(int ind, int idx, int val, int st, int en);
	int query(int ind, int st, int en, int l, int r);
	void display();
	SegmentTree(int *arr, int n){
		siz = 4*n;
		segTree = new int[siz]();
		// cout<<siz<<"\n";
		buildTree(arr, 0, n-1, 0);
	}
};

void SegmentTree::buildTree(int *arr, int st, int en, int ind){
	if(st == en){
		segTree[ind] = arr[st];
		return;
	}
	int mid = (st + en)/2;
	buildTree(arr, st,mid,2*ind + 1);
	buildTree(arr, mid+1,en,2*ind + 2);
	int gap = en - st + 1;
	int cnt = 0;
	while(gap){
		cnt++;
		gap/=2;
	}
	if(cnt%2==0){
		segTree[ind] = segTree[2*ind  + 1] | segTree[2*ind + 2];
	}else{
		segTree[ind] = segTree[2*ind  + 1] ^ segTree[2*ind + 2];
	}
}

void SegmentTree::update(int ind, int idx, int val, int st, int en){
	if(st == en && st == idx){
		segTree[ind] = val;
		return;
	}
	if(en<idx || st>idx){
		return;
	}
	int mid = (st+en)/2;
	update(2*ind + 1, idx, val, st, mid);
	update(2*ind + 2, idx, val, mid+1, en);
	int gap = en - st + 1;
	int cnt = 0;
	while(gap){
		cnt++;
		gap/=2;
	}
	if(cnt%2==0){
		segTree[ind] = segTree[2*ind  + 1] | segTree[2*ind + 2];
	}else{
		segTree[ind] = segTree[2*ind  + 1] ^ segTree[2*ind + 2];
	}
}

int SegmentTree::query(int ind, int st, int en, int l, int r){
	if(en<l || st>r){
		return 0;
	}
	if(st==en || (l<=st && en<=r)){
		return segTree[ind];
	}
	int mid = (st + en)/2;
	return query(2*ind + 1, st, mid, l, r) | query(2*ind + 2, mid+1, en, l, r);
}

void SegmentTree::display() {
	for(int j=0; j<siz; j++){
		cout<<segTree[j]<<" ";
	}
	cout<<"\n";
}

int main(int argc, char const *argv[])
{
	int n,q;
	cin>>n>>q;
	n = pow(2,n);
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	SegmentTree sT = SegmentTree(arr,n);
	for(int i=0; i<q; i++){
		int ind, val;
		cin>>ind>>val;
		sT.update(0,ind-1,val,0,n-1);
		// sT.display();
		cout<<sT.query(0,0,n-1,0,n-1)<<"\n";
	}
	return 0;
}

/**
 * Codeforces Problem link : https://codeforces.com/contest/339/problem/D
 * Referred solution link : https://codeforces.com/contest/339/submission/232356768
 *
 * Approach : The basic solution is a segment tree.
 * Each query updates an index, thus calling the update operation for that index.
 * After that the query function of the segment tree is used to get the value from the segment tree,
 * for the total range i.e., 0 to n-1 index.
 *
 * But the catch is that the or and xor operations should alternate on each level. 
 * So if a,b, and c are 3 nodes in the tree, and a b are lower level nodes then first a|b should happen
 * resulting in x and then x^c should happen. 
 *
 * To attain this operation for a given range p to q we first check the number of nodes in p to q.
 * Lets say there are 5 nodes [1,2,3,4,5]. Thus first 1 or 2 will happen (giving d), then 3 or 4 (giving e)
 * then d^e will happpen giving f and finally f|5 will happen. 
 *
 * After we get the number of nodes we check the level this operation is happening at. 
 * Which we can get by log(number of nodes). It is an even level then or happens otherwise xor happens. 
 * To attain this we subtract 
 *
 * Time Complexity : O(logN^2)
 * Space complexity : O(4*n)
 */