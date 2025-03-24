//
// Created by Семён Евдокимович on 24.03.2025.
//
#include "vesy.h"
#include <fstream>
#include <iostream>
int main() {
    vesy a("Semen",1, 9,24);
    double j;
    for (int i=0; i < 100; i++) {
        int d = a.get_day(i);
        int m = a.get_month(i);
        int y = a.get_year(i);
        a.set_height(j,d,m,y);
        j++;

    }
    std::ofstream outFile("semen.txt");
    if (outFile.is_open()) {
        outFile << "Date:   Weight:"<< std::endl;
        outFile << a;
        outFile.close();
    } else {
        std::cout << "Error opening file" << std::endl;
    }
    vesy b;
    std::ifstream inFile("semen.txt");
    if (inFile.is_open()) {
        inFile >> b;
        inFile.close();
    } else {
        std::cout << "Error opening file" << std::endl;
    }
    std::cout << b << std::endl;
}