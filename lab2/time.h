#ifndef TIME_H
#define TIME_H
#include <string>

struct Time
{
    int h;
    int m;
    int s;
};

bool is_valid(Time const &t);

std::string to_string(Time const &t);
std::string to_string(Time const &t, bool exp_form);

bool is_am(Time const &t);

bool operator==(Time const &t1, Time const &t2);

bool operator!=(Time const &t1, Time const &t2);

Time operator+(Time const &t, int i);

Time operator-(Time const &t, int i);

Time &operator++(Time &t);

Time operator++(Time &t, int i);

Time &operator--(Time &t);

Time operator--(Time &t, int i);

bool operator<(Time const &t1, Time const &t2);

bool operator>(Time const &t1, Time const &t2);

bool operator<=(Time const &t1, Time const &t2);

bool operator>=(Time const &t1, Time const &t2);

std::ostream &operator<<(std::ostream &os, Time const &t);

std::istream &operator>>(std::istream &is, Time &t);

#endif
