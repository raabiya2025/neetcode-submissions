
# Two Sum

## Problem
Given an array nums and a target, return indices of two numbers such that they add up to target.

## Approach 1: Brute Force

### Idea
Check every pair.

### Algorithm
For every i:
    For every j > i:
        if nums[i] + nums[j] == target
            return [i,j]

### Complexity
Time: O(n²)
Space: O(1)

### Why it works
We examine all possible pairs.

### Drawback
Too slow for large inputs.

---

## Approach 2: Hash Map (Optimal)

### Idea
While traversing the array, store previously seen numbers.
For current number x, check if target - x already exists.

### Algorithm
Create hash map

For each number:
    complement = target - num

    if complement exists:
        return indices

    store current number and index

### Complexity
Time: O(n)
Space: O(n)

### Why it works
Lookup in hash map is O(1) on average.

### Key Observation
Instead of searching the entire array for complement,
store what you've already seen.

---

## Pattern
Hashing / Lookup Optimization

## Similar Problems
- Contains Duplicate
- Two Sum II
- 3Sum
- Subarray Sum Equals K

## Interview Follow-up
Can we do better than O(n²)?
Answer: Yes, using HashMap.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int n=nums.size();
        for(int x=0;x<n;x++){
            
            int comp=target-nums[x];
            if(m.find(comp)!=m.end())
                return{m[comp],x};
            m[nums[x]]=x;
            
            
            
            


        }

        
    }
};
