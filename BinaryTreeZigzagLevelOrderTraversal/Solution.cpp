#include<iostream>
#include<vector>
#include<stack>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> result;
		if(root == NULL)
			return result;

		stack<TreeNode*> nodeStack;
		vector<int> levelNodes;
		nodeStack.push(NULL);
		nodeStack.push(root);
		int level = 0;

		while(!nodeStack.empty()){
			TreeNode* cur = nodeStack.top();
			nodeStack.pop();
			if(cur == NULL){
				if(!levelNodes.empty()){
					result.push_back(levelNodes);
					levelNodes.clear();
					nodeStack.push(NULL);
					level++;
				}
			}else{
				levelNodes.push_back(cur->val);
				if(level & 1 == 0){
					if(cur->left)
						nodeStack.push(cur->left);
					if(cur->right)
						nodeStack.push(cur->right);
				}else{
					if(cur->right)
						nodeStack.push(cur->right);
					if(cur->left)
						nodeStack.push(cur->left);
				}
			}
		}

		return result;
	}
};

int main()
{
	Solution so;
	TreeNode* t = new TreeNode(1);
	so.zigzagLevelOrder(t);
}
