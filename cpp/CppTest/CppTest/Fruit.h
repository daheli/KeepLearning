//
//  Fruit.hpp
//  CppTest
//
//  Created by lidahe on 17/1/27.
//  Copyright © 2017年 lidahe. All rights reserved.
//

#ifndef Fruit_hpp
#define Fruit_hpp

#include <stdio.h>

//Fruit total: (24+4) + 补齐 = 32byte
class Fruit {
    int no; // 4
    double weight; // 8
    char key; // 1
    //data -> 24
public:
    void print() {   }
    void print1() {   }
    void print2() {   }
    void print3() {   }
    void print4() {   }
    virtual void process(){   } //vptr -> 4
};


//Apple total: 8 + Fruit(32) = 40byte
class Apple: public Fruit{
    int size; // 4
    char type; // 1
    // data -> 8
public:
    void save() {   }
    virtual void process(){   } //重写vtbl
    virtual void process2(){   }
    virtual void process3(){   }
    virtual void process4(){   }
    virtual void process5(){   }
    virtual void process6(){   }
};

//Pear total: 8 + 8 = 16byte
class Pear {
    int no; // 4
    char key;// 1
    double weight; // 8
};
#endif /* Fruit_hpp */
