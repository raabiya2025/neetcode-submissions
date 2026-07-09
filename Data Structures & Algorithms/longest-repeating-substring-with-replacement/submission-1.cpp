
📌 Longest Repeating Character Replacement (LC 424)
Pattern
Sliding Window + Frequency Array
Approach
Maintain a sliding window using left and right.
Store the frequency of each character in the current window.
Track the maximum frequency (maxFreq) in the current window.
Calculate:
windowLength = right - left + 1
replacementsNeeded = windowLength - maxFreq
If replacementsNeeded > k, shrink the window.
Update the maximum valid window length.
Key Idea

We never actually replace characters.

We only check whether the current window can be converted into a single repeating character using at most k replacements.

Formula
Replacements Needed = Window Length - Maximum Frequency

If

Replacements Needed <= k

the window is valid.

Otherwise,

shrink the window.

Dry Run
Example
s = "AABABBA"
k = 1
Window	Freq(A,B)	maxFreq	Length	Replacements	Valid?	Answer
A	     1,0	     1	     1	      0	              ✅	1
AA	     2,0	     2	     2	      0	              ✅	2
AAB	     2,1	     2	     3	      1	              ✅	3
AABA	 3,1	     3	     4	      1	              ✅	4
AABAB	 3,2	     3	     5	      2	              ❌ Shrink	4
ABAB	 2,2	     3*	     4	       1	             ✅	4
BABB	 1,3	     3	     4	      1	                ✅	4
BABBA	 2,3	     3	     5	      2	               ❌ Shrink	4

Answer = 4

* maxFreq is not decreased when the window shrinks.
Time Complexity
O(n)

Each pointer moves at most n times.

Space Complexity
O(1)

Frequency array size is always 26.

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left=0;
        int right,maxx=0;
        int length,ans=0;//always intialize varaiables to 0 if u are going to compare them in max() type functions
        int n=s.length();
        int frequency[26]={0};
        for(right=0;right<n;right++){
            frequency[s[right]-'A']++;
            maxx=max(maxx,frequency[s[right]-'A']);
            length=right-left+1;
            while(length-maxx>k){
                //shrink the window and decrease the length of the window and also the frequency of the leftmost character
                frequency[s[left]-'A']--;
                left++;
                length=right-left+1;
            }
            ans=max(ans,length);
            //We never actually replace any characters



        }
        return ans;
    }
};
