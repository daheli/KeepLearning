//
//  SortOptional.h
//  Algorithm
//
//  Created by lidahe on 2018/1/16.
//  Copyright © 2018年 lidahe. All rights reserved.
//

#ifndef SortOptional_h
#define SortOptional_h

/**
 *********************自底向上的归并排序, 含优化*********************
 */
// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
// 其中aux为完成merge过程所需要的辅助空间
template<typename  T>
void __merge2(T arr[], T aux[], int l, int mid, int r){
    
    // 由于aux的大小和arr一样, 所以我们也不需要处理aux索引的偏移量
    // 进一步节省了计算量:)
    for( int i = l ; i <= r; i ++ )
        aux[i] = arr[i];
    
    // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
    int i = l, j = mid+1;
    for( int k = l ; k <= r; k ++ ){
        
        if( i > mid ){  // 如果左半部分元素已经全部处理完毕
            arr[k] = aux[j]; j ++;
        }
        else if( j > r ){  // 如果右半部分元素已经全部处理完毕
            arr[k] = aux[i]; i ++;
        }
        else if( aux[i] < aux[j] ) {  // 左半部分所指元素 < 右半部分所指元素
            arr[k] = aux[i]; i ++;
        }
        else{  // 左半部分所指元素 >= 右半部分所指元素
            arr[k] = aux[j]; j ++;
        }
    }
}

template <typename T>
void mergeSortBU2(T arr[], int n){
    // 对于小规模数组, 使用插入排序
    for( int i = 0 ; i < n ; i += 16 )
        insertionSort(arr,i,min(i+15,n-1));
    
    // 一次性申请aux空间, 并将这个辅助空间以参数形式传递给完成归并排序的各个子函数
    T* aux = new T[n];
    for( int sz = 16; sz <= n ; sz += sz )
        for( int i = 0 ; i < n - sz ; i += sz+sz )
            // 对于arr[mid] <= arr[mid+1]的情况,不进行merge
            // 对于近乎有序的数组非常有效,但是对于一般情况,有一定的性能损失
            if( arr[i+sz-1] > arr[i+sz] )
                __merge2(arr, aux, i, i+sz-1, min(i+sz+sz-1,n-1) );
    delete[] aux; // 使用C++, new出来的空间不要忘记释放掉:)
}

/**
 *********************递归求arr的逆序数对个数*********************
 */
// merge函数求出在arr[l...mid]和arr[mid+1...r]有序的基础上, arr[l...r]的逆序数对个数
long long __merge__inversionCount( int arr[], int l, int mid, int r){
    int *aux = new int[r-l+1];
    
    // 初始化逆序数对个数 num = 0
    long long num = 0;
    
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
        } else if (aux[i-l] <= aux[j-l]) { // 左半部分所指元素 <= 右半部分所指元素
            arr[k] = aux[i-l];
        } else { // 左半部分所指元素 > 右半部分所指元素
            arr[k] = aux[j-l];
            j++;
            // 此时, 因为右半部分所指的元素小
            // 这个元素和左半部分的所有未处理的元素都构成了逆序数对
            // 左半部分此时未处理的元素个数为 mid - i + 1
            num += mid - i + 1;
        }
    }
    delete[] aux;
    
    return num;
}

long long __inversionCount(int arr[], int l, int r){
    if( l >= r )
        return 0;
    
    int mid = l + (r-l)/2;
    // 求出 arr[l...mid] 范围的逆序数
    long long res1 = __inversionCount( arr, l, mid);
    // 求出 arr[mid+1...r] 范围的逆序数
    long long res2 = __inversionCount( arr, mid+1, r);
    
    return res1 + res2 + __merge__inversionCount( arr, l, mid, r);
}

long long inversionCount(int arr[], int n){
    return __inversionCount(arr, 0, n-1);
}

#endif /* SortOptional_h */
