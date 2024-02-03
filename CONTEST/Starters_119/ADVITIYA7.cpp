/*
* @Author: lenovo
* @Date:   2024-02-03 13:34:51
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-03 13:37:55
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> primeFactorize(int x){
    int i=2;
    vector<int> f;
    int temp=x;
    while(i*i <= temp){
        int cnt = 0;
        while(x%i==0){
            x/=i;
            cnt++;
        }
        if(cnt!=0){
            f.push_back(cnt);
        }
        i++;
    }
    if(x>1)
    f.push_back(1);
    return f;
}

int main() {
    int mod = 1e9 + 7;
    int test;
    cin>>test;
	for(int t=0; t<test; t++){
	    int x,q;
	    cin>>x>>q;
	    vector<int> as = primeFactorize(x);
	    while(q--){
	        int p;
	        cin>>p;
	        int ans = 1;
	        for(auto a: as) {
	            if(a<=1){
	                continue;
	            }
	           // cout<<a<<" ";
	            ans *= (a>1)+(a%p==0);
	            ans %= mod;
	        }
	       // cout<<endl;
	       if(p==1){
	           cout<<1<<endl;
	       }else
    	        cout<<ans<<endl;
	    }
	}
	return 0;
}



/**
 * given gcd(x,y)^p=lcm(x,y)
 * we know that lcm(x,y)= x*y/gcd(x,y)
 * substitute in given equation,we get
 * gcd(x,y)^(p+1)=x*y ----->(1)
 * now, x can be witten as x=p1^x1 * p2^x2 ........ where p1,p2..... are prime
 * similarly take y=p1^y1 * p2^y2 .....
 * 
 * now put x,y in equation 1,we get on simplifiying (p+1)min(x1,y1)=x1+y1 ---->(2) and 
 * (p+1)min(x2,y2)=x2+y2 ---->(3) and .......
 * 
 * now form equation 2 and 3 we get 4 possible equations px1=x2 or px2=x1 and py1=y2 or py2=y1
 * so it implies if x1%p==0 then x2 can be p*x1 and p/x1-->2 possibilitis similarly check modulo which each factor power if divisible multiply total answer by 2. (refer given test case for better understanding)
 * 
 * Time Complexity: O(root(x) + (q*number_of_prime_factors))
 * Space complexity: O(root(x))
 */