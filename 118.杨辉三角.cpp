/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (64.24%)
 * Likes:    192
 * Dislikes: 0
 * Total Accepted:    41.2K
 * Total Submissions: 64.1K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) {return res;}
        vector<int> firstRow;
        firstRow.push_back(1);
        res.push_back(firstRow);

        for (int i = 1; i < numRows; i++) {
            vector<int> curRow;
            vector<int> preRow = res[i-1];

            curRow.push_back(1);
            // i = 1时其实是 代表第二行，有两个元素，所以是j < i
            for (int j = 1; j < i; j++) {
                curRow.push_back(preRow[j-1]+preRow[j]);
            }

            // the last element of every row is 1
            curRow.push_back(1);
            res.push_back(curRow);
        }
        return res;
    }
};
// @lc code=end

