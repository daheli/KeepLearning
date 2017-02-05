//
//  Fruit.cpp
//  CppTest
//
//  Created by lidahe on 17/1/27.
//  Copyright © 2017年 lidahe. All rights reserved.
//

#include "Fruit.h"
#include <iostream>

using namespace std;


int main() {
    cout <<"fruit =============" << endl;
    Fruit *fruit = new Fruit;
    
    cout <<"fruit2 =============" << endl;
    Fruit *fruit2 = ::new Fruit;
    
    cout <<"apple =============" << endl;
    Apple *apple = new Apple;
    cout << sizeof(void*) << endl;
    cout << "int:" << sizeof(int) << " double:" << sizeof(double) << " char:" << sizeof(char) << endl;
    cout << "Fruit:" << sizeof(Fruit) << endl;
    cout << "Apple:" << sizeof(Apple) << endl;
    cout << "Pear:" << sizeof(Pear) << endl;
    
    cout << "delete fruit =============" << endl;
    delete fruit;
    
    cout <<"delete apple =============" << endl;
    delete apple;
    return 0;
}
