/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 *
 * https://leetcode-cn.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (51.62%)
 * Likes:    30
 * Dislikes: 0
 * Total Accepted:    6K
 * Total Submissions: 11.5K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold
 * Medal", "Silver Medal", "Bronze Medal"）。
 * 
 * (注：分数越高的选手，排名越靠前。)
 * 
 * 示例 1:
 * 
 * 
 * 输入: [5, 4, 3, 2, 1]
 * 输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * 解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal"
 * and "Bronze Medal").
 * 余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
 * 
 * 提示:
 * 
 * 
 * N 是一个正整数并且不会超过 10000。
 * 所有运动员的成绩都不相同。
 * 
 * 
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<numeric> // iota:填充值

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res(nums.size());
        vector<int> index(nums.size());

        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&nums](const int& i, const int& j) {
            return nums[i] > nums[j];
        });

        if (nums.size() > 0) {
            res[index[0]] = "Gold Medal";
        }
        if (nums.size() > 1) {
            res[index[1]] = "Silver Medal";
        }
        if (nums.size() > 2) {
            res[index[2]] = "Bronze Medal";
        }

        for (int i = 3; i < nums.size(); i++) {
            res[index[i]] = to_string(i+1);
        }

        return res;
    }
};
// @lc code=end

