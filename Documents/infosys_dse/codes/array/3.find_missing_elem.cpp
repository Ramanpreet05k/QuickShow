/*
Question:Given an array containing $N-1$ distinct numbers taken from the range $1$ to $N$, find the one number that is missing from the array.
Concept (Optimized Approach - Mathematical Sum):The sum of the first $N$ natural numbers can be found using the formula $\frac{N \times (N + 1)}{2}$. By calculating this expected sum and then subtracting the actual sum of all the elements currently present in your array, the remainder will be the missing number.(Note: For massive arrays where integer overflow is a risk, XOR bit manipulation is an alternative, but the sum formula is standard and highly intuitive).
*/

#include <iostream>
#include <vector>
using namespace std;

int findmissingnumber(vector<int>& nums, int N){
    long long expectedsum = (long long)N* (N+1)/2;
    long long actualsum = 0;
    for(int nums : nums){
        actualsum+=nums;
    }

    return expectedsum-actualsum;

}

int main(){
    vector<int> nums = {1,2,3,5};
    int ans = findmissingnumber(nums,5);
    cout<<ans<<endl;
}