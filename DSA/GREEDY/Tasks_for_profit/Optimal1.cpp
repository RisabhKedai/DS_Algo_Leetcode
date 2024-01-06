/*
* @Author: lenovo
* @Date:   2024-01-06 21:41:14
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-06 21:43:58
*/
/* This is the Task class definition

class Task {
public:
    int deadline, profit;
    Task(int deadline, int profit) {
        this->deadline = deadline;
        this->profit = profit;
    }
};
*/
 
bool comp(Task* a, Task* b){
  return a->profit > b->profit;
}

int getMaxProfit(vector<Task*> &tasks) {
	int maxd = 0;
	sort(tasks.begin(), tasks.end(), comp);
	for(int i=0; i<tasks.size(); i++){
		maxd = max(maxd, tasks[i]->deadline);
	}
	vector<int> ans(maxd+1, 0);
	for(int i=0; i<tasks.size(); i++){
		for(int j=tasks[i]->deadline; j>=1; j--){
			if(ans[j] == 0){
				ans[j] = tasks[i]->profit;
				break;
			}
		}
	}
	return accumulate(ans.begin(), ans.end(), 0);
}


/**
 *  The idea is to complete the given tasks in the decreasing order of their profits.
 *  Initialize a sequence array of size equal to the maximum possible deadline to store the sequence in which the tasks will be completed.
 *  Start from the task having the highest profit and assign it an unoccupied index in the sequence array while traversing from its deadline to 0 and store the profit in that index.
 *  Repeat the above step for all tasks in decreasing the order of their profits.
 *  Traverse the sequence array and add all the profits which will be the answer
 *  
 *  Analysis
 *  Time Complexity: O(n * Maximum Value of Deadline)
 *  Auxiliary Space Complexity: O(Maximum Value of Deadline)
 */