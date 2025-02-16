#if 0
Remove Element

Difficulty: Easy

Given an integer array 'nums' and an integer 'val', remove all occurrences of 'val' in 'nums' in-place. The order of the elements may be changed.
Then return the number of elements in 'nums' which are not equal to 'val'.

Consider the number of elements in 'nums' which are not equal to 'val' be 'k', to get accepted, you need to do the follwing:
- Change the array 'nums' such that the first 'k' elements of 'nums' contain the elements which are not equal to 'val'. The remaining elements of 'nums' are note important as well as the size of nums.
- Return 'k'

#endif

// Include Statements
#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Solution Class
class Solution {
    public:
        int removeElements(vector<int>& nums, int val) {
            /*
            Solution::removeElement function solves the described problem.

            Uses two for loops to travers each number pair and compare them to the target.
            Runs in O(n^2)
            */

           int k = nums.size(); // number of elements in 'nums' which are not equal to 'val'

            ///// Remove elements equal to 'val' and determine the value of 'k' /////
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == val){
                    nums[i] = NULL;
                    k--;
                }
            }

            ///////////////////////////// Reorder nums //////////////////////////////
            for (int i = 0; i < k; ++i) {
                if (nums[i] == NULL){
                    for (int j = i; j < nums.size()-1; ++j){
                        nums[j] = nums[j+1];
                    }
                }
            }

            ////////////////// Set later elements of nums to NULL //////////////////
            for (int i = k; i< nums.size(); ++i){
                nums[i] = NULL;
            }

            ////////////////////////////// Printing ////////////////////////////////
            cout << "Sorted array: [";
            for (int i = 0; i < nums.size(); ++i) {
                cout << nums[i] << " ";
            }
            cout << "]" << endl;

            // Return an empty vector if no solution was found
            return k; 
        }
};

///// Main Function /////////////////////////////////////////////////////
int main() {
    ///// Input values /////
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};   // Input array
    int val = 2;                         // Value to remove

    // Create an instance of the Solution class
    Solution solution;

    // Call the twoSum_For function
    int k = solution.removeElements(nums, val); // Calls my implementation

    // Print the result
    cout << "Instances of non '" << val << "' elements found is: " << k << endl;

    return 0;
};