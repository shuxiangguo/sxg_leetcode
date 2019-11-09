/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (71.10%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    84.7K
 * Total Submissions: 119.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 * 
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最大深度 3 。
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
using namespace std;
class Solution {
public:
    //递归版本
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    }

    // 迭代版本
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        stack<pair<TreeNode*, int>> s;

        TreeNode *p = root;
        int maxDepth = 0;
        int deep = 0;

        //若栈非空，则说明还有一些节点的右子树尚未探索；若p非空，意味着还有一些节点的左子树尚未探索
        while (!s.empty() || p != nullptr) {
            while (p != nullptr) {
                s.push(pair<TreeNode*,int>(p, ++deep));
                p = p->left;
            }
            // 如果没有左孩子了，就准备去找右拐。右拐之前，记录右拐节点的信息
            p = s.top().first;
            deep = s.top().second;
            //预备右拐时，比较当前节点深度和之前存储的最大深度
            if (maxDepth < deep) maxDepth = deep;

            //将右拐点出栈；此时栈顶为右拐点的前一个结点。在右拐点的右子树全被遍历完后，会预备在这个节点右拐
            s.pop();
            p = p->right;
        }
        return maxDepth;

    }
};
// @lc code=end

