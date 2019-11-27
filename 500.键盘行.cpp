/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 *
 * https://leetcode-cn.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (67.42%)
 * Likes:    63
 * Dislikes: 0
 * Total Accepted:    11.7K
 * Total Submissions: 17.3K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * 给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: ["Hello", "Alaska", "Dad", "Peace"]
 * 输出: ["Alaska", "Dad"]
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 你可以重复使用键盘上同一字符。
 * 你可以假设输入的字符串将只包含字母。
 * 
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
    
    vector<string> findWords(vector<string>& words) 
    {
        string q{"qwertyuiop"};
        string a{"asdfghjkl"};
        string z{"zxcvbnm"};
        vector<string> ans;    

        for(int i=0;i<words.size();i++)
        {
            int d=0,b=0,c=0;
            for(int j=0;j<words[i].size();j++)
            {
                if(q.find(tolower(words[i][j]))!=string::npos) b++;
                if(a.find(tolower(words[i][j]))!=string::npos) c++;
                if(z.find(tolower(words[i][j]))!=string::npos) d++;
            }
            if(b==words[i].size()||c==words[i].size()||d==words[i].size()) 
                ans.push_back(words[i]);
        }
        return ans;      
    }
};
// @lc code=end

