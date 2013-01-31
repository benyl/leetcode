/*
Add Binary
Given two binary strings, return their sum (also a binary string).

For example,
a = 11
b = 1
Return 100.
*/

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size())
		{
			string c = a;
			a = b;
			b = c;
		}
		
		int i = a.size()-1;
		int j = b.size()-1;
		int carry = 0;

		while(i>=0)
		{
			int sum = (a[i]-48) + carry;
            if(j>=0) sum += (b[j]-48);
            
			a[i] = sum%2 + 48;
			carry = sum / 2;
			
			i--; j--;
		}

		if(carry!=0)
			a = "1" + a;
		
		return a;
    }
};

void main()
{
	string a = "1";
	string b = "1111";
	
	Solution sol;
	string c = sol.addBinary(a,b);
	
	cout << a << " + " << b << " = " << c << endl;
	getchar();
}