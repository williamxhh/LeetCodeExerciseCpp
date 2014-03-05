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

		//��������vector�ֱ��¼T�г�������Щ��ĸ�����ֵĴ������Լ���ǰS��Ƭ�ΰ�������Щ��ĸ�����ֵĴ���
		vector<int> needInT(256,0);
		vector<int> containInS(256,0);

		//�Ƚ�Tɨ��һ�飬����ĸ���ֵ����load��vector��
		for(int i = 0; i < T.size(); i++)
			needInT[T[i]]++;

		int validCount = 0;
		int containEnd;
		//ɨ��S���ҳ���S��ͷ��ʼ��һֱ������T�е���ĸ�����ֵ�һ���ַ�Ƭ�Σ��ҵ��ַ�Ƭ�ε�ĩβcontainEnd
		for(containEnd = 0;containEnd < S.size();containEnd++)
		{
			if(containInS[S[containEnd]] < needInT[S[containEnd]])
			{
				//validCountָʾ��ǰ�Ѿ�������ַ���Ŀ
				validCount++;
			}
			containInS[S[containEnd]]++;
			//T���ַ��Ѿ�ȫ�����֣���ʱ�˳�ѭ��
			if(validCount == T.size()) break;
		}
		if(containEnd == S.size())
			return "";

		int minStartIndex = 0;

		//ɨ��S������ѹ��Start��λ��
		while(minStartIndex < S.size() && containInS[S[minStartIndex]] > needInT[S[minStartIndex]])
		{
			containInS[S[minStartIndex]]--;
			minStartIndex++;
		}

		int currentStart = minStartIndex;
		int minEnd = containEnd;
		//����Ѱ�Ҹ��̵��ַ�Ƭ��
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