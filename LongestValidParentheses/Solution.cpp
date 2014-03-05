#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int validLen = 0;
		stack<int> stk;
		int* lengthArray;
		lengthArray= new int[s.size()];
		memset(lengthArray,0,sizeof(int)*s.size());
		for(int i = 0;i < s.size();i++){
			if(s[i] == '('){
				stk.push(i);
			}else{
				if(!stk.empty()){
					int index = stk.top();
					lengthArray[i] = i - index + 1 + (index > 0 ? lengthArray[index - 1] : 0);
					if(lengthArray[i] > validLen)
						validLen = lengthArray[i];
					stk.pop();
				}
			}
		}
		return validLen;
	}
};