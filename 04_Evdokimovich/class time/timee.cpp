//
// Created by Семён Евдокимович on 24.02.2025.
//
#include <iostream>
#include "timee.h"
using namespace std;

int main() {
  timee ti1,ti2,ti3,ti4,ti5;
  int h,m,s;
  /*cout<<"Enter time in seconds: ";
  cin>>s;
  cout<<"Enter time in minutes: ";
  cin>>m;
  cout<<"Enter time in hours: ";
  cin>>h;*/
  ti1.set_hour(2);
  ti1.set_minute(50);
  ti1.set_second(50);
  ti2.set_hour(1);
  ti2.set_minute(30);
  ti2.set_second(30);
  ti3.set_hour(0);
  ti3.set_minute(0);
  ti3.set_second(0);
  ti4.set_hour(0);
  ti4.set_minute(0);
  ti4.set_second(0);
  /*ti.print_time();
  ti.plus_second(1);
  ti.print_time();*/
  ti4 = ti3.difference(ti1,ti2);
  ti4.print_time();
  cout<<endl;

}
