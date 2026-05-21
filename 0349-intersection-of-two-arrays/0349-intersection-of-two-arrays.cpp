class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s;
        vector<int>ans;

        //put nums1 element into set
        for(int i=0;i<nums1.size();i++){
            s.insert(nums1[i]);
        }
        //compare for common elements
        for(int i=0;i<nums2.size();i++){

            if(s.find(nums2[i])!=s.end()){
                ans.push_back(nums2[i]);
                s.erase(nums2[i]);
            }
        }
        return ans;
    }
};