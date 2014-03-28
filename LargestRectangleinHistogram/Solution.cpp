#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {  
public:  
	int Max(int a, int b){return a > b ? a : b;}  
	int largestRectangleArea(vector<int> &height) {  
		height.push_back(0);  
		stack<int> stk;  
		int i = 0;  
		int maxArea = 0;  
		while(i < height.size()){  
			if(stk.empty() || height[stk.top()] <= height[i]){  
				stk.push(i++);  
			}else {  
				int t = stk.top();  
				stk.pop();  
				maxArea = Max(maxArea, height[t] * (stk.empty() ? i : i - stk.top() - 1));  
			}  
		}  
		return maxArea;  
	}  
};  

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(100);
	v.push_back(100);
	v.push_back(99);
	v.push_back(100);
	v.push_back(100);
	v.push_back(1);
	Solution so;
	cout<<so.largestRectangleArea(v)<<endl;
}
