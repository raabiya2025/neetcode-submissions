class Solution {
public:
    string encoded="";
    string encode(vector<string>& strs) {
        for(string s:strs){
            encoded+=to_string(s.size());
            encoded+="#";
            encoded+=s;
            
        }
        return encoded;

    }

    vector<string> decode(string s) {
        vector<string> ans;
    int i = 0;

    while (i < s.size()) {

        // Step 1: Read the length
        int len = 0;
        while (s[i] != '#') {
            len = len * 10 + (s[i] - '0');
            i++;
        }

        // Step 2: Skip '#'
        i++;

        // Step 3: Extract the substring of length 'len'
        string word = s.substr(i, len);

        // Step 4: Store it
        ans.push_back(word);

        // Step 5: Move to the next encoded string
        i += len;
    }

    return ans;
    }
};
