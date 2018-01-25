//
//  300.h
//  Algorithm
//
//  Created by lidahe on 2018/1/25.
//  Copyright © 2018年 lidahe. All rights reserved.
//

#ifndef _00_h
#define _00_h

/**
 ********************* 300. Longest Increasing Subsequence 最长上升子序列 *********************
 */
/// https://leetcode.com/problems/longest-increasing-subsequence/description/
/// 动态规划 LIS(i) = max(1 + LIS(j)) i<j,num[i]>num[j]
/// 时间复杂度: O(n^2)
/// 空间复杂度: O(n)
class Solution {
    
public:
    int lengthOfLIS(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        // memo[i] 表示以 nums[i] 为结尾的最长上升子序列的长度
        vector<int> memo(nums.size(), 1);
        for(int i = 1 ; i < nums.size() ; i ++)
            for(int j = 0 ; j < i ; j ++)
                if(nums[i] > nums[j])
                    memo[i] = max(memo[i], 1 + memo[j]);
        
        int res = memo[0];
        for(int i = 1 ; i < nums.size() ; i ++)
            res = max(res, memo[i]);
        
        return res;
    }
};


#endif /* _00_h */
