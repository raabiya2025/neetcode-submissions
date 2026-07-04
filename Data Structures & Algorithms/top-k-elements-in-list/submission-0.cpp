Pattern
HashMap + Bucket Sort
Approach
Count the frequency of every element using a HashMap.
Create buckets where index = frequency.
Store numbers in their corresponding frequency bucket.
Traverse buckets from highest frequency to lowest until k elements are collected.
Key Idea
Frequency becomes the index.
Highest frequency is at the end of the bucket array.
One bucket can contain multiple numbers.
Time Complexity
O(n)
Space Complexity
O(n)
Common Mistakes
Using only ans.push_back(bucket[i]) instead of iterating through every element inside the bucket.
Forgetting that multiple elements can have the same frequency.
Using sorting (O(n log n)) instead of buckets.
Pattern Learned
Frequency Counting
Bucket Sort
HashMap + Array




class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;

        }
        int n=nums.size();
        vector<vector<int>> bucket(n+1);
        for(auto x:mp){
            bucket[x.second].push_back(x.first);
        }
        vector<int> ans;
        for(int i=n;i>=1;i--){
            for(int num:bucket[i]){
                ans.push_back(num);
                if(ans.size()==k)
                    return ans;
            }
        }
            
               
            
        }
        
    
};
