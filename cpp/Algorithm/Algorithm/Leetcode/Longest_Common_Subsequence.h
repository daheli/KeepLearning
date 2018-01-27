//
//  Longest_Common_Subsequence.h
//  Algorithm
//
//  Created by lidahe on 2018/1/27.
//  Copyright © 2018年 lidahe. All rights reserved.
//

#ifndef Longest_Common_Subsequence_h
#define Longest_Common_Subsequence_h

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

/// LCS最长公共子序列
/// 记忆化搜索
/// 时间复杂度: O(len(s1)*len(s2))
/// 空间复杂度: O(len(s1)*len(s2))
// LCS(m,n) S1[0...m] 和 S2[0...n]的最长公共子序列的长度
// S1[m] == S2[n]: LCS(m,n) = 1 + LCS(m-1, n-1)
// S1[m] != S2[n]: max(LCS(m-1,n), LCS(m, n-1)
class LCS{
    
private:
    vector<vector<int> > memo;
    
    // 求s1[0...m]和s2[0...n]的最长公共子序列的长度值
    int __LCS(const string &s1, const string &s2, int m, int n){
        
        if(m < 0 || n < 0)
            return 0;
        
        if(memo[m][n] != -1)
            return memo[m][n];
        
        int res = 0;
        if(s1[m] == s2[n])
            res = 1 + __LCS(s1, s2, m - 1, n - 1);
        else
            res = max(__LCS(s1, s2, m - 1, n),
                      __LCS(s1, s2, m, n - 1));
        memo[m][n] = res;
        return res;
    }
    
    // 通过memo反向求解s1和s2的最长公共子序列
    string __getLCS(const string &s1, const string &s2){
        
        int m = s1.size() - 1;
        int n = s2.size() - 1;
        
        string res = "";
        while(m >= 0 && n >= 0)
            if(s1[m] == s2[n]){
                res = s1[m] + res;
                m --;
                n --;
            }
            else if(m == 0)
                n --;
            else if(n == 0)
                m --;
            else{
                if(memo[m-1][n] > memo[m][n-1])
                    m --;
                else
                    n --;
            }
        
        return res;
    }
    
public:
    string getLCS(const string &s1, const string &s2){
        
        memo.clear();
        for(int i = 0 ; i < s1.size() ; i ++)
            memo.push_back(vector<int>(s2.size(), -1));
        
        __LCS(s1, s2, s1.size() - 1, s2.size() - 1);
        return __getLCS(s1, s2);
    }
};

int main() {
    
    string s1, s2;
    cin >> s1 >> s2;
    cout << LCS().getLCS(s1, s2) << endl;
    
    return 0;
}

#endif /* Longest_Common_Subsequence_h */
