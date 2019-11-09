/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (58.33%)
 * Likes:    88
 * Dislikes: 0
 * Total Accepted:    26.5K
 * Total Submissions: 45.3K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        if (rowIndex < 0) {return res[0];}
        vector<int> firstRow;
        firstRow.push_back(1);
        res.push_back(firstRow);

        for (int i = 1; i < rowIndex+1; i++) {
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
        return res[rowIndex];
    }
};
// @lc code=end

