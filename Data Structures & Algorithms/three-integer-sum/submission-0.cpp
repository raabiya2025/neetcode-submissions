
📌 3Sum (LC 15)
Pattern
Sorting + Fix One Element + Two Pointers
Approach
Sort the array.
Fix one element nums[i].
Convert the problem into Two Sum II:

Find two numbers such that:

nums[left] + nums[right] = -nums[i]
Use two pointers on the remaining sorted array.
Store every valid triplet.
Skip duplicate fixed elements and duplicate pointer values.
Key Idea
Fix one number.
Solve Two Sum on the remaining part of the array.
Sorting enables efficient pointer movement.
Skip duplicates to avoid repeated triplets.
    
    
    
    
    
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int fixed,left,right;
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            fixed=nums[i];
            left=i+1;
            right=n-1;
            while(left<right){
                
                if(nums[left]+nums[right]<-fixed){
                    left++;
                }
                else if(nums[left]+nums[right]>-fixed){
                    right--;
                }
                   
                else{
                    
                    ans.push_back({nums[left],nums[right],fixed});
                    right--;
                    left++;
                    while(left<right && nums[left]==nums[left-1])
                    left++;
                    while(left<right && nums[right]==nums[right+1])
                    right--;
                   
                }
            }
        }
        return ans;
    }
};
