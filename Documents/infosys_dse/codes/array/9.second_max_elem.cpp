/*
2. Find the Second Maximum ElementQuestion:Given an array of integers, find the second largest distinct element. If the array has fewer than two distinct elements, handle it appropriately (usually by returning a minimum value or an error flag).

Concept (Optimized Approach - Single Pass Tracker):The brute-force way is to sort the array ($O(N \log N)$), but we can do this in $O(N)$ time by traversing the array exactly once. We maintain two variables: firstMax and secondMax. As we iterate through the array:If the current number is greater than firstMax, it becomes our new firstMax, and the old firstMax gets demoted to secondMax.If the current number is less than firstMax but greater than secondMax, we simply update secondMax.
*/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int findsecondmax(vector<int>& nums){
    int firstmax = INT_MIN;
    int secondmax = INT_MIN;
    for(int num : nums){
        if(num>firstmax){
            secondmax = firstmax;
            firstmax = num;
        }
        else if(num> secondmax && num<firstmax){
            secondmax = num;
        }
    }
    return secondmax;
}

int main(){
    vector<int> nums = {1,2,3,7,8,5};
    int ans = findsecondmax(nums);
    cout<<ans;
}