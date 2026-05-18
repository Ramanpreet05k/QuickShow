/*
1. Move All Zeros to One EndQuestion:Given an integer array, move all 0s to the end of it while maintaining the relative order of the non-zero elements. This must be done in-place without making a copy of the array.

Concept (Optimized Approach - Two Pointers):We can solve this in a single pass ($O(N)$ time) using the Two Pointer technique. We maintain a pointer called insertPos which keeps track of where the next non-zero element should be placed. As we iterate through the array with a second pointer (i), whenever we find a non-zero element, we swap it with the element at insertPos and move insertPos forward. This naturally pushes all the zeros to the end.
*/

#include <iostream>
#include <vector>
using namespace std;

void movezeroes(vector<int>& nums){
    int insertpos = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            int temp = nums[insertpos];
         nums[insertpos] = nums[i];
         nums[i] = temp;   
         insertpos++;
        }
    }
}

int main(){
    vector<int> nums = {1,2,0,3,0,9,0,5,7};
    movezeroes(nums);
    for(int num : nums){
        cout<<num<<" ";
    }
}