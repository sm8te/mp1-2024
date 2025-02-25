//
// Created by Семён Евдокимович on 24.02.2025.
//

#ifndef TIMEE_H
#define TIMEE_H


struct time {
    int hour=0;
    int minute=0;
    int second=0;
};

class timee {
  int hour; int minute;int second;
  public:
    //~timee();
    int ho;
    void set_hour(int h) {
        if ( h < 24 and h >=0) hour = h;
        else {
            std::cout << "Error in setting hour, please re-enter\n";
            hour = 0;
        }
    };
    void set_minute(int m) {
        if ( m < 60 and m >= 0 ) minute = m;
        else {
            std::cout << "Error in setting minute, please re-enter\n";
            minute = 0;
        }
    };
    void set_second(int s) {
        if ( s < 60 and s >= 0 ) second = s;
        else {
            std::cout << "Error in setting second, please re-enter\n";
            second = 0;
        }
    };
    int get_hours() {
        return hour;
    };
    int get_minutes() {
        return minute;
    };
    int get_seconds() {
        return second;
    };
    int  min_hour(int h) {
        if(0 <= hour - h) hour = hour - h;
        else {
            hour = 24 + (hour - h);
        }
        return hour;
    }
    int min_minute(int m) {
        if(0 <= minute - m) {
            minute = minute - m;
        }
        else {
            minute = 60 + (minute - m);
            hour = min_hour(1);
        }
        return minute;
    };
    int min_second(int s) {
        if(0 <= second - s) {
            second = second - s;

        } else {
            second = 60 + (second - s);
            minute = min_minute(1);
        }
        return second;
    };
    int plus_hour(int h) {
        if(23 >= hour + h) hour = hour + h;
        else {
            hour = (hour + h) - 24;
        }
        return hour;
    }
    int plus_minute(int m) {
        if(59 >= minute + m) minute = minute + m;
        else {
            minute =(minute + m) - 60;
            hour = plus_hour(1);
        }
        return minute;
    }
    int plus_second(int s) {
        if(59 >= second + s) {
            second = second + s;

    } else {
        second = (second + s) - 60;
        minute = plus_minute(1);
    }
    }
    void print_time() {
       if ( hour < 10 ) {
           std::cout <<'0'<< hour << ":";
       } else {
           std::cout << hour << ":";
       }
        if ( minute < 10 ) {
            std::cout <<'0'<< minute << ":";

    } else {
        std::cout << minute << ":";
    }
        if ( second < 10 ) {
            std::cout << '0'<<second << "\n";

    } else {
        std::cout << second << "\n";
    }
    }
    timee difference(timee t1, timee t2) {
        timee diff;
        int hours1 = t1.get_hours();
        int hours2 = t2.get_hours();
        int minutes1 = t1.get_minutes();
        int minutes2 = t2.get_minutes();
        int seconds1 = t1.get_seconds();
        int seconds2 = t2.get_seconds();
        if ( hours1 < hours2 ) {
            diff.set_hour(t2.min_hour(hours1));
            if (minutes1 < minutes2) {
                diff.set_minute(t2.min_minute(minutes1));
                if (seconds1 <= seconds2) {
                    diff.set_second(t2.min_second(seconds1));
                } else {
                    diff.set_second((60 + (t2.get_seconds()-t1.get_seconds())));
                    diff.set_minute(t2.min_minute(1));
                    diff.set_hour(t2.get_hours());
                }
            } else {
                diff.set_minute(t2.plus_minute(minutes1));
                diff.set_hour(t2.min_hour(1));
                if (seconds1 <= seconds2) {
                    diff.set_second(t2.min_second(seconds1));
                } else {
                    diff.set_second((60 + (t2.get_seconds()-t1.get_seconds())));
                    diff.set_minute(t2.min_minute(1));
                    diff.set_hour(t2.get_hours());
                }
            }
        } else {
            diff.set_hour(t1.min_hour(hours2));
            if (minutes2 < minutes1) {
                diff.set_minute(t1.min_minute(minutes2));
                if (seconds2 <= seconds1) {
                    diff.set_second(t1.min_second(seconds2));
                } else {
                    diff.set_second((60 + (t1.get_seconds()-t2.get_seconds())));
                    diff.set_minute(t1.min_minute(1));
                    diff.set_hour(t1.get_hours());
                }
            } else {
                diff.set_minute(t1.plus_minute(minutes2));
                diff.set_hour(t1.min_hour(1));
                if (seconds2 <= seconds1) {
                    diff.set_second(t1.min_second(seconds2));
                } else {
                    diff.set_second((60 + (t1.get_seconds()-t2.get_seconds())));
                    diff.set_minute(t1.min_minute(1));
                    diff.set_hour(t2.get_hours());
                }
            }
        }
        return diff;
    }
};


#endif //TIMEE_H
