/*
* @Author: lenovo
* @Date:   2024-03-11 19:41:43
* @Last Modified by:   lenovo
* @Last Modified time: 2024-03-11 19:43:50
*/

class Solution {
public:
    bool isRobotBounded(string ins) {
        int x=0, y=0;
        char dirs[] = {'N','E','S','W'};
        int d = 0;
        for(int i=0; i<ins.length(); i++){
            if(ins[i]=='G'){
                if(dirs[d]=='N'){
                    y++;
                }else if(dirs[d]=='E'){
                    x++;
                }else if(dirs[d]=='W'){
                    x--;
                }else{
                    y--;
                }
            }else if(ins[i]=='L'){
                d--;
                if(d<0){
                    d = 3;
                }
            }else{
                d+=1;
                d%=4;
            }
            cout<<x<<" "<<y<<" "<<dirs[d]<<endl;
        }
        return ((x == 0 && y==0) || (d!=0));
    }
};

/*
{
	"Approach" : "
		Calculate the final vector of how the robot travels after executing,
		all instructions once - it consists of a change in position plus a change in direction.
		The robot stays in the circle if and only if (looking at the final vector),
		it changes direction (ie. doesn't stay pointing north), or it moves 0.
	",
	"Time complexity" : "O(N)",
	"Space Complexity": "O(1)"
}
*/
