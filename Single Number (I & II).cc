/*
Single Number

http://oj.leetcode.com/problems/single-number/

Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

=======================================================================

Single Number II

http://oj.leetcode.com/problems/single-number-ii/

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

*/

// =======================================================================
// Single Number

class Solution {
public:
    int singleNumber(int A[], int n) {
        int x=0;
        for(int i=0; i<n; ++i)
            x ^= A[i];
        return x;
    }
};

// =======================================================================
// Single Number II
// Reference:
// Finding an element in an array where every element is repeated odd number of times and only one appears once
// http://stackoverflow.com/questions/7338070

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0, threes = 0;
        for (int i=0; i<n; ++i) {
            twos |= ones & A[i];
            ones ^= A[i];
            threes = ~(ones & twos);
            ones &= threes;
            twos &= threes;
        }
        return ones;
    }
};

// =======================================================================
// Single Number I & II
// Version 2

class Solution {
public:
    int singleNumber(int A[], int n) {
        int countBit[32], result=0, freq = 3; // freq set to frequency of every element appears except for one
        memset(countBit, 0, sizeof(countBit));

        for (int i=0; i<n; ++i)
            for(int bit=0; bit<32; ++bit) // for each bit in the numbers
                countBit[bit] += ((A[i] >> bit) & 1); // count the appear times of each bit

        for(int bit=0; bit<32; ++bit)
            if(countBit[bit] % freq != 0) // find the bits that appears different than n times
                result |= 1 << bit; // flip the bit on result

        return result;
    }
};