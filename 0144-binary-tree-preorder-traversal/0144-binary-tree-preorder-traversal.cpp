class Solution {
private:
    vector<int> res;

public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL)
            return res;

        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return res;
    }
};