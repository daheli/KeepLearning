//
//  Rectangle.hpp
//  CppTest
//
//  Created by lidahe on 17/1/24.
//  Copyright © 2017年 lidahe. All rights reserved.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>
#include <iostream>

class Shape {
    int no;
public:
    virtual int getArea()=0;
    void setNo(int _no) {
        no = _no;
    }
};

class Point {
    int x;
    int y;
public:
    Point(int x=0, int y=0): x(x), y(y) {};
    Point(const Point& other) {
        this->x = other.x;
        this->y = other.y;
    }
};

class Rectangle: public Shape {
    int width;
    int height;
    Point *leftUp;
    
public:
    Rectangle(int width = 0, int height = 0, int x = 0, int y = 0): width(width), height(height) {
        leftUp = new Point(x, y);
    };
    Rectangle(const Rectangle& other);
//    Rectangle& operator=(const Rectangle& other);
    virtual int getArea();
    ~Rectangle() {
        delete leftUp;
    }
};

class Circle: public Shape {
    Point *center;
    int radius;
public:
    Circle(int _radius = 0): radius(_radius) {
        center = new Point();
    }    
    virtual int getArea();
    ~Circle() {
        delete center;
    }
};

inline
Rectangle::Rectangle(const Rectangle& other) {
    this->width = other.width;
    this->height = other.height;
    this->leftUp = new Point(*other.leftUp);
}

//inline
//Rectangle& Rectangle::operator=(const Rectangle& other) {
//    if(this == &other) {
//        return *this;
//    }
//    delete leftUp;
//    this->width = other.width;
//    this->height = other.height;
//    this->leftUp = new Point(*other.leftUp);
//    return *this;
//}

inline
int Rectangle::getArea() {
    return width * height;
}

inline
int Circle::getArea() {
    return 3.14 * radius * radius;
}

#endif /* Rectangle_hpp */
