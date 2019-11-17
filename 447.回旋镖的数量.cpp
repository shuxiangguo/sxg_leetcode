/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 *
 * https://leetcode-cn.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Easy (55.14%)
 * Likes:    62
 * Dislikes: 0
 * Total Accepted:    7.2K
 * Total Submissions: 13K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * 给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 i 和 k
 * 之间的距离相等（需要考虑元组的顺序）。
 * 
 * 找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。
 * 
 * 示例:
 * 
 * 
 * 输入:
 * [[0,0],[1,0],[2,0]]
 * 
 * 输出:
 * 2
 * 
 * 解释:
 * 两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int result = 0;
		for (int i = 0; i < points.size(); i++) {
			unordered_map<int, int> recoder;
			for (int j = 0; j < points.size(); j++) {
				if (i != j)
					recoder[pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2)]++;
			}
			for (unordered_map<int, int>::iterator itr = recoder.begin(); itr != recoder.end(); itr++) {
				if(itr->second > 1)
				 result = result + (itr->second) * (itr->second-1);
			}
		}
		return result;
    }
};
// @lc code=end

