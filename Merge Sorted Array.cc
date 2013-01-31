/*
Merge Sorted Array

http://leetcode.com/onlinejudge#question_88

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. 
The number of elements initialized in A and B are m and n respectively.

*/

#include<stdio.h>
#include<iostream>

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // move A[] n steps back
        for(int i=m-1; i>=0; i++)
            A[n+i] = A[i];
        
        int i=0, j=0;
        
        while(i<m && j<n) {
            if(A[i+n] < B[j]) {
                A[i+j] = A[i+n]; 
                i++;
            } else {
                A[i+j] = B[j];
                j++;
            }
        }
        
        while(j<n) {
            A[m+j] = B[j];
        }
    }
};


void main()
{
  int A[100];
  int B[100];
  for(int i=0;i<5;i++)
	  A[i] = i;
  for(int i=0;i<5;i++)
	  B[i] = 5 + i;

  Solution sol;
  sol.merge(A,5,B,5);

  for(int i=0; i<10; i++)
    printf("%d ", A[i]);

  getchar();
}

// =============================================
input: 2 sorted array A, B

output: 1 merger and sorted array = A+B

parameter: int *A, int *B, int sizeA, int sizeB)

output: int *C


pseudo:

int* MergeSorted(A, B, sizeA, sizeB)
{
  if (A == NULL) return B;
  if (B == NULL) return A;
  if (sizeA == 0 || sizeB == 0) return NULL;
  
  int* C = (int *) malloc(sizeof(int) * (sizeA + sizeB));

  int pa = 0, pb = 0, pc = 0;
  while(pa < sizeA && pb < sizeB)
  {
    if(A[pa] < B[pb]) C[pc++] = A[pa++];
    else C[pc++] = B[pb++];
  }

  while(pa < sizeA)
  {C[pc++] = A[pa++];}

  while(pb < sizeB)
  {C[pc++] = B[pb++];}

  return C;
}

case 1: A == NULL && B == NULL
case 2: A == NULL && B != NULL
        A != NULL && B == NULL
case 3: sizeA == 0 || sizeB == 0
case 4: sizeA == 1 && sizeB == 1
case 5: A and B are unsorted

