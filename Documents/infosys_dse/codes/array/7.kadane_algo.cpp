/*
7. Kadane's Algorithm (Maximum Subarray Sum)Question:Given an integer array, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Concept (Optimized Approach - Kadane's Algorithm):Kadane's algorithm is a dynamic programming approach that runs in $O(N)$ time. As you iterate through the array, you keep a running tally of the current_sum. If at any point your current_sum drops below zero, it means the current sequence is only acting as a drag on any future elements, so you reset current_sum to 0. Simultaneously, you constantly update a max_sum variable whenever current_sum exceeds it.
*/

#include <iostream>
#include <vector>
#include <limits> // for minimum integer value
using namespace std;

int maxsumarray(vector<int>& nums){
    int maxsum = INT16_MIN;
    int current_sum = 0;

    for(int num : nums){
        current_sum+=num;
        if(current_sum>maxsum){
            maxsum = current_sum;
        }
        if(current_sum<0){
            current_sum = 0;
        }
    }
    return maxsum;
}

int main(){
    vector<int> nums {1,2,3,-2,5};
    int ans = maxsumarray(nums);
    cout<<ans;
}