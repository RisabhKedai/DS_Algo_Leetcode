/*
* @Author: lenovo
* @Date:   2023-12-18 22:49:02
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-18 22:53:41
*/
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

using namespace std;

int min_steps(std::vector<int> nums) {
    sort(nums.begin(),nums.end(),greater<int>());
    int ans = 0;
    int i;
    int mi = nums[nums.size()-1];
    for(i=1; i<nums.size(); i++){
        if(nums[i] == mi){
            break;
        }
        if(nums[i] == nums[i-1]){
           continue;
        }else{
           ans+=i;
        }
    }
    ans += i;
    return ans;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<int> nums = get_words<int>();
    int res = min_steps(nums);
    std::cout << res << '\n';
}


/**
 * Sort the elements in reverse order. 
 * Start from the last of the maximum and 
 * keep reducing one one to make it equal to smaller ones. 
 * Now when the smaller ones become the maximum they also have the earlier biggest ones which became smaller. 
 * Thus the number of numbers need to be reduced will keep increasing, with each transition. 
 *
 * Time compexity : O(NlogN)
 * Space Complexity :O(1)
 * 
 */