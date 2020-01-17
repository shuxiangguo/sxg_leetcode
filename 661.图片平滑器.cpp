/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 *
 * https://leetcode-cn.com/problems/image-smoother/description/
 *
 * algorithms
 * Easy (50.58%)
 * Likes:    36
 * Dislikes: 0
 * Total Accepted:    5.6K
 * Total Submissions: 10.8K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 包含整数的二维矩阵 M 表示一个图片的灰度。你需要设计一个平滑器来让每一个单元的灰度成为平均灰度 (向下舍入)
 * ，平均灰度的计算是周围的8个单元和它本身的值求平均，如果周围的单元格不足八个，则尽可能多的利用它们。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * [[1,1,1],
 * ⁠[1,0,1],
 * ⁠[1,1,1]]
 * 输出:
 * [[0, 0, 0],
 * ⁠[0, 0, 0],
 * ⁠[0, 0, 0]]
 * 解释:
 * 对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
 * 对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
 * 对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
 * 
 * 
 * 注意:
 * 
 * 
 * 给定矩阵中的整数范围为 [0, 255]。
 * 矩阵的长和宽的范围均为 [1, 150]。
 * 
 * 
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int row = M.size();
        int column = M[0].size();
        vector<vector<int>> res = M;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                int cnt = 0;
                int sum = 0;
                for (int ni = i-1; ni <= i+1; ni++) {
                    for (int nj = j-1; nj <= j+1; nj++) {
                        if (ni >= 0 && ni < row && nj >= 0 && nj < column) {
                            sum += M[ni][nj];
                            cnt++;
                        }
                    }
                }
                res[i][j] = int(sum / cnt);
            }
        }
        return res;
    }

    
};
// @lc code=end

