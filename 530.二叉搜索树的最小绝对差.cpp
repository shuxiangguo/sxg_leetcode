/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 *
 * https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (54.63%)
 * Likes:    80
 * Dislikes: 0
 * Total Accepted:    7.4K
 * Total Submissions: 13.5K
 * Testcase Example:  '[1,null,3,2]'
 *
 * 给定一个所有节点为非负值的二叉搜索树，求树中任意两节点的差的绝对值的最小值。
 * 
 * 示例 :
 * 
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 
 * 输出:
 * 1
 * 
 * 解释:
 * 最小绝对差为1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
 * 
 * 
 * 注意: 树中至少有2个节点。
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
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    //中序遍历， 比较当前结点与前一个结点的差值
    void helper(TreeNode* node, TreeNode*& pre, int& min_num)
    {
        if(node)
        {
            //访问左子树
            helper(node->left, pre, min_num);
            
            //当前结点判断
            if(pre)
                min_num = min(node->val - pre->val, min_num);
            pre = node;
            
            //访问右子树
            helper(node->right, pre, min_num);
        }
    }
    
    int getMinimumDifference(TreeNode* root) {
        int min_num = INT_MAX;
        TreeNode* pre = NULL;
        helper(root, pre, min_num);
        return min_num;
    }
};
// @lc code=end

