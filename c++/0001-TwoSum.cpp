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
#include <list>

using namespace std;

// Custom hash table class
class HashTable {
    private:
        // Each bucket is a list of pairs (key, value)
        // The table [vector] has a bunch of buckets [lists] which hold the key and value [in a pair data type]
        // A really good hash function with 1-1 output wouldn't need the buckets
        // Key - refers to a integer in nums
        // Value - corresponds to that integer's index in nums
        vector<list<pair<int, int>>> table;
        int table_size;

        // Hash function to calculate the index
        int hashFunction(int key) {
            return abs(key) % table_size; // Pretty simple function
        }

    public:
        // Consturctor: Initialize the table with a given size
        HashTable(int size) : table_size(size) {
            table.resize(size);
        }

        // Insert a (key, value) pair into the hash table
        void insert(int key, int value) {
            int index = hashFunction(key);
            table[index].emplace_back(key, value); // Add to the bucket
        }

        // Search for a key in the hash table
        int get(int key) {
            int index = hashFunction(key);
            for (const auto& pair : table[index]) { // Check every pair in the bucket
                if (pair.first == key) {
                    return pair.second; // Return the associated value
                }
            }

            // Return -1 if key is not found
            return -1;
        }

        // Check if a key exists
        bool exists(int key) {
            int index = hashFunction(key);
            for (const auto& pair : table[index]) {
                if (pair.first == key) {
                    return true;
                }
            }

            // Key (the complement) does not exist
            return false;
        }
};

// Solution Class
class Solution {
    public:
        vector<int> twoSum_Hash(vector<int>& nums, int target) {
            /*
            Solution::twoSum_Hash function solves the descibed problem.
            Traverses vector once, checks for complement in hash table, if not adds current value to table.
            Runs in O(n)
            */
            HashTable hashTable(nums.size()); // Initialize hash table

            for (int i = 0; i < nums.size(); ++i) {
                int complement = target - nums[i];

                // Check if complement exists in the hash table
                if (hashTable.exists(complement)) {
                    return {hashTable.get(complement), i};
                }

                // Insert the curretn number with its index into the hash table
                hashTable.insert(nums[i], i);
            }

            // Return an empty vector if no solution was found
            return {}; 
        }

        vector<int> twoSum_For(vector<int>& nums, int target) {
            /*
            Solution::twoSum_For function solves the descibed problem.
            Uses two for loops to travers each number pair and compare them to the target.
            Runs in O(n^2)
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
    vector<int> result = solution.twoSum_Hash(nums, target);

    // Print the result
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
};