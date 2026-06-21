class Solution {
public:
    string simplifyPath(string path) {
        vector<string>st;
        stringstream ss(path);
        string token;

        while(getline(ss,token,'/')){
            if(token==""||token=="."){
                continue;
            }
            else if(token==".."){
                if(!st.empty()){
                    st.pop_back();
                }
            }
            else{
                st.push_back(token);
            }
        }
        //build answer
        string result="";
        for(string dir:st){
            result+="/"+dir;
        }
        //root directly
        if(result.empty()){
            return "/";
        }
        return result;
    }
};