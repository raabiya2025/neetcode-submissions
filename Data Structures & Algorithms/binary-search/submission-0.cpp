class Solution {
public:
    int binary(vector<int>& nums,int low,int high, int target){
        if(low>high){
            return -1;
        }
        else{
            int mid=(low + high) / 2;
            if(target<nums[mid]){
                return binary(nums,low,mid-1,target);
            }
            else if(target>nums[mid]){
                return binary(nums,mid+1,high,target);
            }
            else{
                return mid; 
            }
        }
    }
    int search(vector<int>& nums, int target) {
        
        
        return binary(nums,0,nums.size()-1,target);
        
    }
};
