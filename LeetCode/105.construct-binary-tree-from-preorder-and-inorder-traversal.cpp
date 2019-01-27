/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (38.78%)
 * Total Accepted:    192.4K
 * Total Submissions: 496K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
 * reference: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34538/My-Accepted-Java-Solution
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0, 0, inorder.size()-1, preorder, inorder);
    }

private:
    TreeNode* helper(int preBeg, int inBeg, int inEnd, vector<int>& preorder, vector<int>& inorder) {
        if (preBeg >= preorder.size() || inBeg > inEnd) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[preBeg]);

        int index = inBeg;
        while (index <= inEnd && inorder[index] != root->val) {
            index++;
        }

        root->left = helper(preBeg+1, inBeg, index-1, preorder, inorder);
        root->right = helper(preBeg+index-inBeg+1, index+1, inEnd, preorder, inorder);

        return root;
    }
};
