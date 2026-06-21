class Solution {
public:
    string decodeString(string s) {
        stack<int>countStack;
        stack<string>stringStack;

        int num=0;
        string currStr="";

        for(char ch:s){
            if(isdigit(ch)){
                num=num*10+(ch-'0');
            }
            else if(ch=='['){
                countStack.push(num);
                stringStack.push(currStr);

                num=0;
                currStr="";
            }
            else if(ch==']'){
                int repeat=countStack.top();
                countStack.pop();

                string prevStr= stringStack.top();
                stringStack.pop();

                string temp="";
                for(int i=0;i<repeat;i++){
                    temp+=currStr;
                }
                currStr=prevStr+temp;
            }
            else{
                currStr+=ch;
            }
        }
        return currStr;
    }
};