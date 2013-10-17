/*
Word Ladder

http://leetcode.com/onlinejudge#question_127

Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

//=======================================================================

Word Ladder II

http://leetcode.com/onlinejudge#question_126

Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

//=======================================================================
// Word Ladder I
// version 1, Time Limit Exceeded
// for word length k, and searching in dictionary takes O(1), and the depth of trasation is d
// time complexity is O(n^d), space complexity is O(n)
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start == end) return 0;
        if(start.size() != end.size()) return 0;
        if(trans(start, end)) return 2;
        
        // use queue for BFS, store word string and their distance from start
        queue<pair<string, int> > que; // queue of string and len
        que.push(make_pair(start, 1));
        dict.erase(start);
        
        while(!que.empty()) {
            string str = que.front().first;
            int len = que.front().second;
            que.pop();
            dict.erase(str);
            
            if(trans(str, end)) return len+1;
            
            // search thru dictionary to find the word that can be transfer in 1 step
            for(auto it = dict.begin(); it != dict.end(); ++it)
                if(trans(*it, str)) 
                    que.push(make_pair(*it, len+1));
        }
        
        return 0;
    }
    
    // function to check if the word that can be transfer in 1 step
    bool trans(string start, string end) {
        if(start.size() != end.size()) return false;
        
        int step = 0;
        for(int i=0; i<start.size(); i++) {
            if(start[i] != end[i]) {
                step++;
            }
        }
        return step == 1;
    }
};

//=======================================================================
// Word Ladder I
// version 2, uses 608 milli secs for large judge
// for word length k, and searching in dictionary takes O(1), and the depth of trasation is d
// time complexity is O((k*26)^d), space complexity is O((k*26)^d)
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start == end) return 0;
        
        // use queue for BFS, store word string and their distance from start
        queue<pair<string, int> > que;
        que.push(make_pair(start, 1));
        dict.erase(start);
        
        while(!que.empty()) {
            string str = que.front().first;
            int len = que.front().second;
            que.pop();
            
            // branching factor of BFS is 26 characters * string size
            for(int i=0; i<str.size(); i++) {
                char w = str[i];
                for(char c='a'; c<='z'; c++) {
                    if(w == c) continue;
                    str[i] = c;
                    if(str == end) return len+1;
                
                    // use count instead of find to make searching faster
                    if(dict.count(str) != 0) {
                        que.push(make_pair(str, len+1));
                        // erase the appeared words from dictionary can save search time
                        dict.erase(str);
                        if(dict.empty()) break;
                    }
                }
                str[i] = w; // recover character
            }
        }
        return 0;
    }
};

//=======================================================================
// Word Ladder II
// uses 588 milli secs for large judge
// for word length k, and searching in dictionary takes O(1), and the depth of trasation is d
// branching factor of BFS is 26 characters * string size, better than searching all dictionary
// time complexity is O((k*26)^d), space complexity is O((k*26)^d)

class Solution {
    // recursive function to generate path using backtracking method
    void gen(int v1, int v2, vector<string> &vdict, vector<vector<int> >& prev, 
             vector<int>& path, vector<vector<string> >&ans){
        path.push_back(v2); // push the nodes into path for back tracking
        
        if(v2 == v1) { // translate the path of index to string in reverse order
            ans.push_back(vector<string>());
            for(auto rit=path.rbegin(); rit!=path.rend(); rit++)
                ans.back().push_back(vdict[*rit]);
        } else { // gengrate all possible path in recursive way
            for(auto it=prev[v2].begin(); it!=prev[v2].end(); it++)
                gen(v1, *it, vdict, prev, path, ans);
        }
        
        path.pop_back(); // pop the nodes from path for back tracking
    }
    
public:
    // translate problem to graph search, use interger instead of string to avoid string copy & match
    // use BFS to find path from start to end, and translate back to string at the end
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(start);
        dict.insert(end);
        
        unordered_map<string, int> imap;  // word mapping: word -> id mapping in vdict
        vector<string> vdict(dict.begin(), dict.end()); // vector of dictionary: id -> word mapping in dict
        vector<vector<int> > prev(dict.size()); // store the previous words in BFS
        vector<int> len(dict.size(), -1); // store the distance from start
        
        imap.reserve(vdict.size());
        for(int i=0; i<vdict.size(); i++) // build string - index mapping
            imap[vdict[i]] = i;
        
        int vstr=imap[start], vend=imap[end]; // find the index of start and end words
        queue<int> que; // queue for BFS to search path from start to end
        que.push(vstr);
        len[vstr] = 1; // mark distance of start
        
        while(not que.empty()) {
            int v1 = que.front(); que.pop();
            if(v1 == vend) break;
            
            imap.erase(vdict[v1]); // erase the appeared words from dictionary can save search time
            
            // find all words that can be transfered in 1 step
            // if multiple words can reach the same words, save all the adjancent words
            for(int j=0; j<vdict[v1].size(); j++) { // branching factor = 26 characters * string size
                char w = vdict[v1][j];
                for(char c = 'a'; c <= 'z'; c++) {
                    vdict[v1][j] = c;
                    if(imap.count(vdict[v1])) {
                        int v = imap[vdict[v1]];
                        if(len[v] == -1) { // found new words (len=-1), add to queue
                            prev[v].push_back(v1);
                            len[v] = len[v1] + 1;
                            que.push(v);
                        } else if(len[v] == len[v1] + 1) { // words that already found
                            prev[v].push_back(v1);
                        }
                    }
                } // end of: for(char c = 'a'; c <= 'z'; c++)
                vdict[v1][j] = w;
            } // end of: for(int j = 0; j < vdict[v1].size(); j++)
        } // end of: while(not que.empty())

        // generate the full sting path using the index
        vector<vector<string> > ans;
        vector<int> path;
        gen(vstr, vend, vdict, prev, path, ans);
        return ans;
    }
};