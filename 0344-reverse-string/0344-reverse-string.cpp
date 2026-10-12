class Solution {
public:
    void reverseString(vector<char>& s) {
        reverseHelpers(s,0,(int)s.size()-1);
    }
private:
    void reverseHelpers(vector<char>&s, int left, int right){
        //base case
        if(left>=right){
            return;
        }
        swap(s[left],s[right]);
        reverseHelpers(s,left+1,right-1);
    }
};