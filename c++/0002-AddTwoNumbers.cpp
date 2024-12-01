#if 0
Add Two Numbers

Difficulty: Medium

Given two non-empty linked lists representing two non-negative 
integers stored in reverse order with one digit per node, 
return the sum as a similar linked list.

#endif

// Include Statements
#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Definition for singly-linked list
struct ListNode {
    // Attributes
    int val;
    ListNode *next;

    // Constructors
    ListNode() : val(0), next(nullptr) {} 
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        }
};

// Main Routine
int main() {
    ListNode* l1 = new ListNode(3);
    l1 = new ListNode(4, l1);
    l1 = new ListNode(2, l1);

    ListNode* l2 = new ListNode(4);
    l2 = new ListNode(6, l2);
    l2 = new ListNode(5, l2);

    Solution solution;
    ListNode* answer = solution.addTwoNumbers(l1, l2);
    cout << "The resulting sum (reversed) is : ";
    while (answer->next != nullptr) {
        cout << answer->val << " -> ";
        answer = answer->next;
    }
    cout << endl;

    return 0;
};