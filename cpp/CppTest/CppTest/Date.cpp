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
        for(int j=i; j<size-1; j++) {
            Date date1 = arr[j];
            Date date2 = arr[j+1];
            if(date1 > date2) {
                Date *tmp = &arr[j];
                arr[j] = date2;
                arr[j+1] = *tmp;
            }
        }
    }
}

void test_CreatePoints() {
    cout << "\nCreatePoints\n";
    const int size = 10;
    Date arr[size];
    Date::CreatePoints(arr, size);
    for(int i=0; i<size; i++) {
        arr[i].print();
    }
    
    cout << "\nSort\n";
//    Sort(arr, size);
//    for(int i=0; i<size; i++) {
//        arr[i].print();
//    }
}


int main_date() {
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

