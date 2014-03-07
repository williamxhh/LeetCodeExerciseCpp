#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		vector<int> count(n+1,0);
		if(n < 2){
			return 1;
		}else{
			count[0] = 1;
			count[1] = 1;
		}
		return countTrees(n,count);
	}
	
	int countTrees(int n,vector<int>& count){
		if(count[n] != 0){
			return count[n];
		}else{
			for(int i=0;i<n;i++){
				count[n] += countTrees(i,count)*countTrees(n-i-1,count);
			}
			return count[n];
		}
	}
};

int main()
{
	Solution so;
	cout<<so.numTrees(3)<<endl;
}
