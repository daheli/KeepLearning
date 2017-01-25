//
//  Date.cpp
//  CppTest
//
//  Created by lidahe on 17/1/23.
//  Copyright © 2017年 lidahe. All rights reserved.
//

#include "Date.h"
#include <iostream>

using namespace std;

void Sort(Date arr[], const int size) {
    for(int i=0; i<size; i++) {
        Date *min = &arr[i];
        int min_index = i;
        for(int j=i+1; j<size; j++) {
            if(arr[j].daysTotalNumber() < min->daysTotalNumber()) {
                min = &arr[j];
                min_index = j;
            }
        }
        
        if (min_index != i) {
            min = arr[i].clone();
            arr[i] = arr[min_index];
            arr[min_index] = *min;
        }
    }
    for(int i=0; i<size; i++) {
        arr[i].print();
    }    
}

void test_CreatePoints() {
    cout << "\nCreatePoints\n";
    const int size = 10;
    Date *arr = new Date[size];
    Date::CreatePoints(arr, size);
    for(int i=0; i<size; i++) {
        arr[i].print();
    }
    
    cout << "\nSort\n";
    Sort(arr, size);
    
    delete[] arr;
}


int main() {
    cout << "Date.cpp\n";
    
    Date d1(2001,01,21);
    Date d2(2016,02,01);
    
    d1.print();
    d2.print();
    cout << "d1>d2: " << (d1 > d2) << endl;
    cout << "d1<d2: " << (d1 < d2) << endl;    
    
    test_CreatePoints(); 
    return 0;
}

