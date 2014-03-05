#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	string minWindow(string S, string T) {
		if(S.size() == 0 || T.size() == 0 || T.size() > S.size())
		{
			return "";
		}

		//以下两个vector分别记录T中出现了哪些字母，出现的次数，以及当前S的片段包含了哪些字母，出现的次数
		vector<int> needInT(256,0);
		vector<int> containInS(256,0);

		//先将T扫描一遍，将字母出现的情况load到vector中
		for(int i = 0; i < T.size(); i++)
			needInT[T[i]]++;

		int validCount = 0;
		int containEnd;
		//扫描S，找出从S的头开始，一直到所有T中的字母都出现的一个字符片段，找到字符片段的末尾containEnd
		for(containEnd = 0;containEnd < S.size();containEnd++)
		{
			if(containInS[S[containEnd]] < needInT[S[containEnd]])
			{
				//validCount指示当前已经满足的字符数目
				validCount++;
			}
			containInS[S[containEnd]]++;
			//T中字符已经全部出现，此时退出循环
			if(validCount == T.size()) break;
		}
		if(containEnd == S.size())
			return "";

		int minStartIndex = 0;

		//扫描S，向右压缩Start的位置
		while(minStartIndex < S.size() && containInS[S[minStartIndex]] > needInT[S[minStartIndex]])
		{
			containInS[S[minStartIndex]]--;
			minStartIndex++;
		}

		int currentStart = minStartIndex;
		int minEnd = containEnd;
		//向右寻找更短的字符片段
		for(int i = minEnd+1;i < S.size();i++)
		{
			containInS[S[i]]++;
			int newStart = currentStart;
			while(containInS[S[newStart]] > needInT[S[newStart]])
			{
				containInS[S[newStart]]--;
				newStart++;
			}
			currentStart = newStart;
			if((i-newStart) < (minEnd - minStartIndex))
			{
				minEnd = i;
				minStartIndex = newStart;
			}

		}
		return S.substr(minStartIndex,minEnd - minStartIndex + 1);
	}
};

int main()
{
	string s = "ADOBECODEBANC";
	string t = "ABC";
	Solution so;
	cout<<so.minWindow(s,t)<<endl;
}