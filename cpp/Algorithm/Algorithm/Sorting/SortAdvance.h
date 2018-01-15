//
//  SortingAdvance.h
//  Algorithm
//
//  Created by lidahe on 2018/1/15.
//  Copyright © 2018年 lidahe. All rights reserved.
//

#ifndef SortingAdvance_h
#define SortingAdvance_h

//*********************归并*********************
// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename  T>
void __merge(T arr[], int l, int mid, int r) {
    T aux[r-l+1];
//    T *aux = new T[r-l+1];
    
    for( int i = l ; i <= r; i ++ ) {
        aux[i-l] = arr[i];
    }
    
    // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
    int i = l, j = mid + 1;
    for( int k = l ; k <= r; k ++ ) {
        if (i > mid) { // 如果左半部分元素已经全部处理完毕
            arr[k] = aux[j-l];
            j++;
        } else if (j > r) { // 如果右半部分元素已经全部处理完毕
            arr[k] = aux[i-l];
            i++;
        } else if (aux[i-l] < aux[j-l]) { // 左半部分所指元素 < 右半部分所指元素
            arr[k] = aux[i-l];
            i++;
        } else {
            arr[k] = aux[j-l];
            j++;
        }
    }
//    delete[] aux;
}

// 递归使用归并排序,对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r) {
    // 优化2: 对于小规模数组, 使用插入排序
    if( r - l <= 15 ){
        insertionSort(arr, l, r);
        return;
    }
//    if( l >= r ) {
//        return;
//    }
    
    int mid = (l+r)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    __merge(arr, l, mid, r);
//    SortTestHelper::printArray(arr, r);
}

template<typename T>
void mergeSort(T arr[], int n){
//    SortTestHelper::printArray(arr, n);
    __mergeSort( arr , 0 , n-1 );
//    SortTestHelper::printArray(arr, n);
}

//*********************快排*********************
// 对arr[l...r]部分进行partition操作
// 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r) {
    T v= arr[l];

    int p = l;
    for(int i=l+1; i<=r; i++) {
        if(arr[i] < v) {
            p++;
            swap(arr[p], arr[i]);
        }
    }
    swap(arr[l], arr[p]);
    return p;
}

// 对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r){
    if(l>=r) {
        return;
    }
    
    int p = __partition(arr, l, r);
//    SortTestHelper::printArray(arr, r);
    __quickSort(arr, l, p);
    __quickSort(arr, p+1, r);
//    SortTestHelper::printArray(arr, r);
}

template <typename T>
void quickSort(T arr[], int n){
//    SortTestHelper::printArray(arr, n);
    __quickSort(arr, 0, n-1);
//    SortTestHelper::printArray(arr, n);
}
#endif /* SortingAdvance_h */
