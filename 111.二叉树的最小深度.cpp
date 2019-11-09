/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (40.27%)
 * Likes:    164
 * Dislikes: 0
 * Total Accepted:    33.7K
 * Total Submissions: 83.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
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
#include<stack>
#include<climits>

using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        stack<pair<TreeNode*, int>> stack;
        stack.push(make_pair(root, 1));
        int res = INT_MAX;

        while (!stack.empty()) {
            TreeNode* node = stack.top().first;
            int depth = stack.top().second;
            stack.pop();

            if (node->left == nullptr && node->right == nullptr) {
                res = min(res, depth);
            }
            if (node->left) {
                stack.push(make_pair(node->left, depth+1));
            }
            if (node->right) {
                stack.push(make_pair(node->right, depth+1));
            }
        }
        return res;
        
    }
};
// @lc code=end

