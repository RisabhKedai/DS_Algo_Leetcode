/*
* @Author: lenovo
* @Date:   2024-01-13 13:58:36
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-13 14:12:18
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin>>test;
	for(int t=0; t<test; t++){
	    long long n;
	    cin>>n;
	    if(n%2!=0){
	        cout<<((long long)((sqrtl(n))+1)/2)<<endl;
	    }else{
	        cout<<((long long)((sqrtl(n)))/2)<<endl;
	    }
	}
	return 0;
}


/**
 * For all the integers product to be odd each integer has to be odd
 * 
 * Sum of N off numbers is given by :
 * 1 + 3 + 5 + 7 ... (2n-1) = n^2 
 *
 * Thus for a given n the maximum number of distinct integers in the set is sqrt(n)
 *
 * Odd n will have odd number of intergers in the maximum set
 * Even n will have even number of intergers in the minimum set
 *
 * For a given set of x odd integers the number of sets with odd set of numbers present that can be prepared is  (x+1)/2
 *
 * Reference : https://www.codechef.com/viewsolution/1039659423
 * 
 * Time complexity : O(1)
 * Space complexity : O(1)
 */