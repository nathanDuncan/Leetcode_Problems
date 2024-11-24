#if 0
Two Sum

Difficulty: Easy

Given an array of integers [nums] and an integer [target], return indices of the two numbers such that they add up to target.
You may assume that each input would have exacly one solution, and you may not use the same element twice.
You can return the answer in any order.

#endif

// Include Statements
#include <iostream>
#include <vector>
using namespace std;

// Solution Class
class Solution {
    public:
        vector<int> twoSum_For(vector<int>& nums, int target) {
            /*
            Solution::twoSum function solves the descibed problem.
            Uses two for loops to travers each number pair and compare them to the target.
            Runs in O(n^2)
            
            Inputs
            ------
            nums, vector<int>&
                Reference to the array containing numbers
            target, int
                Target value of two numbers
            
            Returns
            -------
            vector<int>
                Incices of two numbers in 'nums' that add to 'target'
            */

            for (int i = 0; i < nums.size(); ++i) {
                for (int j = i + 1; j < nums.size(); ++j) {

                    // For each unique pair check if sum is target
                    if (nums[i] + nums[j] == target) {
                        vector<int> indices = {i, j};
                        return indices;
                    }
                }
            }

            // Return an empty vector if no solution was found
            return {}; 
        }
};

// Main Function
int main() {
    // Input values 
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Create an instance of the Solution class
    Solution solution;

    // Call the twoSum_For function
    vector<int> result = solution.twoSum_For(nums, target);

    // Print the result
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
};