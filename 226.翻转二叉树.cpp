/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 *
 * https://leetcode-cn.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (72.24%)
 * Likes:    284
 * Dislikes: 0
 * Total Accepted:    35.5K
 * Total Submissions: 49.1K
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * 翻转一棵二叉树。
 * 
 * 示例：
 * 
 * 输入：
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 2     7
 * ⁠/ \   / \
 * 1   3 6   9
 * 
 * 输出：
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 7     2
 * ⁠/ \   / \
 * 9   6 3   1
 * 
 * 备注:
 * 这个问题是受到 Max Howell 的 原问题 启发的 ：
 * 
 * 谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
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
    // TreeNode* invertTree(TreeNode* root) {
    //     if (root == nullptr) return nullptr;
    //     TreeNode *left = invertTree(root->left);
    //     TreeNode *right = invertTree(root->right);

    //     root->left = right;
    //     root->right = left;
    //     return root;
    // }
    #include<deque>
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        deque<TreeNode*> q;
        q.push_back(root);
        TreeNode *tmp, *t;
        while (!q.empty()) {
            tmp = q.back();
            q.pop_back();
            
            // 只要存在一个子节点，都要交换，只有左右孩子节点都不存在，才不交换
            if (tmp->left || tmp->right) {
                t = tmp->right;
                tmp->right = tmp->left;
                tmp->left = t;
            }

            if (tmp->left) q.push_back(tmp->left);
            if (tmp->right) q.push_back(tmp->right);
        }
        return root;
    }
};
// @lc code=end

