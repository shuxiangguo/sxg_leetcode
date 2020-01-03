/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 *
 * https://leetcode-cn.com/problems/minimum-index-sum-of-two-lists/description/
 *
 * algorithms
 * Easy (48.00%)
 * Likes:    48
 * Dislikes: 0
 * Total Accepted:    8.9K
 * Total Submissions: 18.1K
 * Testcase Example:  '["Shogun","Tapioca Express","Burger King","KFC"]\n' +
  '["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]'
 *
 * 假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。
 * 
 * 你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。
 * 
 * 示例 1:
 * 
 * 输入:
 * ["Shogun", "Tapioca Express", "Burger King", "KFC"]
 * ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse",
 * "Shogun"]
 * 输出: ["Shogun"]
 * 解释: 他们唯一共同喜爱的餐厅是“Shogun”。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * ["Shogun", "Tapioca Express", "Burger King", "KFC"]
 * ["KFC", "Shogun", "Burger King"]
 * 输出: ["Shogun"]
 * 解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
 * 
 * 
 * 提示:
 * 
 * 
 * 两个列表的长度范围都在 [1, 1000]内。
 * 两个列表中的字符串的长度将在[1，30]的范围内。
 * 下标从0开始，到列表的长度减1。
 * 两个列表都没有重复的元素。
 * 
 * 
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;


class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        int minIndexSum = INT_MAX;
        if (list1.size() == 0 || list2.size() == 0) return res;
        map<string, int> map1;
        map<string, int> map2;
        for (int i = 0; i < list1.size(); i++) {
            map1[list1[i]] = i;
        }

        for (int i = 0; i < list2.size(); i++) {
            map2[list2[i]] = i;
        }
        
        for (auto& x : map1) {
            if (map2.count(x.first) != 0 && (x.second + map2[x.first] <= minIndexSum)) {
                minIndexSum = x.second + map2[x.first];
            }
        }

        for (auto& x : map1) {
            if (map2.count(x.first) != 0) {
                if (x.second + map2[x.first] == minIndexSum) {
                    res.push_back(x.first);
                }
            }
        }
        return res;

    }
};
// @lc code=end

