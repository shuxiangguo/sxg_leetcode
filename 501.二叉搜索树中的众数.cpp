/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 *
 * https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (42.72%)
 * Likes:    64
 * Dislikes: 0
 * Total Accepted:    6.4K
 * Total Submissions: 15K
 * Testcase Example:  '[1,null,2,2]'
 *
 * 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
 * 
 * 假定 BST 有如下定义：
 * 
 * 
 * 结点左子树中所含结点的值小于等于当前结点的值
 * 结点右子树中所含结点的值大于等于当前结点的值
 * 左子树和右子树都是二叉搜索树
 * 
 * 
 * 例如：
 * 给定 BST [1,null,2,2],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 返回[2].
 * 
 * 提示：如果众数超过1个，不需考虑输出顺序
 * 
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
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
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    void midAccess(TreeNode* root, map<int, int>& dict, int& max) {
        if (root == nullptr) return;
        midAccess(root->left, dict, max);
        dict[root->val] += 1;
        if (dict[root->val] > max) {
            max = dict[root->val];
        }
        midAccess(root->right, dict, max);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        map<int, int> dict;
        int max = 0;
        midAccess(root, dict, max);
        for (auto it : dict) {
            if (it.second == max) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};
// @lc code=end

