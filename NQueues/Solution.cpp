#include<iostream>
#include<vector>
using namespace std;

class Solution {
vector<vector<string>> solutions;
public:
	vector<vector<string> > solveNQueens(int n) {
		solutions.clear();
		vector<int> positions(n);
		traverse_solution_space(positions,0,n);
		return solutions;
	}
	
	void traverse_solution_space(vector<int> positions,int placed,int total){
		if(placed == total){
			generate_solution(positions);
			return ;
		}
		
		//遍历当前行所放置的列号
		for(int column = 0;column < positions.size();column++){
			bool valid = true;
			//与前面的placed-1行检查冲突
			for(int preline = 0;preline < placed;preline++){
				if(column == positions[preline] || abs(column-positions[preline]) == placed - preline){
					valid = false;
					break;
				}
			}
			//都不冲突，就将当前行放在这一位置，然后放置下一行
			if(valid){
				positions[placed] = column;
				traverse_solution_space(positions,placed+1,total);
			}
		}
	}
	
	void generate_solution(const vector<int>& positions){
		vector<string> s;
		for(int i = 0;i<positions.size();i++){
			string line(positions.size(),'.');
			line[positions[i]] = 'Q';
			s.push_back(line);
		}
		solutions.push_back(s);
	}
};