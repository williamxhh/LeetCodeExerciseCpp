#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int sum = 0;
		vector<int> tank;
		for(int i=0;i<gas.size();i++){
			tank.push_back(gas[i] - cost[i]);
			sum += gas[i] - cost[i];
		}
		
		if(sum < 0 || gas.size() == 0){
			return -1;
		}
		
		int begin = 0,end = 0;
		int index = begin;
		int gasInCar = 0;
		while(begin != ((end + 1)%gas.size())){
			gasInCar += tank[index];
			if(gasInCar < 0){
				begin--;
				if(begin < 0){
					begin = gas.size() - 1;
				}
				index = begin;
			}else{
				end++;
				if(end >= gas.size()){
					end = 0;
				}
				index = end;
			}
		}
		
		return begin;
	}
};

int main()
{
	vector<int> gas;
	vector<int> cost;
	gas.push_back(1);
	gas.push_back(2);
	

	cost.push_back(2);
	cost.push_back(1);

	Solution so;
	cout<<so.canCompleteCircuit(gas,cost);
	return 0;

}
