/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.25%)
 * Likes:    1332
 * Dislikes: 0
 * Total Accepted:    117.5K
 * Total Submissions: 430.9K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==1) return s;//大小为1的字符串必为回文串
        string rev = s;//rev存放s反转结果
        string res;//存放结果
        std::reverse(rev.begin(),rev.end());
        if(rev==s) return s;
        int len=0;//存放回文子串的长度
        for(int i=0;i<s.length();i++)//查找s与rev的最长公共子串
        {
            string temp;//存放待验证子串
            for(int j=i;j<s.length();j++)
            {
                temp=temp+s[j];
                if(len>=temp.length())
                    continue;
                else if(rev.find(temp)!=-1)//在rev中找到temp
                {
                    string q=temp;//q用来验证temp是否是回文子串
                    std::reverse(q.begin(),q.end());
                    if(q==temp)
                    {
                        len=temp.length();
                        res=temp;
                    }
                }
                else break;
            }
            temp="";
        }
        return res;
    }
};
// @lc code=end

