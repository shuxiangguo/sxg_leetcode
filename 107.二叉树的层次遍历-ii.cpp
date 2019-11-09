/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (62.84%)
 * Likes:    141
 * Dislikes: 0
 * Total Accepted:    27.8K
 * Total Submissions: 44.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res; // 存放结果的vector
        if (root == nullptr) {
            return res;
        }

        // 定义一个队列，用来存放每层的节点，后续遍历每次取一层的节点
        queue<TreeNode*> q;

        // 首先将root插入到队列q中
        q.push(root);

        // 关键代码：每次更新q,每次的q都存了一层的节点信息
        while (!q.empty()) {
            vector<int> temp; // 临时变量，存放当前层的节点信息
            int len = q.size();
            for (int i = 0; i < len; i++) {
                // 获取队列第一个
                TreeNode *now = q.front();
                q.pop();
                temp.push_back(now->val);

                // 将该节点的子节点存入队列
                if (now->left) {
                    q.push(now->left);
                }
                if (now->right) {
                    q.push(now->right);
                }
            }
            res.push_back(temp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

