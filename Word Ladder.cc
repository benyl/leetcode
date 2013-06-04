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
class Solution {
public:
    // version 1, Time Limit Exceeded
    int ladderLength1(string start, string end, unordered_set<string> &dict) {
        if(start == end) return 0;
        if(start.size() != end.size()) return 0;
        if(trans(start, end)) return 2;
        
        dict.erase(start);
        
        queue<pair<string, int> > que; // queue of string and len
        for(auto it = dict.begin(); it != dict.end(); ++it) {
            if(trans(*it, start)) 
                que.push(make_pair(*it, 2));
        }
        
        while(!que.empty()) {
            string str = que.front().first;
            int len = que.front().second;
            que.pop();
            
            if(trans(str, end)) return len+1;
            
            dict.erase(str);
            for(auto it = dict.begin(); it != dict.end(); ++it) {
                if(trans(*it, end)) 
                    que.push(make_pair(*it, len+1));
            }
        }
        
        return 0;
    }
    
    bool trans(string start, string end) {
        if(start.size() != end.size()) return false;
        
        int step = 0;
        for(int i=0; i<start.size(); i++) {
            if(start[i] != end[i]) {
                step++;
            }
        }
        return step < 2;
    }
};

//=======================================================================
// Word Ladder I
// version 2
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start == end) return 0;
        if(start.size() != end.size()) return 0;
        
        queue<pair<string, int> > que; // queue of string and len
        que.push(make_pair(start, 1));
        
        while(!que.empty()) {
            string str = que.front().first;
            int len = que.front().second;
            que.pop();
            
            dict.erase(str);
            
            for(int i=0; i<str.size(); i++)
            for(char c='a'; c<='z'; c++) {
                char chi = str[i];
                str[i] = c;
                
                if(str == end) return len+1;
                
                if(dict.count(str) != 0) {
                    que.push(make_pair(str, len+1));
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
// version 1, Time Limit Exceeded
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > result;
        if(start == end) return result;
        if(start.size() != end.size()) return result;
        
        queue<vector<string> > q1, q2; // queue of full path and curr string
		queue<vector<string> > &curr = q1, next = q2; // queue of full path and curr string
        vector<string> dellst;
        curr.push(vector<string>(1, start));
        
        while(!curr.empty() || !next.empty()) {
			if(curr.empty()) {
				if(!result.empty())
					break;
				curr = (curr == q1)?q2:q1;
				next = (next == q2)?q1:q2;
                for(int i=0; i<dellst.size(); i++)
                    dict.erase(dellst[i]);
                dellst.clear();
                if(dict.empty()) break;
			}

            vector<string> path = curr.front();
            string str = path.back();
            curr.pop();
            
            for(int i=0; i<str.size(); i++)
            for(char c='a'; c<='z'; c++) {
                char chi = str[i];
                str[i] = c;
                
                if(str == end) {
					vector<string> p(path);
                    p.push_back(str);
                    result.push_back(p);
                    dellst.push_back(str);
                } else if(result.empty() && dict.count(str) != 0) {
                    vector<string> p(path);
                    p.push_back(str);
                    next.push(p);
                    dellst.push_back(str);
                }
                
                str[i] = chi;
            }
        }
        return result;
    }
};

//=======================================================================
// Word Ladder II
// version 2
class Solution {
    void build(unordered_set<string> &dict, vector<string> &vdict, vector<vector<int> > &adj){
        unordered_map<string, int> ids;
        for(int i = 0; i < vdict.size(); i++)
            ids[vdict[i]] = i;
        
        for(int i = 0; i < vdict.size(); i++){
            ids.erase(vdict[i]);
            for(int j = 0; j < vdict[i].size(); j++){
                char w = vdict[i][j];
                for(char c = 'a'; c <= 'z'; c++){
                    vdict[i][j] = c;
                    if(ids.count(vdict[i])) {
                        int id = ids[vdict[i]];
                        adj[i].push_back(id);
                        adj[id].push_back(i);
                    }
                    vdict[i][j] = w;
                }
            }
        }
    }

    void gen(int v1, int v2, vector<string> &vdict, vector<vector<int> >& prev, vector<int>& path, vector<vector<string> >&ans){
        path.push_back(v2);
        if(v2 == v1 and path.size() > 1){
            ans.push_back(vector<string>());
            for(auto rit = path.rbegin(); rit != path.rend(); rit++)
                ans.back().push_back(vdict[*rit]);
        }else{
            for(int i = 0; i < prev[v2].size(); i++)
                gen(v1, prev[v2][i], vdict, prev, path, ans);
        }
        path.pop_back();
    }
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(start);
        dict.insert(end);
        vector<string> vdict(dict.begin(), dict.end()); // id -> word mapping in dict
        vector<vector<int> > adj(dict.size()); // adjacent list of words
        vector<vector<int> > prev(dict.size()); // previous words in BFS
        vector<int> distance(dict.size(), -1); // distance from start
        
        build(dict, vdict, adj); // build adjacent list
        
        // use BFS to search path from start to end
        queue<int> que;
        int vstr=0, vend=0;
        while(vdict[vstr] != start) vstr++;
        while(vdict[vend] != end) vend++;
        que.push(vstr);
        distance[vstr]=0;
        
        while(not que.empty()){
            int v1 = que.front(); que.pop();
            if(v1 == vend) break;
            int d = distance[v1] + 1;
            for(int i = 0; i < adj[v1].size(); i++){
                int v = adj[v1][i];
                if(distance[v] == -1){
                    prev[v].push_back(v1);
                    distance[v] = d;
                    que.push(v);
                }else if(distance[v] == d){
                    prev[v].push_back(v1);
                }
            }
        }

        vector<vector<string> > ans;
        vector<int> path;
        gen(vstr, vend, vdict, prev, path, ans);
        return ans;
    }
};

//=======================================================================
// Word Ladder II
// version 3, faster and cleaner
class Solution {
    void gen(int v1, int v2, vector<string> &vdict, vector<vector<int> >& prev, 
             vector<int>& path, vector<vector<string> >&ans){
        path.push_back(v2);
        if(v2 == v1 and path.size() > 1){
            ans.push_back(vector<string>());
            for(auto rit = path.rbegin(); rit != path.rend(); rit++)
                ans.back().push_back(vdict[*rit]);
        }else{
            for(int i = 0; i < prev[v2].size(); i++)
                gen(v1, prev[v2][i], vdict, prev, path, ans);
        }
        path.pop_back();
    }
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(start);
        dict.insert(end);
        
        vector<string> vdict(dict.begin(), dict.end()); // id -> word mapping in dict
        unordered_map<string, int> ids;  // word -> id mapping in vdict
        vector<vector<int> > prev(dict.size()); // previous words in BFS
        vector<int> distance(dict.size(), -1); // distance from start
        
        for(int i = 0; i < vdict.size(); i++)
            ids[vdict[i]] = i;
        
        // use BFS to search path from start to end
        queue<int> que;
        int vstr=0, vend=0;
        while(vdict[vstr] != start) vstr++;
        while(vdict[vend] != end) vend++;
        que.push(vstr);
        distance[vstr]=0;
        
        while(not que.empty()){
            int v1 = que.front(); que.pop();
            if(v1 == vend) break;
            int d = distance[v1] + 1;
            
            // get adjancent list here
            vector<int> adj;
            ids.erase(vdict[v1]);
            for(int j = 0; j < vdict[v1].size(); j++){
                char w = vdict[v1][j];
                for(char c = 'a'; c <= 'z'; c++){
                    vdict[v1][j] = c;
                    if(ids.count(vdict[v1]))
                        adj.push_back(ids[vdict[v1]]);
                    vdict[v1][j] = w;
                }
            }
            
            // calculate path
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

        vector<vector<string> > ans;
        vector<int> path;
        gen(vstr, vend, vdict, prev, path, ans);
        return ans;
    }
};