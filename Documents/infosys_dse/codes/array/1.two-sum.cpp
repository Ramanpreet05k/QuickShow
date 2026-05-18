/* 
   1. Two Sum ArrayQuestion:Given an array of integers and an integer target, return the indices of the two numbers such that they add up to the target. You may assume that each input would have exactly one solution, and you may not use the same element twice.
   
   Concept (Optimized Approach - Hash Map):The brute-force way is to use nested loops ($O(N^2)$), but we can optimize this to $O(N)$ time complexity using a Hash Map (unordered_map). As we iterate through the array, we calculate the complement needed to reach the target (target - current_element). We check if this complement already exists in our map. If it does, we have found our pair! If not, we store the current element and its index in the map for future checks.
*/



#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twosum(vector<int>& nums, int target){
   unordered_map<int,int> numsMap;
   for(int i=0;i<nums.size();i++){
      int complement = target - nums[i];
      if(numsMap.count(complement)){
         return {numsMap[complement],i};
      }
      numsMap[nums[i]]=i;
   }
   return {};
}

int main(){
   int target = 5;
   vector<int> nums = {1,2,3,7};
   vector<int> ans = twosum(nums,target);
   for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<endl;
   }

}