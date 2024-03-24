#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	Heap heap = new Heap("min");
	for(int i=0; i<n; i++) {
		int item;
		cin>>item;
		heap.push(item);
	}
	for(auto x : heap){
		cout<<x<<"\n";
	}
	return 0;
}