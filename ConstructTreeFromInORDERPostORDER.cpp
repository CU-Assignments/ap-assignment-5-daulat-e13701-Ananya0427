class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd, 
                              vector<int>& postorder, int postStart, int postEnd, 
                              unordered_map<int, int>& inMap) {
        if (inStart > inEnd || postStart > postEnd) return nullptr;

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        int inRoot = inMap[rootVal];
        int leftSize = inRoot - inStart;

        root->left = buildTreeHelper(inorder, inStart, inRoot - 1, 
                                     postorder, postStart, postStart + leftSize - 1, inMap);
        root->right = buildTreeHelper(inorder, inRoot + 1, inEnd, 
                                      postorder, postStart + leftSize, postEnd - 1, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap; 
        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;

        return buildTreeHelper(inorder, 0, inorder.size() - 1, 
                               postorder, 0, postorder.size() - 1, inMap);
    }
};
