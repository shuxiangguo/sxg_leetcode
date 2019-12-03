/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 *
 * https://leetcode-cn.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (57.47%)
 * Likes:    168
 * Dislikes: 0
 * Total Accepted:    11.7K
 * Total Submissions: 20.3K
 * Testcase Example:  '[5,2,13]'
 *
 * 给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater
 * Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
 * 
 * 例如：
 * 
 * 
 * 输入: 二叉搜索树:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 * 
 * 输出: 转换为累加树:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
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
#include<iostream>
using namespace std;

class Solution {
public:
    void converBST_Helper(TreeNode* node, int& sum) {
        if (node != nullptr) {
            converBST_Helper(node->right, sum);
            sum += node->val;
            node->val = sum;
            converBST_Helper(node->left, sum);
        }
    }
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root != nullptr) {
            converBST_Helper(root, sum);
        }
        return root;
    }
};
// @lc code=end

