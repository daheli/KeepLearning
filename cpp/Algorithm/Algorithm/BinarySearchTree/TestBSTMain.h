//
//  TestBSTMain.h
//  Algorithm
//
//  Created by lidahe on 2018/1/17.
//  Copyright © 2018年 lidahe. All rights reserved.
//

#ifndef TestBSTMain_h
#define TestBSTMain_h

#include "BSTBasic.h"
#include "FileOps.h"
#include "SequenceST.h"

void testSearch() {
    // 使用圣经作为我们的测试用例
    string filename = "bible.txt";
    vector<string> words;
    if( FileOps::readFile(filename, words) ) {
        
        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;
        
        
        // 测试 BST
        time_t startTime = clock();
        
        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        BST<string, int> bst = BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = bst.search(*iter);
            if (res == NULL)
                bst.insert(*iter, 1);
            else
                (*res)++;
        }
        
        // 输出圣经中god一词出现的频率
        if(bst.contain("god"))
            cout << "'god' : " << *bst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;
        
        time_t endTime = clock();
        
        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;
        
        
        // 测试顺序查找表 SST
        startTime = clock();
        
        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        SequenceST<string, int> sst = SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = sst.search(*iter);
            if (res == NULL)
                sst.insert(*iter, 1);
            else
                (*res)++;
        }
        
        // 输出圣经中god一词出现的频率
        if(sst.contain("god"))
            cout << "'god' : " << *sst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;
        
        endTime = clock();
        
        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
    }
}

void testTraverse() {
    srand(time(NULL));
    BST<int,int> bst = BST<int,int>();
    
    // 取n个取值范围在[0...m)的随机整数放进二分搜索树中
    int N = 10;
    int M = 100;
    for( int i = 0 ; i < N ; i ++ ){
        int key = rand()%M;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        cout<<key<<" ";
        bst.insert(key,value);
    }
    cout<<endl;
        
    // 测试二分搜索树的size()
    cout<<"size: "<<bst.size()<<endl<<endl;
    
    // 测试二分搜索树的前序遍历 preOrder
    cout<<"preOrder: "<<endl;
    bst.preOrder();
    cout<<endl;
    
    // 测试二分搜索树的中序遍历 inOrder
    cout<<"inOrder: "<<endl;
    bst.inOrder();
    cout<<endl;
    
    // 测试二分搜索树的后序遍历 postOrder
    cout<<"postOrder: "<<endl;
    bst.postOrder();
    cout<<endl;
    
    // 测试二分搜索树的层序遍历 levelOrder
    cout<<"levelOrder: "<<endl;
    bst.levelOrder();
    cout<<endl;
    
}
#endif /* TestBSTMain_h */
