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
