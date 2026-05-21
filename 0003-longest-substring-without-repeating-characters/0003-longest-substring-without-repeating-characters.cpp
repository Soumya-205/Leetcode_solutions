class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;

        int left=0;
        int maxLength=0;
        for(int right=0;right<s.length();right++){

            while(st.find(s[right])!=st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            int len=right-left+1;
            maxLength=max(maxLength,len);
        }
        return maxLength;

    }
};