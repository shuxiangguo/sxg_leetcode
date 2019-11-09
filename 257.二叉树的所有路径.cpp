/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (60.26%)
 * Likes:    166
 * Dislikes: 0
 * Total Accepted:    17.4K
 * Total Submissions: 28.8K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
#include<string>
#include<vector>

using namespace std;
class Solution {
public:
    void constructPath(TreeNode* root, string path, vector<string>& paths) {
        if (root != nullptr) {
            path.append(std::to_string(root->val));
            // 当前是叶子节点
            if ((root->left == nullptr) && (root->right == nullptr)) {
                paths.push_back(path); // 把路径加入到答案中
            } else {
                path.append("->");
                constructPath(root->left, path, paths);
                constructPath(root->right, path, paths);
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string path = "";
        
        constructPath(root, path, paths);
        return paths;
    }
};
// @lc code=end

