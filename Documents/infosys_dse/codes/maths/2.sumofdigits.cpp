 /*
 2. Sum Digits of an Integer
Question:
Given an integer, calculate and return the sum of its digits.

Concept (Optimized Approach - Modulo and Division):
Similar to the palindrome logic, we can isolate each digit of the number using modulo base-10 arithmetic. We run a loop while the number is not zero. In each iteration, we use % 10 to grab the rightmost digit and add it to our sum tracker. Then, we use / 10 to chop off that rightmost digit. To handle negative numbers robustly, we take the absolute value of the integer before starting the loop.
 */

 #include <iostream>
#include <cmath> // For abs()
using namespace std;

int sumOfDigits(int n) {
    int sum = 0;
    
    // Handle negative numbers to ensure proper digit extraction
    n = abs(n);
    
    while (n > 0) {
        // Extract the last digit and add it to sum
        sum += n % 10;
        
        // Remove the last digit from n
        n /= 10;
    }
    
    return sum;
}

int main(){
    int num = 1234;
    cout<<sumOfDigits(num);
}
