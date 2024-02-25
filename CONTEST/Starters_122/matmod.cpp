/*
* @Author: lenovo
* @Date:   2024-02-25 16:14:13
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-25 16:15:57
*/

#include <bits/stdc++.h>
using namespace std;

int fact(int x, int mod){
    int f=1;
    for(int i=1; i<=x; i++){
        f *= i;
        f %= mod;
    }
    return f;
}

int main() {
    int mod = 1e9 + 7; 
    int test;
    cin>>test;
	for(int t=0; t<test; t++){
	    int n;
	    cin>>n;
	    vector<vector<int>> mat(n,vector<int>(n));
	    for(int i=1; i<=n; i++){
	        for(int j=1;j<=n; j++){
	            cin>>mat[i-1][j-1];
	        }
	    }
	    int mn = n*(n+1)/2;
	    int d1 = (n * (n-1)) /2;
	    int d2 = mn;
	    int diags=0;
	    for(int i=0; i<n; i++){
	        if(mat[i][i]==0){
	            diags++;
	        } else if(d1<=mat[i][i] && mat[i][i]<=d2){
	            continue;
	        }else{ 
	            diags=-1;
	            break;
	        }
	    }
	    if(diags==-1){
	        cout<<0<<endl;
	        continue;
	    }
	   // cout<<d1<<" "<<d2<<endl;
	    int cnt = 0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(mat[i][j]==0 && mat[j][i]==0){
                    cnt ++;
                } else if(
                    (mat[i][j]==0 && (d1>mat[j][i] || mat[j][i]>d2)) ||
                    (mat[j][i]==0 && (d1>mat[i][j] || mat[i][j]>d2)) ||
                    (mat[i][j]%mn  == mat[j][i]%mn)
                ) {
                    continue;
                } else  {
                    // cout<<i<<" "<<j<<endl;
                    cnt=-1;
                    break;
                }
	        }
	    }
	   // cout<<diags<<" "<<cnt<<endl;
	    if(cnt==-1){
	        cout<<0<<endl;
	        continue;
	    }
	    long long ans = pow(2,cnt);
	    ans %= mod;
	    ans *= fact(cnt,mod);
	    ans %= mod;
	    ans *= fact(diags,mod);
	    ans %= mod;
	    cout<<ans<<endl;
	}
	return 0;
}


/**
 * Mn is n*(n+1))/2 why?
 * Reason: try with Mn higher than this number, u will find a pair of a[i][j] and a[j][i] such that abs(a[i][j]-a[j][i])<Mn. In that case a[i][j]%Mn !=a[j][i]%Mn.
 * but, with Mn as n*(n+1))/2 we can find non diagonal pairs a[i][j] a[j][i] as follows
 * 
 * (1, l+1), (2, l+2),......(l, n^2),
 * 
 * here l=(n*(n-1))/2
 * 
 * let k=Mn
 * 
 * the diagonals should have only numbers in the range l+1 to l+n
 * if a[i][j] is x and x<=l then a[j][i] should be x+k if a[i][j] is x and x>l+n then a[j][i] should be x-k
 * non diagonals elements should not lie in the range [l+1, l+n]
 * thus find the number of pairs (i,j), (j,i) such that a[i][j]=a[j][i]=0. call them as empty_pairs
 * find the number of empty diagonal elements. call it empty_diagonals
 * then the answer is
 * 
 * (2^(empty_pairs))((empty_pairs)!)(empty_diagonals!)
 * 
 * https://www.codechef.com/viewsolution/1046499438
 * Time complexity : O(N^2)
 * Space complexity : O(1)
 */