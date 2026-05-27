#include <algorithm>

class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "", delim = "del%";

        for(string str : strs){
            reverse(str.begin(), str.end());
            res.append(str + delim);
        }
        return res;

    }

    vector<string> decode(string s) {
        vector<string> res;
        string delim = "del%";
        while(!s.empty()){
            int index = s.find(delim);
            string tempStr = s.substr(0, index);
            reverse(tempStr.begin(), tempStr.end());
            res.push_back(tempStr);
            s.erase(0, index + delim.length());
        }
        
        return res;
    }
};
