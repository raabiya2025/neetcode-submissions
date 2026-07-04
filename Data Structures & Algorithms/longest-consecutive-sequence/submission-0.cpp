📌 Longest Consecutive Sequence (LC 128)
Pattern
HashSet + Sequence Start Detection
Approach
Insert all numbers into a HashSet.
Iterate through each unique number.
A number is a sequence starter if (x - 1) does not exist.
From every starter, keep checking x + 1, x + 2, ... until the sequence ends.
Update the maximum sequence length.
Key Idea
Never start counting from the middle of a sequence.
Only expand sequences from their starting element.
HashSet provides O(1) average lookup for previous/next elements.
Time Complexity
O(n)
Every number is inserted once.
Every number is visited at most once while expanding sequences.
Space Complexity
O(n)
Common Mistakes
Sorting first (O(n log n)), violating the required complexity.
Starting a sequence from every element, leading to repeated work.
Forgetting the starter condition: !set.count(x - 1).
Using x inside the while loop instead of a separate current variable.

Forgetting to update the answer:

longest = max(longest, length);
Pattern Learned
HashSet Membership Queries
Sequence Start Detection
Expand Only From Valid Starters
Eliminate Duplicate Work



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int x:nums){
            s.insert(x);
        }
        int longg=0;
        for(auto x:s){
            if(!s.count(x-1)){
                int current=x;
                int length=1;
                while(s.count(current+1)){
                    length++;
                    current++;
                }
                longg=max(longg,length);
            }

        }
        return longg;
        
    }
};
