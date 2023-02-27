#include "time.h"
#include <string>
#include <iostream>

using namespace std;

bool is_valid(Time const &t)
{
    if (t.h < 0 or t.h > 23)
    {
        return false;
    }

    if (t.m < 0 or t.m > 59)
    {
        return false;
    }

    if (t.s < 0 or t.s > 59)
    {
        return false;
    }

    return true;
}

string to_string(Time const &t)
{
    string tmp;

    if (t.h < 10)
    {
        tmp += '0';
    }

    tmp += to_string(t.h);

    tmp += ':';

    if (t.m < 10)
    {
        tmp += '0';
    }

    tmp += to_string(t.m);

    tmp += ':';

    if (t.s < 10)
    {
        tmp += '0';
    }

    tmp += to_string(t.s);

    return tmp;
}

string to_string(Time const &t, bool exp_form)
{
    Time tmptime{t};
    string tmp;

    if (!is_am(t))
    {
        tmptime.h -= 12;
        exp_form = false;
    }

    tmp = to_string(tmptime);

    if (exp_form)
    {
        tmp += " am";
    }
    else
    {
        tmp += " pm";
    }

    return tmp;
}

bool is_am(Time const &t)
{
    return (t.h < 12);
}

bool operator==(Time const &t1, Time const &t2)
{
    if (t1.h != t2.h)
    {
        return false;
    }

    if (t1.m != t2.m)
    {
        return false;
    }

    if (t1.s != t2.s)
    {
        return false;
    }

    return true;
}

bool operator!=(Time const &t1, Time const &t2)
{
    return !(t1 == t2);
}

Time operator+(Time const &t, int i)
{
    Time tmp{t};
    tmp.s += i;

    if (tmp.s > 59)
    {
        tmp.m += tmp.s / 60;
        tmp.s = tmp.s % 60;
    }

    if (tmp.m > 59)
    {
        tmp.h += tmp.m / 60;
        tmp.m = tmp.m % 60;
    }

    if (tmp.h >= 24)
    {
        tmp.h = tmp.h % 24;
    }

    return tmp;
}

Time operator-(Time const &t, int i)
{
    Time tmp{t};
    tmp.s -= i;

    if (tmp.s < 0)
    {
        tmp.m += tmp.s / 60 - 1;
        if (tmp.s % 60 < 0)
        {
            tmp.s = 60 + tmp.s % 60;
        }
        else
        {
            tmp.s = tmp.s % 60;
        }
    }

    if (tmp.m < 0)
    {
        tmp.h += tmp.m / 60;
        if (tmp.m % 60 < 0)
        {
            tmp.m = 60 + tmp.m % 60;
            tmp.h -= 1;
        }
        else
        {
            tmp.m = tmp.m % 60;
        }
    }

    if (tmp.h < 0 && tmp.h % 60 < 0)
    {
        tmp.h += 24 + 24 * tmp.h / -24 + tmp.h % 24;
    }
    else if (tmp.h < 0)
    {
        tmp.h += 24 * tmp.h / -24;
    }

    return tmp;
}

Time &operator++(Time &t)
{
    t = t + 1;
    return t;
}

Time operator++(Time &t, int i)
{
    Time tmp{t};
    t = t + 1;
    return tmp;
}

Time &operator--(Time &t)
{
    t = t - 1;
    return t;
}

Time operator--(Time &t, int i)
{
    Time tmp{t};
    t = t - 1;
    return tmp;
}

bool operator<(Time const &t1, Time const &t2)
{
    if (t1.h < t2.h)
    {
        return true;
    }

    if (t1.m < t2.m)
    {
        return true;
    }

    if (t1.s < t2.s)
    {
        return true;
    }

    return false;
}

bool operator>(Time const &t1, Time const &t2)
{
    return !(t1 < t2);
}

bool operator<=(Time const &t1, Time const &t2)
{
    return (t1 < t2 || t1 == t2);
}

bool operator>=(Time const &t1, Time const &t2)
{
    return (t1 > t2 || t1 == t2);
}

ostream &operator<<(ostream &os, Time const &t)
{
    os << to_string(t);
    return os;
}

istream &operator>>(istream &is, Time &t)
{
    char colon1, colon2{};
    is >> t.h >> colon1 >> t.m >> colon2 >> t.s;
    if (!(colon1 == ':' && colon2 == ':') || !is_valid(t))
    {
        is.setstate(ios_base::failbit);
    }
    return is;
}
