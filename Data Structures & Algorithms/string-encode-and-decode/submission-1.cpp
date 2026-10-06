class Solution {
public:

    string encode(vector<string>& strs) {

        string ans="";

        for(auto x:strs){
            ans+="/" + to_string(x.length()) + "/" +x;
        }

        return ans;

    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i=0;

        while(i<s.length()){
            int len=0;
            i++;

            while(i<s.length() && s[i]!='/'){
                len=len*10+(s[i]-'0');
                i++;
            }

            i++;

            ans.push_back(s.substr(i,len));

            i+=len;
        }

        return ans;
    }
};
