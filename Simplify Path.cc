/*
Simplify Path

http://leetcode.com/onlinejudge#question_71

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".

Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

class Solution {
public:
    string simplifyPath(string path) {
        if(path == "") return "/";
        if(path[0] != '/') path = '/' + path; // ensure start with '/'
        if(path.back() != '/') path = path + '/'; // ensure end with '/'
        
        vector<string> stack;
        for(int p1=0, p2=1; p2<path.size(); ++p2)
            if(path[p2] == '/') {
                string sub = path.substr(p1+1, p2-p1-1);
                if(sub == "..") { if(!stack.empty()) stack.pop_back(); } 
                else if(sub != "." && sub != "") stack.push_back(sub);
                p1 = p2;
            }
        
        string result = "";
        for(int i=0; i<stack.size(); ++i)
            result += "/" + stack[i];
        
        return result.empty() ? "/" : result;
    }
};
