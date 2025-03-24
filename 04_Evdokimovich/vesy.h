//
// Created by Семён Евдокимович on 21.03.2025.
//

#ifndef VESY_H
#define VESY_H
#include <ostream>


class vesy {
    int day[100];
    int month[100];
    int year[100];
    char *name;
    double heigh[100];
    int days=100;
    public:
    vesy(char *n = "Name", int d = 0, int m = 0, int y = 0, double h = 0);
    vesy(const vesy& v);
    void print();
    void set_height(double h, int d, int m, int y);
    void set_data(int d, int m, int y);
    int get_day(int d);
    int get_month(int m);
    int get_year(int y);
    double average();
    double minimum(int month);
    double minimum();
    double maximum(int month);
    double maximum();
    friend std::ostream& operator<<(std::ostream& os, const vesy& v);
    friend std::istream& operator>>(std::istream& is, vesy& v);
    ~vesy();
};



#endif //VESY_H
