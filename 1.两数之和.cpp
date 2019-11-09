/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        vector<int> res;

        int remain = 0;
        for (int i = 0; i < nums.size(); i++) {
            remain = target - nums[i];
            if (record.find(remain) != record.end()) {
                res.push_back(i);
                res.push_back(record[remain]);
            } else {
                record[nums[i]] = i;
            }
        }
        return res;
    }
};

