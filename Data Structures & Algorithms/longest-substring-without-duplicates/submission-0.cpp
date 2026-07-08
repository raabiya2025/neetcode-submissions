

📌 Longest Substring Without Repeating Characters (LC 3)
Pattern
Sliding Window + HashSet
Approach
Maintain a window using left and right.
Expand the window by moving right.
If the current character already exists in the window:
Shrink the window from the left.
Remove characters from the HashSet.
Continue until the duplicate is removed.
Insert the current character.
Update the maximum window length.
Key Idea

The window should always contain unique characters only.

HashSet always stores exactly the characters inside the current window.

Sliding Window Template
Expand window
      ↓
Window invalid?
      ↓
YES → Shrink window until valid
      ↓
Insert current character
      ↓
Update answer
Time Complexity
O(n)

Each character is inserted once and removed once.

Space Complexity
O(k)

k = Number of unique characters in the current window.
    
    
    
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window
        unordered_set<int> st;
        int left=0;
        int n=s.length();
        int right;
        int length,max=0;
        
        //The HashSet must always exactly match the current window.
        
        for(right=0;right<n;right++){
            while(st.count(s[right])){
                    st.erase(s[left]);
                    left++;
                   }
            st.insert(s[right]);
            length=right-left+1;
            if(length>max){
                max=length;
            }

            }
        


        return max;
    }
    
};
