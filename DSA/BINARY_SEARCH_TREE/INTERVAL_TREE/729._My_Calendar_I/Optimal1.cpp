/*
* @Author: lenovo
* @Date:   2024-01-25 23:16:52
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-25 23:19:09
*/


class MyCalendar {
private:
    vector<pair<int,int>> intervals;
public:
    MyCalendar() {
       this->intervals = vector<pair<int,int>>();
    }
    
    bool book(int start, int end) {
        int n = this->intervals.size();
        if(n==0){
            this->intervals.push_back({start, end});
            return true;
        }
        int beg = 0;
        int en = n-1;
        int ans = -1;
        while(beg<=en) {
            int mid = (beg+en)/2;
            if(this->intervals[mid].first < start){
                ans = mid;
                beg = mid+1;
            }else{
                en = mid-1;
            }
        }
        if(ans == -1){
            if(start<this->intervals[0].first && end<=this->intervals[0].first){
                this->intervals.push_back({start, end});
                sort(this->intervals.begin(), this->intervals.end());
                return true;
            }else{
                return false;
            }
        } else {
            if(this->intervals[ans].second<=start){
                if(ans==n-1){
                    this->intervals.push_back({start, end});
                    sort(this->intervals.begin(), this->intervals.end());
                    return true;
                }else if(this->intervals[ans+1].first >= end){
                    this->intervals.push_back({start, end});
                    sort(this->intervals.begin(), this->intervals.end());
                    return true;
                } else{ 
                    return false;
                }
            }else{
                return false;
            }
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

/**
 * Make a sorted list of intervals and check if the new range fits in between the intervals
 * Use binary search to search for the position where it can be inserted . 
 * Sort the list after inserting the new range
 *
 * Time complexity : O(NlogN)
 * Space complexity : O(N) 
 */