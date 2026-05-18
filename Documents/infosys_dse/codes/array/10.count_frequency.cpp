/*
Question:Given an array of integers, count how many times each element appears and print the element alongside its frequency.

Concept (Optimized Approach - Hash Map):The most efficient way to track frequencies is by using a Hash Map (unordered_map). A hash map allows us to store key-value pairs where the "key" is the number from the array and the "value" is its running count. As we iterate through the array, we look up each number in the map and increment its count in $O(1)$ average time. Finally, we iterate through the map to print the results.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void printelementfrequencies(vector<int>& nums){
    unordered_map<int,int> freqmap ;
    for(int num : nums){
        freqmap[num]++;
    }

    for(auto const& pair : freqmap){
        cout<< "Element : "<<pair.first<<" | frequency : "<<pair.second<<endl;
    }


}

int main(){
    vector<int> nums = {1,2,2,3,3,5,5,6,7,8,3,5,7,5,3,1,1,1};
    printelementfrequencies(nums);
}