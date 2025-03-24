//
// Created by Семён Евдокимович on 21.03.2025.
//

#include "vesy.h"

#include <iostream>
#include <ostream>

vesy::vesy(char *n, int d, int m, int y, double h) {
    name = new char[strlen(n) + 1];
    name = strcpy(name, n);
    for (int i=0; i < days; i++) {
        day[i]=d;
        month[i]=m;
        year[i]=y;
        heigh[i] = h;
        if (d<=30) {
            d++;
        } else if (m<12) {
            m++;
            d=1;
        } else {
            m=1;
            y++;
        }
    }
}
vesy::vesy(const vesy &v) {
    delete [] name;
    name = new char[strlen(v.name) + 1];
    name=v.name;
    for (int i=0; i <days; i++) {
        day[i] = v.day[i];
        month[i] = v.month[i];
        year[i] = v.year[i];
        heigh[i] = v.heigh[i];
    }
}
void vesy::print() {
    std::cout<<"Name: "<<name<<std::endl;
    for (int i=0; i <days; i++) {
        std::cout<<day[i]<<"."<<month[i]<<"."<<year[i]<<": "<<heigh[i]<<std::endl;
    }
}
void vesy::set_data(int d, int m, int y) {

}
void vesy::set_height(double h, int d, int m,int y) {
    int ho = 373*y + m*31 + d;
    ho = ho - year[0]*373 - month[0]*31 - day[0];
    heigh[ho]= h;
}
int vesy::get_day(int d) {
    return day[d];
}
int vesy::get_month(int m) {
    return month[m];
}
int vesy::get_year(int y) {
    return year[y];
}
double vesy::average() {
    int ho = 0;
    for (int i=0; i <days; i++) {
        ho+=heigh[i];
    }
    return ho;
}
double vesy::minimum(int mont) { //добавить структуру в которой будет вес и дата плюс ее вывод
    double mi = 9999;            // либо сделать вывод строки в которой это будет
    int ho = (mont - month[0]+1)*31;
    int ho1 = day[0] + (mont - month[0])*31 - 1;
    for (int i=ho1; i <ho; i++) {
        mi = std::min(mi, heigh[i]);
    }
    return mi;
}
double vesy::minimum() {
    double min = 9999;
    for (int i=0; i <days; i++) {
        min = std::min(min, heigh[i]);
    }
    return min;
}
double vesy::maximum(int mont) {
    double mx = 0;
    int ho = (mont - month[0]+1)*31;
    int ho1 = day[0] + (mont - month[0])*31 - 1;
    for (int i=ho1; i <ho; i++) {
        mx = std::max(mx, heigh[i]);
    }
    return mx;
}
double vesy::maximum() {
    double mx = 0;
    for (int i=0; i <days; i++) {
        mx = std::max(mx, heigh[i]);
    }
    return mx;
}
std::ostream &operator<<(std::ostream &os, const vesy &v){
        for (int i = 0; i < v.days; i++) {
            os << v.day[i] << ".";
            os << v.month[i] << ".";
            os << v.year[i] << " - ";
            os << v.heigh[i] << "kg."<<std::endl;
        }
        return os;
    }
std::istream &operator>>(std::istream &is, vesy &v) {
    for (int i = 0; i < v.days; i++) {
        is >> v.day[i];
        is >> v.month[i];
        is >> v.year[i];
        is >> v.heigh[i];
    }
    return is;
}
vesy::~vesy() {
    delete[] name;
}




