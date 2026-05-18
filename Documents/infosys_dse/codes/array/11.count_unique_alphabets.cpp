/*
2. Count Unique Alphabets in an Array
Question:
Given an array of characters, count the number of unique alphabet letters present. (For example, given ['a', 'b', 'a', '1', 'C'], it should identify 'a', 'b', and 'c' as the unique alphabets).

Concept (Optimized Approach - Hash Set with Case Handling):
To count unique items, a Hash Set (unordered_set) is the perfect data structure because it automatically ignores duplicate insertions. We iterate through the character array and use isalpha() to ensure we are only looking at letters (ignoring numbers or symbols). To ensure that 'A' and 'a' are counted as the same letter of the alphabet, we convert every character to lowercase using tolower() before inserting it into the set. The final answer is simply the size of the set.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cctype> // For isalpha() and tolower()
using namespace std;

int countuniquealphabets(vector<char>& chars){
    unordered_set<char> unqiueletters;
    for(char c : chars){
        if(isalpha(c)){
            unqiueletters.insert(tolower(c));
        }
    }
    return unqiueletters.size();
}

int main(){
    vector<char> myChars = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '1'};
    
    // 2. Call the function and store the result
    int result = countuniquealphabets(myChars);
    
    // 3. Print the result
    cout << "The number of unique alphabetical characters is: " << result << "\n";
    
    return 0;
}