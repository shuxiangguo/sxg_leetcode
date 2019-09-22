《LeetCode刷题记录》

------

## 1.两数之和

* 题目描述

> 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
>
> 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
>
> 链接：https://leetcode-cn.com/problems/two-sum



* 解题

  使用查找表来解决该问题。

  设置一个 map 容器 record 用来记录元素的值与索引，然后遍历数组 nums。

  * 每次遍历时使用临时变量 complement 用来保存目标值与当前值的差值。
  * 在此次遍历中查找 record，查看是否有与 complement 一致的值，如果查找成功则返回查找值的索引值与当前变量的值 i。
  * 如果未找到，则在 record 保存该元素与索引值 i

  链接：https://leetcode-cn.com/problems/two-sum/solution/dong-hua-tu-jie-suan-fa-liang-shu-zhi-he-fu-shi-pi/

* 代码实现

  * C++版本

    ```c++
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
    ```

  * Java版本

    ```java
    class Solution {
    	public int[] twoSum(int[] nums, int target) {
            Map<Integer, Integer> map = new HashMap<>();
            for (int i = 0; i < nums.length; i++) {
                if (map.containsKey(temp)) {
                    return new int[] {map.get(temp), i};
                }
                map.put(nums[i], i);
            }
            return new int[] {-1, -1};
        }
    }
    ```

    