/*
6. Concatenate Two Arrays (Without Union)
Question:
Given two integer arrays, concatenate them into a single third array sequentially (append the second array to the end of the first array). Do not use set logic (like Union), meaning duplicates should be preserved.

Concept (Optimized Approach - Pre-allocated Array):
To avoid memory reallocation overhead, we create a new result array and pre-allocate its size to be exactly size_of_array1 + size_of_array2. Then, we simply loop through the first array to copy its elements, followed by a loop through the second array.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> concatinatearrays(vector<int>& arr1 , vector<int>& arr2){
    vector<int> result(arr1.size()+arr2.size());
    int index = 0;
    for(int num : arr1){
        result[index++] = num;
    }
    for(int num : arr2){
        result[index++] = num;
    }
    return result;
}

int main(){
    vector<int> arr1 = {1,2,3,4};
    vector<int> arr2 = {2,4,5,6,7};
    vector<int> ans = concatinatearrays(arr1,arr2);
    for(int num : ans){
        cout<<num<<" ";
    }
}