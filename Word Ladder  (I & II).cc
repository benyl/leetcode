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
        if(start.size() != end.size()) return 0;
        
        // use queue for BFS, store word string and their distance from start
        queue<pair<string, int> > que;
        que.push(make_pair(start, 1));
        dict.erase(start);
        
        while(!que.empty()) {
            string str = que.front().first;
            int len = que.front().second;
            que.pop();
            
            // branching factor of BFS is 26 characters * string size
            for(int i=0; i<str.size(); i++)
            for(char c='a'; c<='z'; c++) {
                char chi = str[i];
                str[i] = c;
                
                if(str == end) return len+1;
                
                // use count instead of find to make searching faster
                if(dict.count(str) != 0) {
                    que.push(make_pair(str, len+1));
                    // erase the appeared words from dictionary can save search time
                    dict.erase(str);
                    if(dict.empty()) break;
                }
                
                str[i] = chi;
            }
        }
        return 0;
    }
};

//=======================================================================
// Word Ladder II
// uses 668 milli secs for large judge
// for word length k, and searching in dictionary takes O(1), and the depth of trasation is d
// time complexity is O((k*26)^d), space complexity is O((k*26)^d)
class Solution {
    // function to generate path using backtracking method
    void gen(int v1, int v2, vector<string> &vdict, vector<vector<int> >& prev, 
             vector<int>& path, vector<vector<string> >&ans){
             
        path.push_back(v2); // push the nodes into path for back tracking
        
        if(v2 == v1 and path.size() > 1){
            ans.push_back(vector<string>());
            // translate the path of index to string in reverse order
            for(auto rit = path.rbegin(); rit != path.rend(); rit++)
                ans.back().push_back(vdict[*rit]);
        }else{
            // gengrate all possible path in recursive way
            for(int i = 0; i < prev[v2].size(); i++)
                gen(v1, prev[v2][i], vdict, prev, path, ans);
        }
        
        path.pop_back(); // pop the nodes from path for back tracking
    }
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(start);
        dict.insert(end);
        
        vector<string> vdict(dict.begin(), dict.end()); // vector dictionary: id -> word mapping in dict
        unordered_map<string, int> ids;  // index dictionary: word -> id mapping in vdict
        vector<vector<int> > prev(dict.size()); // store the previous words in BFS
        vector<int> distance(dict.size(), -1); // store the distance from start
        
        // build string - index mapping, transfer problem to graph search
        // use interger instead of string to eliminate cost of string matching
        for(int i = 0; i < vdict.size(); i++)
            ids[vdict[i]] = i;
        
        // find the index of start and end words
        int vstr=0, vend=0;
        while(vdict[vstr] != start) vstr++;
        while(vdict[vend] != end) vend++;
        
        // use queue for BFS to search path from start to end
        queue<int> que;
        que.push(vstr);
        distance[vstr]=0;
        
        while(not que.empty()){
            int v1 = que.front(); que.pop();
            if(v1 == vend) break;
            int d = distance[v1] + 1;
            
            // get adjancent list of the words, branching factor of BFS is 26 characters * string size
            vector<int> adj;
            // erase the appeared words from dictionary can save search time
            ids.erase(vdict[v1]);
            
            // find all the words that can be transfered in 1 step
            for(int j = 0; j < vdict[v1].size(); j++){
                char w = vdict[v1][j];
                for(char c = 'a'; c <= 'z'; c++){
                    vdict[v1][j] = c;
                    if(ids.count(vdict[v1]))
                        adj.push_back(ids[vdict[v1]]);
                    vdict[v1][j] = w;
                }
            }
            
            // use BFS to calculate path to end, add new words (distance=-1) into queue
            // if multiple words can reach the same words, save all the words
            for(int i = 0; i < adj.size(); i++){
                int v = adj[i];
                if(distance[v] == -1){
                    prev[v].push_back(v1);
                    distance[v] = d;
                    que.push(v);
                }else if(distance[v] == d){
                    prev[v].push_back(v1);
                }
            }
        }

        // generate the full sting path using the index
        vector<vector<string> > ans;
        vector<int> path;
        gen(vstr, vend, vdict, prev, path, ans);
        return ans;
    }
};