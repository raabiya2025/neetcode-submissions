class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window
        unordered_set<int> st;
        int left=0;
        int n=s.length();
        int right;
        int length,max=0;
        
        //The HashSet must always exactly match the current window.
        
        for(right=0;right<n;right++){
            while(st.count(s[right])){
                    st.erase(s[left]);
                    left++;
                   }
            st.insert(s[right]);
            length=right-left+1;
            if(length>max){
                max=length;
            }

            }
        


        return max;
    }
    
};
