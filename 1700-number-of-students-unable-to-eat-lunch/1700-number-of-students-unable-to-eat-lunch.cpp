class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0=0;
        int count1=0;

        //count students
        for(int student:students){
            if(student==0){
                count0++;
            }else{
                count1++;
            }
        }
        //Process sandwiches from top to bottom
        for(int sandwich:sandwiches){
            if(sandwich==0){
                //Nobody wants a circular sandwich
                if(count0==0){
                    break;
                }
                count0--;
            }else{
                //Nobidy wants a square sandwich
                if(count1==0){
                    break;
                }
                count1--;
            }
        }
        return count0+count1;
    }
};