/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (67.16%)
 * Likes:    254
 * Dislikes: 0
 * Total Accepted:    33.8K
 * Total Submissions: 50.2K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定有序数组: [-10,-3,0,5,9],
 * 
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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

/**
 平衡二叉搜索树的特点是：每个节点的左右子树都高度差在1以内，每个节点左子树小于右子树。
根据平衡二叉搜索树的特点，可以联想到，每个节点当做根节点的时候，左子树形成的数组一定比它小，右子树形成的数组一定比他大。
因此，符合有序数组任意子数组中点的性质。
结合树结构常用的递归思想，可以采用DFS，递归构建这颗树，为了实现每个节点都是平衡二叉搜索树，可以递归二分数组来分配资源，
左面的构建左子树，右面的构建右子树，以此递归。
*/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBST(nums, 0, nums.size()-1);
    }

    TreeNode* toBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = (int)(left + right)/2; //二分中值
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = toBST(nums, left, mid-1);
        root->right = toBST(nums, mid+1, right);
        return root;
    }
};
// @lc code=end

