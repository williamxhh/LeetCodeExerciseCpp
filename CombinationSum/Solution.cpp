#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<vector<int>> result;
		vector<int> countOfEachElement;
		if(candidates.size() == 0 || target < 0){
			return result;
		}
		
		countOfEachElement.resize(candidates.size());
		sort(candidates.begin(),candidates.end());
		
		solver(candidates,0,candidates.size(),target,countOfEachElement,result);
		return result;
		
	}
	
	void solver(vector<int>& candidates,int position,int maxPosition,int target,vector<int>& countOfEachElement,vector<vector<int>>& result){
		if(position == maxPosition && target == 0){
			vector<int> s;
			for(int i=0;i<countOfEachElement.size();i++){
				for(int j=0;j<countOfEachElement[i];j++){
					s.push_back(candidates[i]);
				}
			}
			result.push_back(s);
		}

		if(position >= maxPosition)
			return;
		
		for(int j=0;j<=target/candidates[position];j++){
			countOfEachElement[position] = j;
			solver(candidates,position+1,maxPosition,target-j*candidates[position],countOfEachElement,result);
		}
	}
};

int main()
{
	Solution so;
	vector<int> candidates(1,1);
	vector<vector<int>> result = so.combinationSum(candidates,1);
	for(vector<vector<int>>::iterator iter1 = result.begin();iter1 != result.end();iter1++)
	{
		for(vector<int>::iterator iter2 = (*iter1).begin();iter2 != (*iter1).end();iter2++)
		{
			cout<<*iter2<<"\t";
		}
		cout<<endl;
	}

}
