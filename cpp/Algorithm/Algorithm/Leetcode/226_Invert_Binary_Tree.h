//
//  226_Invert_Binary_Tree.h
//  Algorithm
//
//  Created by lidahe on 2018/1/25.
//  Copyright © 2018年 lidahe. All rights reserved.
//

#ifndef _26_Invert_Binary_Tree_h
#define _26_Invert_Binary_Tree_h

/// 226. Invert Binary Tree
/// https://leetcode.com/problems/invert-binary-tree/description/
/// 时间复杂度: O(n), n为树中节点个数
/// 空间复杂度: O(h), h为树的高度

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL)
            return NULL;
        
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        
        return root;
    }
};

#endif /* _26_Invert_Binary_Tree_h */
