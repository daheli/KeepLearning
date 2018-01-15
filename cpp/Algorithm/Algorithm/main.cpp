//
//  main.cpp
//  Algorithm
//
//  Created by lidahe on 2018/1/11.
//  Copyright © 2018年 lidahe. All rights reserved.
//

#include <iostream>
#include "SortTestHelper.h"
#include "SortBasic.h"
#include "SortAdvance.h"


//template <typename Key, typename Value>
//class BST{
//
//private:
//    struct Node {
//        Key key;
//        Value value;
//        Node(Key key, Value value) {
//            this->key = key;
//            this->value = value;
//        }
//    };
//    Node *root; // 根节点
//    int count;  // 节点个数
//
//public:
//    BST() {
//        root = NULL;
//        count = 0;
//    }
//
//    ~BST() {
//
//    }
//};

/**
 排序测试
 */
void testSortBasic() {
    int n = 20000;
    
    // 测试1 一般测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Insertion Sort", selectionSort, arr2, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    
    cout<<endl;
    
    // 测试2 有序性更强的测试
    cout<<"Test for more ordered random array, size = "<<n<<", random range [0, 3]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,3);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,n);
    SortTestHelper::testSort("Selection Sort", selectionSort,arr2,n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    
    cout<<endl;
    
    
    // 测试3 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,n);
    SortTestHelper::testSort("Selection Sort", selectionSort,arr2,n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}

void testSortAdvance() {
    int n = 50000;
    
    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort",     mergeSort,     arr2, n);
    
    delete[] arr1;
    delete[] arr2;
    
    cout<<endl;
    
    
    // 测试2 测试近乎有序的数组
    // 对于近乎有序的数组, 数组越有序, InsertionSort的时间性能越趋近于O(n)
    // 所以可以尝试, 当swapTimes比较大时, MergeSort更快
    // 但是当swapTimes小到一定程度, InsertionSort变得比MergeSort快
    int swapTimes = 10;
    assert( swapTimes >= 0 );

    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort",     mergeSort,     arr2, n);

    delete[] arr1;
    delete[] arr2;
}

void testSortAdvance2() {
//    int n = 4;
    int n = 1000000;

    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1,n);

//    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout<<endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n" << endl;
    
//    testSortBasic();
//    testSortAdvance();
    testSortAdvance2();
    return 0;
}
