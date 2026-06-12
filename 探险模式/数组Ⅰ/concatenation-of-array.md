---
title: "LeetCode：数组串联"
date: 2026-06-12
tags:
  - "LeetCode"
  - "数组"
  - "模拟"
  - "C++"
---

# LeetCode：数组串联

## 题目信息

- 题目链接：https://leetcode.cn/problems/concatenation-of-array/description/?envType=problem-list-v2&envId=shujujiegouyusuanfa-xianxingqiantan-shuzu-i
- 难度：简单
- 核心知识点：数组、模拟

## 题目概述

给定一个长度为 n 的整数数组 nums，构造一个长度为 2n 的数组，使前半部分和后半部分都按原顺序等于 nums。

## 解题思路

代码先取得原数组长度 n，并创建长度为 2n 的结果数组 v。遍历 nums 时，把 nums[i] 同时写入 v[i] 和 v[i+n]，因此一次循环就完成了两段相同数组的构造。

## 解题步骤

1. 记录原数组长度 n，并创建大小为 2n 的结果数组。
2. 遍历原数组，将 nums[i] 分别写入结果数组的第 i 个位置和第 i+n 个位置。
3. 遍历结束后返回结果数组。

## 我的代码

```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> v(2*n);
        for(int i=0;i<n;i++){
            v[i]=v[i+n]=nums[i];
        }
        return v;
    }
};
```

## 复杂度分析

- 时间复杂度：`O(n)`
- 空间复杂度：`O(n)`

## 关键细节与易错点

- v[i] 与 v[i+n] 使用链式赋值，可在同一条语句中写入两个对应位置。
- 结果数组需要存放 2n 个元素，因此返回结果所占空间为 O(n)。

## 总结

直接利用下标偏移 n 同时填写结果数组的前后两部分，思路简洁，也只需要遍历原数组一次。
