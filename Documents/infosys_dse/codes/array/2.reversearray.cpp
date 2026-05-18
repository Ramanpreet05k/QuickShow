/*
2. Reverse an ArrayQuestion:Given an array of integers, reverse the order of its elements in-place without allocating extra space for another array.
Concept (Optimized Approach - Two Pointers):To reverse an array efficiently in $O(N)$ time and $O(1)$ space, use the Two Pointer technique. Place one pointer at the beginning (start = 0) and one at the end (end = size - 1). Swap the elements at these two positions. Then, move the start pointer forward and the end pointer backward. Repeat this until the pointers meet or cross each other.  
*/

#include <iostream>
#include <vector>
using namespace std;

void reversearray(vector<int>& arr){
    int start = 0;
    int end = arr.size()-1;
    while(start<end){
        int temp = arr[start];
        arr[start]= arr[end];
        arr[end]=temp;

        start++;
        end--;
    }

}

int main(){
    vector<int> nums = {1,2,3,4,5};
    cout<<"Original array : "<<endl;
    for(int i = 0 ; i<nums.size();i++){
        cout<<nums[i];
    }
    cout<<"Reversed Array : "<<endl;
    reversearray(nums);
     for(int i = 0 ; i<nums.size();i++){
        cout<<nums[i];
    }

}
