#include<iostream>
using namespace std;

class Solution {
public:
	int search(int A[], int n, int target) {
		int index = 0;
		for(int i=1;i<n;i++){
			if(A[i-1] > A[i]){
				index = i;
				break;
			}
		}
		if(target == A[0]){
			return 0;
		}else if(target > A[0]){
			if(index == 0){
				return bSearch(A,n,target);
			}else{
				return bSearch(A,index,target);
			}
		}else{
			int position = bSearch(&A[index],n - index,target);
			if(position == -1){
				return -1;
			}else{
				return position + index;
			}
		}
	}
	
	int bSearch(int A[],int n,int target){
		int min = 0;
		int max = n-1;
		int mid;
		while(true){
			mid = (min+max)/2;
			if(target == A[mid]){
				return mid;
			}else if(target < A[mid]){
				max = mid -1;
			}else{
				min = mid + 1;
			}
			if(min > max)
				break;
		}
		return -1;
	}
};

int main()
{
	int a[] = {1,3};
	Solution so;
	cout<<so.search(a,2,3)<<endl;
}
