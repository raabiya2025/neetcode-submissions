Approach 1: Sort + HashMap
Key Idea
Two strings are anagrams iff their sorted versions are identical.
Use the sorted string as the key in a hashmap.
Store the original strings in the corresponding vector.
Algorithm
Create unordered_map<string, vector<string>> mp.
For every string:
Make a copy.
Sort the copy.
Insert the original string into mp[sortedCopy].
Traverse the hashmap and push every vector<string> into the answer.
Data Structure
unordered_map<string, vector<string>> mp;
Complexity
Let:
n = number of strings
k = average string length
Sorting one string = O(k log k)
Sorting all strings = O(n × k log k)
HashMap insertion = O(1) average

Time: O(n × k log k)

Space: O(n × k)
    Common Mistakes
unordered_map<string, vector<string>>, NOT unordered_map<string, string>
Iterate using string, not char.
sort() modifies the string in place.
Sort a copy, not the original string.
Key = sorted string.
Value = original string.
mp[key].push_back(word);

While creating the answer:

for (auto &x : mp)
    ans.push_back(x.second);






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
