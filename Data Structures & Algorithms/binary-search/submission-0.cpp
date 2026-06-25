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
Pattern
Binary Search

Used when:

Array is sorted
Need fast searching
Need to reduce search space repeatedly
Key Observation

Instead of checking every element:

Linear Search -> O(n)

Use sorted order to eliminate half the search space each step:

Binary Search -> O(log n)
Core Idea

At every step:

Find middle element

If:

target == nums[mid]

Found.

If:

target < nums[mid]

Search left half.

If:

target > nums[mid]

Search right half.

Important Formula
Mid Index

Preferred:

int mid = low + (high - low) / 2;

Avoid:

int mid = (low + high) / 2;

Reason:

Possible integer overflow

Interviewers like the first version.
