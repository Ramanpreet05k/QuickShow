/*
Question:Given an unsorted array of integers, remove all duplicate elements and print only the unique elements in the order they were first encountered.
Concept (Optimized Approach - Hash Set):Using an unordered_set allows us to track which elements we have already seen in $O(1)$ average time. We iterate through the array; if the current element is not in our set, we print it (or add it to a result array) and then insert it into the set. If it is already in the set, we simply skip it.
*/


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void printuniqueelements(vector<int>& arr){
    unordered_set<int> seen;
    for(int num : arr){
        if(seen.count(num)==0){
            cout<<num<<" ";
            seen.insert(num);
        }
    }
    cout<<endl;
}

int main(){
    vector<int> nums = {1,2,2,3,3,4,4,5,6,6,7};
printuniqueelements(nums);
}

