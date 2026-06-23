class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char,int> m;
        unordered_map<char,int> n;
        for(char i:s){
            m[i]++;
        }
        for(char i:t){
            n[i]++;
        }
        for(auto i:m){
            if(m[i.first] != n[i.first])
                return false;
        }
        return true;
    }
};
