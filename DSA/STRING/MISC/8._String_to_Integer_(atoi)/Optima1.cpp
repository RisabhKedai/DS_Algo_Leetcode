/*
* @Author: lenovo
* @Date:   2024-03-13 01:59:10
* @Last Modified by:   lenovo
* @Last Modified time: 2024-03-13 01:59:49
*/

class Solution {
public:
    bool notDigit(char x){
        return '0'>x || '9'<x;
    }
    int myAtoi(string s) {
        int mult = 1;
        int ind = 0;
        while(ind<s.length() && (s[ind]==' ')) ind++;
        if(s[ind]=='-' || s[ind]=='+'){
            if(s[ind]=='-') mult*=-1;
            ind++;
        }
        long ans = 0;
        while(ind<s.length() && !notDigit(s[ind])){
            cout<<ind<<" "<<s[ind]<<endl;
            ans *=10;
            ans += s[ind]-48;
            ind++;
            if(ans>INT_MAX){
                break;
            }
        }
        if(ans*mult < INT_MIN){
            return INT_MIN;
        }
        if(ans*mult > INT_MAX){
            return INT_MAX;
        }
        return ans*mult;
    }
};

/*
Crude implementation
Time complexity : O(N)
Space complexity : O(1)
 */