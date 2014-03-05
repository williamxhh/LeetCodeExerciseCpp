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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> path;
        stack<TreeNode*> stk;
        TreeNode* t = root;
        
        while(t != NULL || !stk.empty()){
            if(t != NULL){
                while(t){
                    path.push_back(t->val);
                    stk.push(t);
                    t = t->left;
                }
            }else{
                t = stk.top()->right;
                stk.pop();
            }
        }
        return path;
    }
};