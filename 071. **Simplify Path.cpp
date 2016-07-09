//http://bangbingsyb.blogspot.com/2014/11/leetcode-simplify-path.html
class Solution {
public:
    string simplifyPath(string path) {
        string ret, curDir;
        vector<string> allDir;
        
        path.push_back('/');
        for(int i=0; i<path.size(); i++) {
            if(path[i]=='/') {
                if(curDir.empty()) {
                    continue;
                }
                else if(curDir==".") {
                    curDir.clear();
                }
                else if(curDir=="..") {
                    if(!allDir.empty())
                        allDir.pop_back();
                    curDir.clear();
                }
                else {
                    allDir.push_back(curDir);
                    curDir.clear();
                }
            }
            else {
                curDir.push_back(path[i]);
            }
        }
        
        
        for(int i=0; i<allDir.size(); i++) 
            ret.append("/"+allDir[i]);
        if(ret.empty()) ret = "/";
        return ret;
    }
