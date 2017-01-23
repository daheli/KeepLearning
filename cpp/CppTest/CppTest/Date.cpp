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

void test_CreatePoints() {
    cout << "\nCreatePoints\n";
    const int size = 10;
    Date arr[size];
    Date::CreatePoints(arr, size);
    for(int i=0; i<size; i++) {
        arr[i].print();
    }
}

int main() {
    cout << "Date.cpp\n";
    
    Date d1(2001,01,21);
    Date d2(2016,02,01);
    
    d1.print();
    d2.print();
//    cout << "d1: " << d1 << endl;
//    cout << "d2: " << d2 << endl;
    cout << "d1>d2: " << (d1 > d2) << endl;
    cout << "d1<d2: " << (d1 < d2) << endl;    
    
    test_CreatePoints(); 
    return 0;
}

