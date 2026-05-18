/*
1. Palindrome Check (Integer)Question:Given an integer x, return true if x is a palindrome, and false otherwise. An integer is a palindrome when it reads the same forward and backward.

Concept (Optimized Approach - Mathematical Reversal):While converting the integer to a string and using two pointers is easy ($O(N)$ space), the more optimized approach is to reverse the integer mathematically using modulo arithmetic. This keeps the space complexity at 
$O(1)$.If the number is negative, it cannot be a palindrome (e.g., -121 becomes 121-).
We extract the last digit of the number using x % 10 and append it to a reversedNumber variable (reversedNumber * 10 + last_digit).
We remove the last digit from the original number by dividing it by 10 (x / 10).
We repeat this until the original number is 0, then compare the reversedNumber to a saved copy of the original number. (Note: We use a long long for the reversed number to prevent integer overflow during the reversal process).
*/

#include <iostream>
using namespace std;

bool ispalindrome(int x){
    if(x<0){
        return false;
    }
    long long reversedNumber = 0 ;
    int originalNumber = x;
    while(x>0){
        int lastdigit = x%10;
        reversedNumber = reversedNumber *10 + lastdigit;
        x/=10;
    }
    return originalNumber;
}

int main(){
    int num = 1234321;
    cout<<ispalindrome(num);
}