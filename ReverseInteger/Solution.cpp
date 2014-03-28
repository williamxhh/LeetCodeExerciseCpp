#include<iostream>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		bool positive = true;
		if(x < 0){
			x = -x;
			positive = false;
		}
		x = reversePositive(x);
		if(positive){
			return x;
		}else{
			return -x;
		}
	}

	int reversePositive(int x){
		int result = 0;
		while(x){
			result = (result * 10 + x % 10);
			x = x/10;
		}
		return result;
	}
};

int main(){
	Solution so;
	cout<<so.reverse(123)<<endl;
}
