class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> s;
        
        for(string m:strs){
            string temp=m;
            sort(temp.begin(),temp.end());
            s[temp].push_back(m);
        }
        vector<vector<string>> arr;
        for(auto x:s){
            arr.push_back(x.second);
        }
        return arr;

        
    }
};
