class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //using hashset we can do
        unordered_set<int> s;
        for(int x:nums){
            if(s.count(x)==0){
                s.insert(x);
            }
            else{
                return true;
            }
        }
        return false;


        
    }
};