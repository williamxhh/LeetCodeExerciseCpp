#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int row = triangle.size();
		//假象在triangle的最下一行下面有一行全为0
		vector<int> sums(row+1,0);
		//自底向上的做
		while(row-- > 0){
			//动态规划，每一行的每一个位置i都是它的当前值和它下一行的位置i和i+1中取小的
			//这里i是从左往右做，更新了sums[i]后，不影响下一轮更新sums[i+1],从右往左就不行
			for(int i = 0;i < triangle[row].size();i++){
				sums[i] = triangle[row][i] + min(sums[i],sums[i+1]);
			}
		}
		return sums[0];
	}
};