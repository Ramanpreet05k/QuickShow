/*
5. Find the Remaining Element After Removing Duplicate PairsQuestion:Given an array of integers where every element appears exactly twice except for one element which appears exactly once, find that single isolated element.
Concept (Optimized Approach - Bit Manipulation / XOR):This is a classic trick problem. The most optimized way uses the XOR (^) bitwise operator.Two rules of XOR make this work:$A \oplus A = 0$ (XORing a number by itself cancels it out to zero).$A \oplus 0 = A$ (XORing a number with zero yields the number).If we XOR all the numbers in the array together, every duplicate pair will cancel each other out to 0. The only number left standing will be the unique element.
*/

#include <iostream>
#include <vector>
using namespace std;

int findsingleelem(vector<int>& arr){
    int result = 0;
    for(int num : arr){
        result^=num;
    }
    return result;
}

int main(){
    vector<int> nums = {1,1,2,2,3,4,4,5,5};
    int ans = findsingleelem(nums);
    cout<<ans;
} 