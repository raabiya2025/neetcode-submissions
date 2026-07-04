class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int x:nums){
            s.insert(x);
        }
        int longg=0;
        for(auto x:s){
            if(!s.count(x-1)){
                int current=x;
                int length=1;
                while(s.count(current+1)){
                    length++;
                    current++;
                }
                longg=max(longg,length);
            }

        }
        return longg;
        
    }
};
