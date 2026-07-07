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
