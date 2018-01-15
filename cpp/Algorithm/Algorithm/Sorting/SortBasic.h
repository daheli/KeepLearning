//
//  SelectionSort.h
//  Algorithm
//
//  Created by lidahe on 2018/1/15.
//  Copyright © 2018年 lidahe. All rights reserved.
//

#ifndef SelectionSort_h
#define SelectionSort_h

template<typename T>
void selectionSort(T arr[], int n) {
    for(int i =0 ; i<n; i++ ) {
        int minIndex = i;
        for( int j= i+1; j<n; j++ ) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

template<typename T>
void insertionSort(T arr[], int n) {
//    for(int i=1; i<n; i++ ) {
//        for(int j=i; j>0; j--) {
//            if(arr[j] < arr[j-1]) {
//                swap(arr[j-1], arr[j]);
//            } else {
//                break;
//            }
//        }
//    }
    
    for(int i=1; i<n; i++ ) {
        T e = arr[i];
        int j; // j保存元素e应该插入的位置
        for (j=i; j>0 && arr[j-1] > e; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

// 对arr[l...r]范围的数组进行插入排序
template<typename T>
void insertionSort(T arr[], int l, int r){
    for(int i=l+1; i<=r; i++) {
        for(int j=i; j>l && arr[j-1] > arr[j]; j--) {
            swap(arr[j-1], arr[j]);
        }
    }
}

template<typename T>
void bubbleSort(T arr[], int n) {
    bool swapped;
    do {
        swapped = false;
        for(int i=1; i<n; i++ ) {
            if(arr[i] < arr[i-1]) {
                swap(arr[i], arr[i-1]);
                swapped = true;
            }
        }
        n--;
    }while(swapped);
}

#endif /* SelectionSort_h */
