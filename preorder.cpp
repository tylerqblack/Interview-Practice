//Recursive solution first. 
//Algo: Node -> left -> right

class Solution {
public:
    void preorder(TreeNode* root, vector<int> &path){
        if(root!=nullptr){
            path.push_back(root->val);
            preorder(root->left, path);
            preorder(root->right, path);
        }
        return;
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> path;
        preorder(root, path);
        return path;
    }
};

//iterative solution

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr){ //base case
            return {};
        }
        vector<int> path;
        stack<TreeNode*> stack;
        stack.push(root);
        
        while(!stack.empty()){
            root = stack.top();
            stack.pop();
            path.push_back(root->val);
            if(root->right){
                stack.push(root->right);
            }
            if(root->left){
                stack.push(root->left);
            }
        }
        return path;
    }
};