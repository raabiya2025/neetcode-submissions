class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
         unordered_map<char,int> mp2;
         int n=s.length();
         int m=t.length();
         if(n!=m)
            return false;
        for(char c:s){
            mp[c]++;
        }
        for(char c:t){
            mp2[c]++;
        }
        // 
        for(auto x:mp){
            if(mp2[x.first]!=x.second)
                return false;
        }
        return true;

 

    }
};
