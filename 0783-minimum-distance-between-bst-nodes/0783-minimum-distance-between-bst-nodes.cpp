class Solution {
public:
    TreeNode* prev = NULL;

    int minDiffInBST(TreeNode* root) {
        if (root == NULL) {
            return INT_MAX;
        }

        int ans = INT_MAX;

        // Left subtree
        if (root->left != NULL) {
            int leftMin = minDiffInBST(root->left);
            ans = min(ans, leftMin);
        }

        // Compare current node with previous node
        if (prev != NULL) {
            ans = min(ans, root->val - prev->val);
        }

        // Update previous node
        prev = root;

        // Right subtree
        if (root->right != NULL) {
            int rightMin = minDiffInBST(root->right);
            ans = min(ans, rightMin);
        }

        return ans;
    }
};