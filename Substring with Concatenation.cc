/*
Substring with Concatenation of All Words

http://leetcode.com/onlinejudge#question_30

You are given a string, S, and a list of words, L, that are all of the same length. 
Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        if(L.size() == 0) return vector<int>();
        if(S.size() < L.size() * L[0].size()) return vector<int>();
        
        vector<int> result;
        
        vector<string> words;
        vector<int> count;
        int total = 0;
        
        sort(L.begin(), L.end());
        
        for(int i=0; i<L.size(); i++) {
            if(i!=0 && L[i] == L[i-1])
                count[count.size()-1]++;
            else {
                words.push_back(L[i]);
                count.push_back(1);
            }
        }
        
        int sumlen = L.size() * L[0].size();
        
        for(int i=0; i<S.size()-sumlen+1; i++) {
            if(matchString(S, i, words, count)) 
                result.push_back(i);
        }
        
        return result;
    }
    
    bool matchString(string S, int idx, vector<string> &words, vector<int> &count) {
        vector<int> found(count.size(), 0);
        int sum = 0;
        
        while(sum < words.size()) {
            string str = S.substr(idx, words[0].size());
			if(str<words[0]) return false;
			if(str>words[words.size()-1]) return false;
            for(int i=0; i<words.size(); i++) {
                if(str == words[i]) {
                    found[i]++;
                    if(found[i] == count[i]) sum++;
                    if(found[i] > count[i]) return false;
                    idx += words[0].size();
                    break;
                } else if(str < words[i]) return false;
            }
        }
        
        return true;
    }
    
    // version 2, use map
    vector<int> findSubstring2(string S, vector<string> &L) {
        map<string, int> words;
    	map<string, int> curStr;
		for(int i = 0; i < L.size(); ++i)
			++words[L.at(i)];
		int N = L.size();
		vector<int> ret;
		if(N <= 0)	return ret;
		int M = L.at(0).size();
		for(int i = 0; i <= (int)S.size()-N*M; ++i)
		{
			curStr.clear();
			int j = 0;
			for(j = 0; j < N; ++j)
			{
				string w = S.substr(i+j*M, M);
				if(words.find(w) == words.end())
					break;
				++curStr[w];
				if(curStr[w] > words[w])
					break;
			}
			if(j == N)	ret.push_back(i);
		}
		return ret;
    }
};


// version 3, use hash
class Solution {
 private:
     int count[1000];
     int countSize;
     map<string, int> index;
     vector<int> ret;
 public:
     vector<int> findSubstring(string S, vector<string> &L) {
         ret.clear();
         if (L.size() == 0)
             return ret;
 
         index.clear();
         countSize = 0;
         for(int i = 0; i < L.size(); i++)
             if (index.count(L[i]) > 0)
                 count[index[L[i]]]++;
             else
             {
                 index[L[i]] = countSize;
                 count[countSize++] = 1;
             }
 
             int step = L[0].size();
 
             vector<int> a;
 
             for(int i = 0; i < step; i++)
             {
                 a.clear();
                 for(int j = i; j < S.size(); j += step)
                 {
                     if (j + step <= S.size())
                     {
                         string s(S, j, step);
                         if (index.count(s) > 0)
                             a.push_back(index[s]);
                         else
                             a.push_back(-1);
                     }
                 }
 
                 int beg = -1;
                 int end = 0;
                 int size = L.size();
                 while(end < a.size())
                 {
                     if (a[end] != -1)
                     {
                         if (count[a[end]] > 0)
                         {
                             if (beg == -1)
                                 beg = end;
                             size--;
                             count[a[end]]--;
                         }
                         else
                         {
                             while(beg < end)
                             {
                                 count[a[beg]]++;
                                 size++;
                                 if (a[beg++] == a[end])
                                     break;
                             }
                             count[a[end]]--;
                             size--;
                         }
                     }
                     else
                     {
                         size = L.size();
                         if (beg != -1)
                         {    
                             for(int i = beg; i < end; i++)
                                 count[a[i]]++;
                         }
                         beg    = -1;
                     }
 
                     end++;
 
                     if (size == 0)
                     {
                         ret.push_back(beg * step + i);
                         size++;
                         count[a[beg]]++;
                         beg++;
                     }
                 }
 
                 if (beg != -1)
                 {
                     for(int i = beg; i < end; i++)
                         count[a[i]]++;
                 }
             }
 
             return ret;
     }
 };