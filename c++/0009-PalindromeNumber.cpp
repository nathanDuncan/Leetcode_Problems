#if 0
Palindrome Number

Difficulty: Easy

Given an integer [x], return true if [x] is a palindrome, and false otherwise.

#endif

// Include Statements
#include <iostream>
#include <vector>

using namespace std;

// Solution Class 
class Solution {
    public:
        bool isPalindrome(int x) {

            if (x < 0 ){return false;} // Quick elimination of negatives

            int reverse = 0;
            
            while(reverse < x) {
                reverse = reverse*10 + x%10;
                x = x/10;
            }

            return (reverse == x || reverse/10 == x);
        }
};

int main() {
    // Input Values
    vector<int> values = {121, -121, 0, 40404, 1234, 67800876};

    // Create an instance of the Solution class
    Solution solution;

    for (auto num : values) {
        cout << "Is " << num << " a palindrone? -> " << solution.isPalindrome(num) << endl;
    }

    return 0;
};