#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > result;
		if(numRows <= 0){
			return result;
		}
		vector<int> line;
		
		for(int i = 1;i <= numRows;i++){
			if(i == 1){
				line.push_back(1);
			}else{
				line.push_back(1);
				for(int j=1;j<i-1;j++){
					line.push_back(result[i-1-1][j-1] + result[i-1-1][j]);
				}
				line.push_back(1);
			}
			result.push_back(line);
			line.clear();
		}
		return result;
	}
};

int main(){
	Solution so;
	so.generate(3);
}
