//
//  Date.hpp
//  CppTest
//
//  Created by lidahe on 17/1/23.
//  Copyright © 2017年 lidahe. All rights reserved.
//

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Date;
inline bool
__greater(const Date& date1, const Date& date2);

class Date {
    
public:
    Date (int year = 2000, int month = 1, int day = 1): year(year), month(month), day(day) {
        dateStr = new char[16];
        sprintf(dateStr, "%d-%d-%d", year, month, day);
    }
    ~Date();
    Date& operator == (const Date&);
    char* get_c_str() const {
        return dateStr;
    };
    int daysTotalNumber() const;
    void print() {
        printf("%s\n", dateStr);
    }
    void setDate(int _year, int _month, int _day) {
        delete[] dateStr;
        year = _year;
        month = _month;
        day = _day;
        dateStr = new char[16];
        sprintf(dateStr, "%d-%d-%d", year, month, day);
    }
    static void CreatePoints(Date arr[], const int size) {
        for(int i=0; i<size; i++) {
            int year = rand()%110 + 1900;
            int month = rand()%12 + 1;
            int day = rand()%30 + 1;
            
            Date &date = arr[i];
            date.setDate(year, month, day);
        }
    };
    
private:
    int year,month,day;
    char* dateStr;
    friend bool __greater(const Date&, const Date&);
};

inline bool
operator > (const Date& date1, const Date& date2) {
    return __greater(date1, date2);
}

inline bool
operator < (const Date& date1, const Date& date2) {
    return !__greater(date1, date2);
}

Date::~Date() {
    delete[] dateStr;
}

inline bool
__greater(const Date& date1, const Date& date2) {
    if(date1.daysTotalNumber() > date2.daysTotalNumber()) {
        return true;
    } else if(date1.daysTotalNumber() < date2.daysTotalNumber()) {
        return false;
    }
    return true;
}

int Date::daysTotalNumber() const {
    return this->year * 365 + this->month * 31 + day;
}

ostream& operator<<(ostream& os, const Date& date1)
{
    os << date1.get_c_str();
    return os;
}

#endif /* Date_hpp */
