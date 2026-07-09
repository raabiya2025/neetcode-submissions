class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> frequency1(26,0);
        int n=s2.length();
        int left=0,i;
        vector<int> frequency2(26,0);
        //sliding window:s2
        if(s1.length() > s2.length())
            return false;
        for(char x:s1){
            frequency1[x-'a']++;
        }
    //build the frequency array of the initial window of string2 length
        for(i=0;i<s1.length();i++){
            frequency2[s2[i]-'a']++;}
            if(frequency1==frequency2){
                return true;}
            
        
            
        for(int right = s1.length(); right < n; right++){
                frequency2[s2[left]-'a']--;
                left++;
                frequency2[s2[right]-'a']++;
                if(frequency1==frequency2){
                return true;
            }}
        return false;

    }
        

        
    
};
