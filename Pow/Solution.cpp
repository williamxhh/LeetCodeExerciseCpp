#include<iostream>
using namespace std;

class Solution {
public:
	double pow(double x, int n) {
		if(n == 0)
			return 1;
		else if(n > 0)
			return powPositive(x,n);
		else
			return 1/powPositive(x,-n);
	}
	
	double powPositive(double x, int n){
		if(n == 0)
			return 1;
		if(n == 1)
			return x;
		
		double half = powPositive(x,n/2);
		return half*half*((n & 0x1) == 0?1:x);
	}
};


int main()
{
	Solution so;
	cout<<so.pow(2,-3)<<endl;
	cout<<so.pow(2.5,4)<<endl;
	cout<<pow(1.00001,123456)<<endl;
	cout<<so.pow(1.00001,123456)<<endl;
}
