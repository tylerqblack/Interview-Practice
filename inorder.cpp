//Recursive solution first
//algo left, node, right

class Solution {
public:
    void inorder(TreeNode* root,vector<int> &path){
        if(root != nullptr){
            inorder(root->left, path);
            path.push_back(root->val);
            inorder(root->right, path);
        }
        return;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> path;
        inorder(root, path);
        return path;
    }
};

//iterative solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<int> path;
        stack<TreeNode*> stack;
        TreeNode* curr = root;
        
        while(!stack.empty() || curr != nullptr){
            if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            path.push_back(curr->val);
 
            curr = curr->right;
        }
        }
        return path;
    }
};