/*
Sort Colors:

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int p0=0, p1=0, p2=0; // end of 0, 1, 2
        while(p2++ != n)
        {
            if(A[p2-1] == 0)
            {
                A[p0++]=0;
                if(++p1!=p0) A[p1-1]=1;
                if(p2!=p1) A[p2-1]=2;
            }
            else if(A[p2-1] == 1)
            {
                A[p1++]=1;
                if(p2!=p1) A[p2-1]=2;
            }
        }
        
    }
};

// ====================================================
#define RED 0
#define WHITE 1
#define BLUE 2

class Solution {
public:
    void sortColors(int A[], int n) {
        int r=-1, w=-1, b=-1; // end of red, white, blue
        while(b<n-1) {
            switch(A[b+1]) {
                case RED:
                    A[++b] = BLUE;
                    A[++w] = WHITE;
                    A[++r] = RED;
                    break;
                case WHITE:
                    A[++b] = BLUE;
                    A[++w] = WHITE;
                    break;
                case BLUE:
                    A[++b] = BLUE;
                    break;
            }
        }
    }
};