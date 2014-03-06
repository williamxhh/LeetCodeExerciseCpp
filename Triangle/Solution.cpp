#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int row = triangle.size();
		//������triangle������һ��������һ��ȫΪ0
		vector<int> sums(row+1,0);
		//�Ե����ϵ���
		while(row-- > 0){
			//��̬�滮��ÿһ�е�ÿһ��λ��i�������ĵ�ǰֵ������һ�е�λ��i��i+1��ȡС��
			//����i�Ǵ�����������������sums[i]�󣬲�Ӱ����һ�ָ���sums[i+1],��������Ͳ���
			for(int i = 0;i < triangle[row].size();i++){
				sums[i] = triangle[row][i] + min(sums[i],sums[i+1]);
			}
		}
		return sums[0];
	}
};