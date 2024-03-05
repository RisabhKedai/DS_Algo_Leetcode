/*
* @Author: lenovo
* @Date:   2024-03-05 07:28:46
* @Last Modified by:   lenovo
* @Last Modified time: 2024-03-05 07:41:56
*/

class Solution {
public:
    string convertToTitle(int col) {
        int x = col;
        string ans="";
        while(x>0){
            // cout<<x<<endl;
            if(x%26 == 0){
                ans = "Z"+ans;
                x /= 26;
                x--;
                continue;
            }
            ans = (char)(64 + x%26) + ans;
            x/=26;
        }
        return ans;
    }
};

/*
{
	Apporach : "Treat the number as decimal and derive the 26-nary number of it. There is just a edge case that when x/26 is zero it means it will be Z so accordingly handle that case"
	Time complexity : "O(log(N,26))",
	Space complexity : "O(1)"
}*/
