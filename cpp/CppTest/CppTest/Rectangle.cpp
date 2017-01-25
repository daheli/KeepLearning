//
//  Rectangle.cpp
//  CppTest
//
//  Created by lidahe on 17/1/24.
//  Copyright © 2017年 lidahe. All rights reserved.
//

#include "Rectangle.h"
#include <iostream>

using namespace std;

int main() {
    cout << "\nRectangle\n";
    
    const int size = 20;
    int j=0;
    Shape *shape[size] = {NULL};
    Shape *result[size] = {NULL};

    for(int i=0; i<size; i++) {
        if(i < 10) {
            int width = rand()%10 + 2;
            int height = rand()%10 + 1;
            Rectangle *rectangle = new Rectangle(width, height);
            shape[i] = rectangle;
        } else {
            int radius = rand()%10 + 2;
            Circle *circle = new Circle(radius);
            shape[i] = circle;
        }
        
        shape[i]->setNo(i+1);
    }
    
    for(int i=0; i<size; i++) {
        int area = shape[i]->getArea();
//        cout << area << "\n";
        if(area < 50) {
            delete shape[i];
            shape[i] = NULL;
        } else {
            result[j] = shape[i];
            j++;
        }
    }
    
    cout << "new array print\n";
    for(int i=0; i< j; i++) {
        cout << i  << ": " << result[i]->getArea() << "\n";
    }
    
    for(int i=0; i<size; i++) {
        delete shape[i];
    }
        
    return 0;
}
