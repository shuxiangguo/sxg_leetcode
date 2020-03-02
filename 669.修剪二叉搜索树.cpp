/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
 *
 * https://leetcode-cn.com/problems/trim-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (63.24%)
 * Likes:    147
 * Dislikes: 0
 * Total Accepted:    7.8K
 * Total Submissions: 12.4K
 * Testcase Example:  '[1,0,2]\n1\n2'
 *
 * 给定一个二叉搜索树，同时给定最小边界L 和最大边界 R。通过修剪二叉搜索树，使得所有节点的值在[L, R]中 (R>=L)
 * 。你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * ⁠   1
 * ⁠  / \
 * ⁠ 0   2
 * 
 * ⁠ L = 1
 * ⁠ R = 2
 * 
 * 输出: 
 * ⁠   1
 * ⁠     \
 * ⁠      2
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 
 * ⁠   3
 * ⁠  / \
 * ⁠ 0   4
 * ⁠  \
 * ⁠   2
 * ⁠  /
 * ⁠ 1
 * 
 * ⁠ L = 1
 * ⁠ R = 3
 * 
 * 输出: 
 * ⁠     3
 * ⁠    / 
 * ⁠  2   
 * ⁠ /
 * ⁠1
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root ) return nullptr;
        //剪枝分三种情况 0 [1,2, 3,] 2 [1,2,3] 4 [1,2,3]
        // 0 [1,2,3] ,左枝都不要了 root不要了，root=右枝
        if ( root->val < L) {
            root->left = nullptr;
            root = trimBST(root->right,L,R);
            return root;
        }
        // 2 [1,2,3];
        if ( root->val >= L && root->val <= R) {
            root->left = trimBST(root->left,L,R);
            root->right = trimBST(root->right,L,R);
            return root;
        }
        // 4 [1,2,3];
        if ( root->val > R) {
            root->right  = nullptr;
            root = trimBST(root->left,L,R);
            return root;
        }
        
        return root;
    }
};
// @lc code=end

