📌 Permutation in String (LC 567)
Pattern
Fixed-Size Sliding Window
Frequency Array
Approach

We need to check whether any substring of s2 is a permutation of s1.

A permutation has:

Same characters
Same frequency of each character
Order does not matter

Therefore, instead of comparing strings, compare frequency arrays.

Key Observations
1. Window size is fixed

The window size is always

s1.length()

because every permutation has the same length as s1.

2. Order doesn't matter

Example

abc
bac
cab

All are valid permutations because

a = 1
b = 1
c = 1

Only the frequency matters.

3. Compare frequencies, not characters

Instead of checking

abc == bac

check

frequency(s1)
==
frequency(window)

Important Observations I Derived

✅ Window length is always s1.length().

✅ Order doesn't matter.

✅ Frequency matters.

✅ Compare two frequency arrays.

✅ Every slide updates only two frequencies.

✅ Never rebuild the frequency array.

Time Complexity

Building frequency arrays

O(m)

Sliding window

O(n)

Comparing vectors

26 comparisons = O(1)

Overall

O(n)
Space Complexity
O(1)

Only two frequency arrays of size 26.



class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> frequency1(26,0);
        int n=s2.length();
        int left=0,i;
        vector<int> frequency2(26,0);
        //sliding window:s2
        if(s1.length() > s2.length())
            return false;
        for(char x:s1){
            frequency1[x-'a']++;
        }
    //build the frequency array of the initial window of string2 length
        for(i=0;i<s1.length();i++){
            frequency2[s2[i]-'a']++;}
            if(frequency1==frequency2){
                return true;}
            
        
            
        for(int right = s1.length(); right < n; right++){
                frequency2[s2[left]-'a']--;
                left++;
                frequency2[s2[right]-'a']++;
                if(frequency1==frequency2){
                return true;
            }}
        return false;

    }
        

        
    
};
