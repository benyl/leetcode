/*
Search for a Range

http://leetcode.com/onlinejudge#question_34

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/


class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result(2,-1);
        if(A[0]>target) return result;
        if(A[n-1]<target) return result;
        
        // find the lower bound
        if(A[0]==target) result[0]=0;
        else {
            int imin=0, imax=n;
            while(imin<=imax){
                int imid=(imin+imax)/2;
                    
                if(A[imid]<target)
                    imin = imid + 1;
                else if(A[imid]>target)
                    imax = imid - 1;
                else if(imid==0)
                    {result[0]=0;break;}
                else if(A[imid-1]!=target)
                    {result[0]=imid;break;}
                else imax = imid - 1;
            }
        }
        
        // find the upper bound
        if(A[n-1]==target) result[1]=n-1;
        else {
            int imin=0, imax=n;
            while(imin<=imax){
                int imid=(imin+imax)/2;
                    
                if(A[imid]<target)
                    imin = imid + 1;
                else if(A[imid]>target)
                    imax = imid - 1;
                else if(imid==n-1)
                    {result[1]=n-1;break;}
                else if(A[imid+1]!=target)
                    {result[1]=imid;break;}
                else imin = imid + 1;
            }
        }
        
        return result;
    }
};