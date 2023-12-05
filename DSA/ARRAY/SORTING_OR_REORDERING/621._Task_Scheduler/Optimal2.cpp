/*
* @Author: lenovo
* @Date:   2023-12-05 00:43:42
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-05 22:30:33
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        int max_freq=0, count_maxfreq=0, sz=tasks.size();
        for(char i:tasks){
            mp[i-'A']++;  // count the number of times a task needs to be done
            if(mp[i-'A']>max_freq){
                max_freq=mp[i-'A']; // find maximum frequency 
            }
        }   
        for(int i=0;i<26;i++){
            if(mp[i]==max_freq) count_maxfreq++; // number of tasks having maximum frequency
        }
        // cout<<count_maxfreq<<" "<<max_freq<<" "<<(n+1)<<endl;
        int time= (max_freq-1)*(n+1) + count_maxfreq; // total time taken to complete all tasks
        return max(time,sz);
        // extra tasks will be left in case where each cycle is filled by max freq elements.
        // and since we are calculating the time based on max freq elements, other are getting left out.
    }
};

/**
 * Let's understand this with an example:
 * 
 * tasks= ['A','A','A','B','B','B','C','D'], n=2
 * 
 * Maximum frequency=3 and maximum occurring task= A,B
 * Here our possible solution is:
 * ['A'->'B'->'C'] -> ['A','B','D'] ->['A','B']
 * total time: 3+3+2=8
 * 
 * Notice something: The cycle A->B->other_task is repeating 2 (maximum frequency-1) times and then A->B occurs.
 * A and B are the maximum frequency elements which are making the cycle of length 3(n+1).
 * We can say that
 * 
 * total time= (cycle length)*(maximum frequency-1) + number maximum frequency tasks that are left  
 * i.e total time=(n+1)*(max_freq-1)+count_maxfreq_task
 * 
 * In scenarios where the total time is less than the number of tasks, the minimum time required would be the number of tasks itself.
 *
 * Time Complexity : O(N)
 * Space Complexity : O(1)
 */