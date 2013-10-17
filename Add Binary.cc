/*
Add Binary
Given two binary strings, return their sum (also a binary string).

For example,
a = 11
b = 1
Return 100.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()) swap(a, b);
		int i=a.size()-1, j=b.size()-1, carry=0;

		while(i>=0) {
			int sum = (a[i]-'0') + carry;
            if(j>=0) sum += (b[j]-'0');
            
			a[i] = sum%2 + '0';
			carry = sum / 2;
			
			--i; --j;
		}

		if(carry!=0) a = "1" + a;
		
		return a;
    }
};