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


class Shape {
    int no;
public:
    virtual int getArea()=0;
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
    Point * leftUp;
    
public:
    Rectangle(int width, int height, int x, int y): width(width), height(height) {
        leftUp = new Point(x, y);
    };
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    ~Rectangle() {
        delete leftUp;
    }
};

class Circle: public Shape {
    Point center;
    int radius;
};

inline
Rectangle::Rectangle(const Rectangle& other) {
    this->width = other.width;
    this->height = other.height;
    this->leftUp = new Point(*other.leftUp);
}

inline
Rectangle& Rectangle::operator=(const Rectangle& other) {
    if(this == &other) {
        return *this;
    }
    delete leftUp;
    this->width = other.width;
    this->height = other.height;
    this->leftUp = new Point(*other.leftUp);
    return *this;
}


#endif /* Rectangle_hpp */
