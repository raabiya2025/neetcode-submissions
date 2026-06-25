class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='('||c=='{'||c=='['){
                st.push(c);
            }
            else{
            if(st.empty())

                return false;
            
            if(c==')'&& st.top()!='('){
                return false;
            }
            if(c=='}'&& st.top()!='{'){
                return false;
            }
            if(c==']'&& st.top()!='['){
                return false;
            }
            st.pop();
            }

        }
        return st.empty();
    }
};
Complexity
Time Complexity

Each bracket:

pushed once
popped once
O(n)
Space Complexity

Worst case:

((((((((

All brackets stay in stack.

O(n)
Pattern
Stack
Similar Problems
Min Stack
Daily Temperatures
Next Greater Element
Largest Rectangle in Histogram
Evaluate Reverse Polish Notation
