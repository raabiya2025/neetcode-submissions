Pattern
String Serialization
Approach
Encode each string as:
length#string

Example:

4#neet4#code2#is
During decoding:
Read digits until # to obtain the length.
Convert the length string to an integer.
Read exactly that many characters as one word.
Repeat until the encoded string ends.
Key Idea
The separator alone is not enough because strings may contain special characters.
The length tells the decoder exactly how many characters belong to the current string.
No ambiguity, even if the string contains #.
Time Complexity
Encoding: O(n)
Decoding: O(n)
Space Complexity
O(n)
Common Mistakes
Splitting directly on #.
Forgetting to read multiple digits for lengths greater than 9.
Not advancing the pointer after extracting the substring.
Pattern Learned
Serialization / Deserialization
Pointer Traversal
Length-Prefixed Encoding



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
