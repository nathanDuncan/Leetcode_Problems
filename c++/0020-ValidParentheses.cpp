#if 0
ValidParentheses

Difficulty: Easy

Given a string 's' containing just the characters '(', ')', '{', '}', '[', and ']', determine if the input string is valid.
An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

#endif

// Include Statements
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;

            for(auto c : s){

                if (bracket_map.count(c)){
                    if (st.empty() || st.top() != bracket_map[c]) {
                        return false;
                    }
                }
                else {
                    st.push(c);
                }
            }

            return st.empty();

        }
    private:
    unordered_map<char, char> bracket_map = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

};

int main(){
    Solution solution;

    string str = "([{[[]]}])"; 

    bool ans = solution.isValid(str);

    cout << ans << endl;

    return 0;
}
