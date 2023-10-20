/*
* @Author: lenovo
* @Date:   2023-10-20 22:09:49
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-20 22:55:43
*/
#include <bits/stdc++.h>
using namespace std;

int apartmentHunting(vector<map<string,bool>>& blocks, vector<string>& queries){
	int n = blocks.size(); 
	vector<int> tot(n,0);
	for(auto query: queries){
        // cout<<query<<" ";
		vector<int> dist(n,INT_MAX);
		int leftind = -1;
		for(int i=0; i<n; i++){
            // cout<<leftind<<" ";
			dist[i] = min(abs(i-leftind),dist[i]);
			if(blocks[i][query]){
				leftind = i;
			}
		}
		int rightind = n;
		for(int i=n-1; i>=0; i--){
			dist[i] = min(abs(i-rightind),dist[i]);
			if(blocks[i][query]){
				rightind = i;
			}
		}
		for(int i=0; i<n; i++){
			tot[i] += dist[i];
		}
	}
	int minind = 0;
	for(int i=0; i<n; i++){
        // cout<<tot[i]<<" ";
		if(tot[minind] > tot[i]){
			minind = i;
		}
	}
	return minind;
}

int main() {
	int n;
	cin>>n;
	vector<map<string,bool>> blocks(n);
	for(int i=0; i<n; i++){
		int x; 
		cin>>x;
		for(int j=0; j<x; j++){
			string str;
			cin>>str;
			blocks[i][str] = true;
		}
	}
	int q;
	cin>>q;
	vector<string> queries(q);
	for(int i=0; i<q; i++){
		cin>>queries[i];
	}
	cout<<"Block : "<<apartmentHunting(blocks,queries);
	return 0;
}

/**
 * For each facility requirement traverse all the blocks from right to left
 * and left to right to find the nearest facility to each of the block. 
 * Finally sum the distances for each facility for a given block.
 * Find the block with minimum sum 
 *
 * Time complexity: O(n)
 * Space Complexity : O(nq)
 */