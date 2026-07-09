class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left=0;
        int right,maxx=0;
        int length,ans=0;//always intialize varaiables to 0 if u are going to compare them in max() type functions
        int n=s.length();
        int frequency[26]={0};
        for(right=0;right<n;right++){
            frequency[s[right]-'A']++;
            maxx=max(maxx,frequency[s[right]-'A']);
            length=right-left+1;
            while(length-maxx>k){
                //shrink the window and decrease the length of the window and also the frequency of the leftmost character
                frequency[s[left]-'A']--;
                left++;
                length=right-left+1;
            }
            ans=max(ans,length);
            //We never actually replace any characters



        }
        return ans;
    }
};
