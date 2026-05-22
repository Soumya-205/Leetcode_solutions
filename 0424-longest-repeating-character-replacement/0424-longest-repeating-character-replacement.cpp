class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int left=0;
        int maxFreq=0;
        int maxLen=0;

        for(int right=0;right<s.length();right++){
            //increase frequency
            mp[s[right]]++;

            //update maximum frequency
            maxFreq=max(maxFreq,mp[s[right]]);

            //current window size
            int windowsize=right-left+1;

            //if invalid window
            while((windowsize-maxFreq)>k){
                mp[s[left]]--;
                left++;

                windowsize=right-left+1;
            }
            //store maximum answer
            maxLen=max(maxLen,windowsize);
        }
        return maxLen;
    }
};