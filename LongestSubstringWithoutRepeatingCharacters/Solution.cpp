#include<iostream>
using namespace std;

class Solution {
private:
	bool canUse[256];
public:
	int lengthOfLongestSubstring(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		memset(canUse, true, sizeof(canUse));
		
		int count = 0;
		int start = 0;
		int ret = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if (canUse[s[i]])
			{
				canUse[s[i]] = false;
				count++;
			}
			else
			{
				ret = max(ret, count);
				while(true)
				{
					canUse[s[start]] = true;
					count--;
					if (s[start] == s[i])
						break;
					start++;
				}
				start++;
				canUse[s[i]] = false;
				count++;
			}
		}
		
		ret = max(ret, count);
		
		return ret;
	}
};

int main()
{
	string s = "abcad";
	Solution so;
	cout<<so.lengthOfLongestSubstring(s)<<endl;
}
