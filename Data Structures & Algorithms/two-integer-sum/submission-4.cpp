class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //use a hashmap
        unordered_map<int,int> mp;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int comp=target-nums[i];
            if(mp.count(comp)==1){
                return vector<int>{mp[comp], i};
            }
            else{
                mp[nums[i]]=i;
            }

        }
//       The problem guarantees:

// Exactly one valid answer exists.

// So logically, the function will always return from inside the loop.

// However, the compiler doesn't know the problem statement.
        return {};
        
    }
};
