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
        vector<string> pathstack;
        
        int start=0, end=1;
        while(true){
            while(start<path.size() && path[start] == '/') 
                start++;
            if(start == path.size())
                break;
            end = start+1;
            while(end<path.size() && path[end] != '/') 
                end++;
            
            string str = path.substr(start, end-start);
            if(str == "..") {
                if(!pathstack.empty())
                    pathstack.pop_back(); 
            } else if(str != "" && str != ".")
                pathstack.push_back(str);
                
            start = end;
        }
        
        if(pathstack.empty()) return "/";
        
        string result = "";
        
        for(int i=0; i<pathstack.size(); i++)
            result += "/" + pathstack[i];
        
        return result;
    }
};


//===========================================================
class Solution {
public:
    string simplifyPath(string path) {
        if(path == "") return "/";
        if(path[0] != '/') path = '/' + path;
        if(path.back() != '/') path = path + '/';
        
        int p1=0, p2=1;
        vector<string> stack;
        while(p2<path.size()) {
            if(path[p2]!='/') ++p2;
            else {
                string sub = path.substr(p1+1, p2-p1-1);
                if(sub == "." || sub == "") ; // do nothing
                else if(sub == "..") { if(!stack.empty()) stack.pop_back(); } 
                else stack.push_back(sub);
                p1 = p2; ++p2;
            }
        }
        
        string result = "";
        
        for(int i=0; i<stack.size(); ++i)
            result += "/" + stack[i];
            
        if(result == "") result = "/";
        
        return result;
    }
};