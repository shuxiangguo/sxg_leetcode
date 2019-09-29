# 《LeetCode刷题笔记》



## 1.两数之和

### 题目描述

> 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
>
> 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
>
> 链接：https://leetcode-cn.com/problems/two-sum



### 解题思路

使用查找表来解决该问题。

设置一个 map 容器 record 用来记录元素的值与索引，然后遍历数组 nums。

* 每次遍历时使用临时变量 complement 用来保存目标值与当前值的差值。
* 在此次遍历中查找 record，查看是否有与 complement 一致的值，如果查找成功则返回查找值的索引值与当前变量的值 i。
* 如果未找到，则在 record 保存该元素与索引值 i

链接：https://leetcode-cn.com/problems/two-sum/solution/dong-hua-tu-jie-suan-fa-liang-shu-zhi-he-fu-shi-pi/



### 代码实现

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

------------

### 知识点

> Map的使用，熟悉使用STL！！！

## 2.两数相加

### 题目描述

> 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
>
> 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
>
> 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
>
> 示例：
>
> 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
> 输出：7 -> 0 -> 8
> 原因：342 + 465 = 807
>
> 来源：力扣（LeetCode）
> 链接：https://leetcode-cn.com/problems/add-two-numbers

### 解题思路

* 解法1：将长度较短的链表在末尾补零使得两个链表长度相等，再一个个元素相加，考虑进位

具体步骤：

> 1. 获取两个链表所对应的长度
> 2. 在较短的链表末尾补零
> 3. 对齐相加，考虑进位

### 代码实现

解法1的：

```c
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=1;//记录l1的长度
        int len2=1;//记录l2的长度
        ListNode* p=l1;
        ListNode* q=l2;
        while(p->next!=NULL)//获取l1的长度
        {
            len1++;
            p=p->next;
        }
        while(q->next!=NULL)//获取l2的长度
        {
            len2++;
            q=q->next;
        }
        if(len1>len2)//l1较长，在l2末尾补零
        {
            for(int i=1;i<=len1-len2;i++)
            {
                q->next=new ListNode(0);
                q=q->next;
            }
        }
        else//l2较长，在l1末尾补零
        {
            for(int i=1;i<=len2-len1;i++)
            {
                p->next=new ListNode(0);
                p=p->next;
            }
        }
        p=l1;
        q=l2;
        bool count=false;//记录进位
        ListNode* l3=new ListNode(-1);//存放结果的链表
        ListNode* w=l3;//l3的移动指针
        int i=0;//记录相加结果
        while(p!=NULL&&q!=NULL)
        {
            i=count+p->val+q->val;
            w->next=new ListNode(i%10);
            count=i>=10?true:false;
            w=w->next;
            p=p->next;
            q=q->next;
        }
        if(count)//若最后还有进位
        {
            w->next=new ListNode(1);
            w=w->next;
        }
        return l3->next; 
    }
};

链接：https://leetcode-cn.com/problems/add-two-numbers/solution/liang-shu-xiang-jia-by-gpe3dbjds1/
```

- 解法2：不对齐补零，若链表不为空则用sum(代表每个位的和的结果)加上，考虑进位。

```c++
class Solution2 {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1); // 存放结果的链表
        ListNode* h = head; // head的移动指针

        int sum = 0; // 每个对应位和进位的相加和
        bool carry = false; // 是否有进位
        while (l1 != nullptr || l2 != nullptr) {
            sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            if (carry) {
                sum++;
            }

            h->next = new ListNode(sum % 10);
            h = h->next;
            carry = sum >= 10 ? true : false;
        }

        if (carry) {
            h->next = new ListNode(1);
        }
        return head->next;
    }
};
```



### 知识点

> 指针，链表



## 3. 无重复字符的最长子串

### 题目描述

> 给定一个字符串，请你找出其中不含有重复字符的 **最长子串** 的长度。
>
> **示例 1:**
>
> ```
> 输入: "abcabcbb"
> 输出: 3 
> 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
> ```



### 解题思路

> 通过使用 HashSet 作为滑动窗口，我们可以用 O(1)的时间来完成对字符是否在当前的子字符串中的检查。
>
> 滑动窗口是数组/字符串问题中常用的抽象概念。 窗口通常是在数组/字符串中由开始和结束索引定义的一系列元素的集合，即 [i,j)（左闭，右开）。而滑动窗口是可以将两个边界向某一方向“滑动”的窗口。例如，我们将 [i,j)[i, j)[i,j) 向右滑动 1个元素，则它将变为 [i+1,j+1)（左闭，右开）。
>
> 回到我们的问题，我们使用 HashSet 将字符存储在当前窗口 [i,j)（最初 j=i）中。 然后我们向右侧滑动索引 jjj，如果它不在 HashSet 中，我们会继续滑动 jjj。直到 s[j] 已经存在于 HashSet 中。此时，我们找到的没有重复字符的最长子字符串将会以索引 i开头。如果我们对所有的 i 这样做，就可以得到答案
> 链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetcod/
>

### 代码实现

* C++版本

```c++
# include<iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        set<char> myset;
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            // try to extend the range[i, j]
            if (!myset.count(s[j])) {
                myset.insert(s[j++]);
                ans = max(ans, j-i);
            } else {
                myset.erase(s[i++]);
            }
        }
        return ans;
    }
};
```

* Python版本

```python

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # 如果字符串s为空，返回0
        if not s:return 0
        # 保存窗口内字符串
        lookup = list()
        n = len(s)
        # 最大子串长度
        max_len = 0
        # 当前窗口长度
        cur_len = 0
        # 遍历字符串s
        for i in range(n):
            val = s[i]
            # 如果该值不在窗口中
            if not val in lookup:
                # 添加到窗口内
                lookup.append(val)
                # 当前长度+1
                cur_len+=1
            # 如果该值在窗口中已存在
            else:
                # 获取其在窗口中的位置
                index = lookup.index(val)
                # 移除该位置及之前的字符，相当于上图中的图3到图4
                lookup = lookup[index+1:]
                lookup.append(val)
                # 当前长度更新为窗口长度
                cur_len = len(lookup)
            # 如果当前长度大于最大长度，更新最大长度值
            if cur_len > max_len:max_len = cur_len
        # 返回最大子串长度
        return max_len
```



### 知识点

>  滑动窗口的使用，具体可查看参考链接

### 参考链接

* https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetcod/
* https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-dong-chuang-kou-by-powcai/

------

## 4.寻找两个有序数组的中位数

### 题目描述

> *给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。*请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。*
>
> 你可以假设 nums1 和 nums2 不会同时为空。
>
> 示例 1:
>
> nums1 = [1, 3]*
>
> nums2 = [2]
>
>  则中位数是 2.0
>
> 
>
>  示例 2:
>
> nums1 = [1, 2]
>
> nums2 = [3, 4]
>
>  则中位数是 (2 + 3)/2 = 2.5



### 解题思路

> 用 len 表示合并后数组的长度，如果是奇数，我们需要知道第 （len+1）/2 个数就可以了，如果遍历的话需要遍历 int(len/2 ) + 1 次。如果是偶数，我们需要知道第 len/2和 len/2+1 个数，也是需要遍历 len/2+1 次。所以遍历的话，奇数和偶数都是 len/2+1 次。
>
> 返回中位数的话，奇数需要最后一次遍历的结果就可以了，偶数需要最后一次和上一次遍历的结果。所以我们用两个变量 left 和 right，right 保存当前循环的结果，在每次循环前将 right 的值赋给 left。这样在最后一次循环的时候，left 将得到 right 的值，也就是上一次循环的结果，接下来 right 更新为最后一次的结果。
>
> 循环中该怎么写，什么时候 A 数组后移，什么时候 B 数组后移。用 aStart 和 bStart 分别表示当前指向 A 数组和 B 数组的位置。如果 aStart 还没有到最后并且此时 A 位置的数字小于 B 位置的数组，那么就可以后移了。也就是aStart＜m&&A[aStart]< B[bStart]。
>
> 但如果 B 数组此刻已经没有数字了，继续取数字 B[ bStart ]，则会越界，所以判断下 bStart 是否大于数组长度了，这样 || 后边的就不会执行了，也就不会导致错误了，所以增加为 aStart＜m&&(bStart) >= n||A[aStart]<B[bStart]) 。



### 代码实现

```C++
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int len = m + n;
        int left = -1, right = -1;
        int aStart = 0, bStart = 0;
        for (int i = 0; i <= len / 2; i++) {
            left = right;
            if (aStart < m && (bStart >= n || nums1[aStart] < nums2[bStart])) {
                right = nums1[aStart++];
            } else {
                right = nums2[bStart++];
            }
        }

        if ((len & 1) == 0) {
            return (left + right) / 2.0;
        } else {
            return right;
        }
    }
};
```

### 参考链接

https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/