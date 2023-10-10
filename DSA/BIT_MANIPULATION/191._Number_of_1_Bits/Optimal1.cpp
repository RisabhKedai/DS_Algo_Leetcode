/*
* @Author: lenovo
* @Date:   2023-09-26 20:39:47
* @Last Modified by:   lenovo
* @Last Modified time: 2023-09-26 20:57:42
*/
class Solution {
public:
    // APPROACH 4 - Using & operator
    // n &= (n-1)
    /** 
     * This works because doing n-1 brings the first 1 in the series near 0 so that the & then eliminates it.  
     * An example could be 2[10] - 1[01]. THe carry back just brings back the 1 to the end and emininates it. 
     * Another example could be 100(4) - 1(!) . This removes 1 from its position and brings it in front of zeroes.
     * The time complexity reduces to hamming weight.
     */
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n!=0){
            n &= n-1;
            ans++;
        }
        return ans;  
    }

    // APPROACH 5 - Using & operator
    // n -= n&(2's complement of n)
    /** 
     * This works because this also goes to all the 1's in the binary representation on N and remoes them
     * A numbers negative number is nothing but it's 2's complement.
     * 2's complement is nothing but 1's complement (inverting all the bits) and adding 1 to it.
     * Ex: N = 10010
     * 1s complement = 01101
     * 2s complement = 01101 + 1 = 01111. See how the +1 filled in the first place where there was 0. 
     * This place in actual is the first place where there was 1 in the original number N.
     * Now if we & N & (-N)[2's comp.] we get that first place as 1 and all other 0/ in this case:
     * 10010 & 01111 = 00010
     * This when subtracted from N removes one 1.
     */
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n!=0){
            n -= n &(-n);
            ans++;
        }
        return ans;  
    }
};

/**
 * Time complexity: O(Hamming_weight)
 * Space COmplexity: O(1)
 */