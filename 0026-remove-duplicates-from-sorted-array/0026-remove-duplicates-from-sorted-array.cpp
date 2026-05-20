class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //edge case 1: if there is only one element
        if(nums.size()==1){
            return 1;
        }
        //j pointer is the position for next unique element
        int j=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
        
    }
  

};