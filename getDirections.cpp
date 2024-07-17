struct TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode()  val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x)  val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode left, TreeNode right)  val(x), left(left), right(right) {}
};

class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);
        string pathToStart, pathToDest;
        findPath(lca, startValue, pathToStart);
        findPath(lca, destValue, pathToDest);
        return string(pathToStart.size(), 'U') + pathToDest;
    }

private:
    TreeNode* findLCA(TreeNode* root, int startValue, int destValue) {
        if (!root || root->val == startValue || root->val == destValue)
            return root;
        TreeNode* left = findLCA(root->left, startValue, destValue);
        TreeNode* right = findLCA(root->right, startValue, destValue);
        if (left && right)
            return root;
        return left ? left : right;
    }

    bool findPath(TreeNode* root, int target, string& path) {
        if (!root)
            return false;
        if (root->val == target)
            return true;
        path.push_back('L');
        if (findPath(root->left, target, path))
            return true;
        path.pop_back();
        path.push_back('R');
        if (findPath(root->right, target, path))
            return true;
        path.pop_back();
        return false;
    }
};
