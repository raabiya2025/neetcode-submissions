Pattern
Prefix Product + Suffix Product
Two-pass array traversal.
Approach
First pass (Left → Right): Store the product of all elements before the current index.
Second pass (Right → Left): Multiply each position by the product of all elements after the current index.
Reuse the output array to store prefix products, avoiding extra space.
Key Idea
Answer = Left Product × Right Product
Store first, then update the running product.
Traverse from both directions.
Time Complexity
O(n)
Space Complexity
O(1) extra space (excluding the output array).
Common Mistakes
Multiplying the current element before storing the prefix.
Overwriting ans[i] instead of multiplying by the suffix product.
Using an empty vector without allocating size.
Thinking two separate loops are O(n²) (they are O(n)).
Pattern Learned
Prefix/Suffix Products
Running Product
Two-pass Optimization

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int leftproduct=1;
        int rightproduct=1;
        for(int i=0;i<nums.size();i++){
            ans[i] = leftproduct;
            leftproduct*=nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
           ans[i]=ans[i]*rightproduct;
           rightproduct*=nums[i];
           
        }
        
        return ans;
    }
};
