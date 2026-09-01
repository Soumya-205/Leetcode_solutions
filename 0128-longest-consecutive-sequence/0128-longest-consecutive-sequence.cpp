class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;

        //insert the numbers into the set
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }
        int longest=0;
        for(int num: set){
            //check if nums[i] is the START of the sequence
            if(set.find(num-1)==set.end()){
                int current=num;
                int count=0;

                //Continue checking the existing sequence
                while(set.find(current)!=set.end()){
                    count++;
                    current++;
                }
                //keep the maximum length sequence
                longest=max(count, longest);
            }
        }
        return longest;
    }
};