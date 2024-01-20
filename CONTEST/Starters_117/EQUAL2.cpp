/*
* @Author: lenovo
* @Date:   2024-01-20 16:10:41
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-20 16:36:29
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin>>test;
	for(int t=0; t<test; t++){
	    int a,b;
	    cin>>a>>b;
	    if(a==b){
	        cout<<0<<endl;
	    }else{ 
	        int diff = abs(a-b);
	        if(diff%2){
	            long long st = -1;
	            long long beg = 1;
	            long long end = 1e9;
	            while(beg<=end){
	                long long mid = (beg+end)/2;
	               // cout<<mid<<" ";
	                if((mid*(mid+1))/2 < diff){
	                    beg = mid+1;
	                }else{
	                    st = mid;
	                    end = mid-1;
	                }
	            }
	            while(((st*(st+1))/2)%2==0){
	                st+=1;
	            }
	            cout<<st<<endl;
	        }else{
                long long st = -1;
	            long long beg = 1;
	            long long end = 1e9;
	            while(beg<=end){
	                long long mid = (beg+end)/2;
	               // cout<<mid<<" ";
	                if((mid*(mid+1))/2 < diff){
	                    beg = mid+1;
	                }else{
	                    st = mid;
	                    end = mid-1;
	                }
	            }
	            while(((st*(st+1))/2)%2!=0){
	                st+=1;
	            }
	            cout<<st<<endl;
	        }
	    }
	}
	return 0;
}


/**
 * Consider a and b. The difference is |a-b|.
 * This is supposed to be 0.
 * To make it zero we can add / subtract a number to a or b. 
 * basically means we can add the odd ones to the smaller or bigger and subtract evens from bigger or smaller
 * among a and b
 *
 * Note this means that if operations done on correct numbers any operation can add / subtract value to the diff.
 *
 * Thus the diff can be represented as diff <= 1 + 2 + 3 +.. + st
 * where st being a minimum number of steps to be done such that sum(1..st) >= diff
 *
 * Now note that the sum till st might and most probably will exeed diff.
 * But the fact being that we can always turn some positive signs to negative (add to sub)
 * to reduce the sum to diff.
 *
 * For example 
 * diff = 11
 * st = 5
 * diff <= 1+2+3+4+5 (sum = 15)
 * which is exceeding by 4
 * Now I can just turn +2 to -2 Such that the sum is now
 * 1 - 2 + 3 + 4 + 5 = 11
 * 
 * Turning the symbol + to - was equivalent to subtracting 2 times 2 (4) from 2. 
 * If I want to turn symbol of 3 I need to subtract 6 from 3. 
 *
 * Meaning I'll always subtract an even number from the sum
 *
 * In this case the sum was odd(15) and the value to be reached was 11 which was also odd. 
 * So I was able to subtract even number from it and reach the answer.
 *
 * In case the sum was odd but the answer was supposed to be even.
 * Ex : diff = 12
 * st = 5 
 * Sum = 15
 * In this case I cannot find an even number which when subtracted from 15 will give 12.
 *
 * Now I need to make the sum even such that even minus even gives even.
 * So increase st to 7.
 * st = 28.
 * Diff = 12
 * I need to reduce it by 16. So just turn the symbols of 7 and 1
 *
 * -1+2+3+4+5+6-7 = 12
 *
 * The value of St is the number of steps.
 *
 * Note the initial st can be found using binary search. 
 * 
 * Time complexity : O(logN)
 * Space complexity : O(1)
 */