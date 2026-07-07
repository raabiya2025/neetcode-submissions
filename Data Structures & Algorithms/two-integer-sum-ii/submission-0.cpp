
📌 Two Sum II – Input Array Is Sorted (LC 167)
Pattern
Two Pointers
Approach
Place one pointer at the beginning and one at the end.
Compute the current sum.
If the sum is smaller than the target, move the left pointer.
If the sum is larger than the target, move the right pointer.
If the sum equals the target, return the 1-based indices.
Key Idea
Since the array is sorted:
Sum too small → move left.
Sum too large → move right.
No HashMap required.
Time Complexity
O(n)
Space Complexity
O(1)
Common Mistakes
Initializing left = 1 and right = n instead of 0 and n-1.
Returning values instead of 1-based indices.
Using a for loop instead of while(left < right).
Accessing numbers[n] (out of bounds).
Forgetting that vectors use 0-based indexing.
Pattern Learned
Two Pointers
Sorted Array Optimization





class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left, right;
        int n=numbers.size();
        left=0;
        right=n-1;
        vector<int> ans;

        while(left<right){
            if(numbers[left]+numbers[right]<target){
                left++;
            }
            else if(numbers[left]+numbers[right]>target){
                right--;

            }
            else{
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            }
        }
    }
        
    
};
