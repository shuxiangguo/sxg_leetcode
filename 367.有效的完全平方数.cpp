/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (42.31%)
 * Likes:    71
 * Dislikes: 0
 * Total Accepted:    17.3K
 * Total Submissions: 40.7K
 * Testcase Example:  '16'
 *
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 * 
 * 说明：不要使用任何内置的库函数，如  sqrt。
 * 
 * 示例 1：
 * 
 * 输入：16
 * 输出：True
 * 
 * 示例 2：
 * 
 * 输入：14
 * 输出：False
 * 
 * 
 */

// @lc code=start
#include<iostream>
#include<cmath>

using namespace std;
class Solution {
public:
    // 二分法
    // bool isPerfectSquare(int num) {
    //     int start = 1;
    //     int end = num;
    //     int mid = start + (end - start) / 2;

    //     while (start <= end) {
    //         if (pow(mid, 2) > num ) {
    //             end = mid - 1;
    //         } else if (pow(mid, 2) < num) {
    //             start = mid + 1;
    //         } else {
    //             return true;
    //         }
    //         mid = start + (end - start) / 2;
    //     }
    //     return false;
    // }

    // // 递增判断
    // bool isPerfectSquare(int num) {
    //     int i = 1;
    //     while (pow(i, 2) < num) {
    //         i++;
    //     }
    //     if (pow(i, 2) == num) return true;
    //     else return false;
    // }

    // 公式法
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};
// @lc code=end

