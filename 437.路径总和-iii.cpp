/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 *
 * https://leetcode-cn.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (52.55%)
 * Likes:    219
 * Dislikes: 0
 * Total Accepted:    14.2K
 * Total Submissions: 26.9K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * 给定一个二叉树，它的每个结点都存放着一个整数值。
 * 
 * 找出路径和等于给定数值的路径总数。
 * 
 * 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 * 
 * 二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
 * 
 * 示例：
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * 返回 3。和等于 8 的路径有:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3.  -3 -> 11
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        sum -= root->val;
        return (sum == 0 ? 1 : 0) + helper(root->left, sum) + helper(root->right, sum);
    }
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
// @lc code=end