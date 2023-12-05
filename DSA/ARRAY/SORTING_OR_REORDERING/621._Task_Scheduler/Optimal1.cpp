/*
* @Author: lenovo
* @Date:   2023-12-05 00:40:26
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-05 00:43:10
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int>mp(26,0);

        for(char i:tasks){
            mp[i-'A']++;  // count the number of times a task needs to be done
        }   
        for(int i=0;i<26;++i){
            if(mp[i]) 
            pq.push(mp[i]);
        }

        int time=0; // stores the total time taken 
        while(!pq.empty()){
            vector<int>remain;
            int cycle=n+1;  // n+1 is the CPU cycle length, if n is the cooldown period then after a task A there will be n more tasks. Hence n+1.

            while(cycle and !pq.empty()){
                int max_freq=pq.top(); // the task at the top should be first assigned the CPU as it has highest frequency
                pq.pop();
                if(max_freq>1){ // task with more than one occurrence, the next occurrence will be done in the next cycle 
                    remain.push_back(max_freq-1); // add it to remaining task list
                }
                ++time; 
                --cycle; 
            }

            for(int count:remain){
                pq.push(count); 
            }
            if(pq.empty())break; // if the priority queue is empty than all tasks are completed and we don't need to include the idle time
            time+=cycle; // this counts the idle time 
        }
        return time;
    }
};

/**
 * Reference : https://leetcode.com/problems/task-scheduler/solutions/3280549/full-explanation-using-priority-queue-and-formula-based-approach/
 *
 * First count the number of occurrences of each task and store that in a map/vector.
 * Then push the count into a priority queue, so that the maximum frequency task can be accessed and completed first.
 * Then until all tasks are completed (i.e the priority queue is not empty):
 * 	intialise the cycle length as n+1. n is the cooldown period so the cycle will be of n+1 length.
 * 	Example: for ['A','A','A','B','B'] and n=2,
 * 	the tasks can occur in the following manner:
 * 	[A B idle]->[A B idle]->[A]. See here each cycle is n+1 length long, only then A can repeat itself.
 * 	for all elements in the priority queue, until the cycle length is exhausted, pop the elements out of the queue and 
 * 	if the task is occurring more than once then add it to the remaining array (which stores the remaining tasks).
 * 	This means that we are completing that task once in this cycle.So keep counting the time.
 * 	Then, add the occurrence of tasks back to the priority queue.
 * 	Add the idle time into the time count.
 * 	
 * Idle time is the time that was needed in the cycle because no task was available. 
 * It is the remaining cycle length in our algorithm. Idle time should be only added if the priority queue is empty (i.e all tasks are completed).
 *
 * Time Complexity : O(NlogN)
 * Space Complexity : O(N)
 */