#include "catch.hpp"
#include "time.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TEST_CASE("Testing is_valid()")
{
    Time valid{12, 21, 00};
    Time hour_too_big{69, 53, 23};
    Time hour_too_small{-69, 48, 20};
    Time minute_too_big{12, 69, 23};
    Time minute_too_small{12, -69, 9};
    Time seconds_too_big{12, 56, 69};
    Time seconds_too_small{12, 44, -69};

    CHECK(is_valid(valid));
    CHECK_FALSE(is_valid(hour_too_big));
    CHECK_FALSE(is_valid(hour_too_small));
    CHECK_FALSE(is_valid(minute_too_big));
    CHECK_FALSE(is_valid(minute_too_small));
    CHECK_FALSE(is_valid(seconds_too_big));
    CHECK_FALSE(is_valid(seconds_too_small));
}

TEST_CASE("Testing to_string()")
{
    Time morning{8, 21, 00};
    Time evening{20, 34, 59};

    string twelwe_hour_morning{};
    string twenty_four_hour_morning{};
    string twelwe_hour_evening{};
    string twenty_four_hour_evening{};

    istringstream am{"08:21:00 am"};
    getline(am, twelwe_hour_morning);

    istringstream digital_morning{"08:21:00"};
    getline(digital_morning, twenty_four_hour_morning);

    istringstream pm{"08:34:59 pm"};
    getline(pm, twelwe_hour_evening);

    istringstream digital_evening("20:34:59");
    getline(digital_evening, twenty_four_hour_evening);

    CHECK(to_string(morning, true) == twelwe_hour_morning);
    CHECK(to_string(morning) == twenty_four_hour_morning);
    CHECK(to_string(evening, true) == twelwe_hour_evening);
    CHECK(to_string(evening) == twenty_four_hour_evening);
    CHECK_FALSE(to_string(evening) == twelwe_hour_evening);
}

TEST_CASE("Testing is_am()")
{
    Time morning{8, 21, 00};
    Time evening{20, 52, 12};

    CHECK(is_am(morning));
    CHECK_FALSE(is_am(evening));
}

TEST_CASE("Testing operator==()")
{
    Time t1{12, 21, 00};
    Time t2{12, 21, 00};
    Time t3{11, 21, 00};
    CHECK(t1 == t2);
    CHECK_FALSE(t1 == t3);
}

TEST_CASE("Testing operator!=()")
{
    Time t1{12, 21, 00};
    Time t2{12, 21, 55};
    Time t3{12, 21, 00};
    CHECK(t1 != t2);
    CHECK_FALSE(t1 != t3);
}

TEST_CASE("Testing operator+()")
{
    Time t1{23, 59, 30};
    Time t2{0, 0, 30};

    Time t3 = t1 + (86400 * 3 + 60);
    Time t4 = t1 + (86400 * 7 + 30);

    CHECK(t3 == t2);
    CHECK_FALSE(t4 == t2);
}

TEST_CASE("Testing operator-()")
{
    Time t1{0, 0, 0};
    Time t2{9, 2, 57};

    Time t3 = t1 - 53823;
    Time t4 = t1 - (86400 * 3 - 30);
    CHECK(t3 == t2);
    CHECK_FALSE(t4 == t2);
}

TEST_CASE("Testing operator++ prefix")
{
    Time t1{12, 21, 11};
    Time t2{12, 21, 12};
    Time t3{23, 59, 59};
    Time t4{0, 0, 0};

    CHECK(++t1 == t2);
    CHECK(++t3 == t4);

    Time t5{t1};

    CHECK_FALSE(t5 == ++t1);
}

TEST_CASE("Testing operator++ postfix")
{
    Time t1{12, 21, 10};
    Time t2{12, 21, 11};
    Time t3{23, 59, 59};
    Time t4{0, 0, 0};

    Time t5{t1};

    CHECK(t1++ == t5);
    CHECK(t1 == t2);

    CHECK_FALSE(t3++ == t4);
    CHECK(t3 == t4);

    CHECK_FALSE(t1 == t1++);
}

TEST_CASE("Testing operator-- prefix")
{
    Time t1{12, 21, 10};
    Time t2{12, 21, 9};
    Time t3{0, 0, 0};
    Time t4{23, 59, 59};

    CHECK(--t1 == t2);
    CHECK(--t3 == t4);

    Time t5{t1};

    CHECK_FALSE(--t1 == t5);
}

TEST_CASE("Testing operator-- postfix")
{
    Time t1{12, 21, 10};
    Time t2{12, 21, 9};
    Time t3{0, 0, 0};
    Time t4{23, 59, 59};

    Time t5{t1};

    CHECK(t1-- == t5);
    CHECK(t1 == t2);

    CHECK_FALSE(t3-- == t4);
    CHECK(t3 == t4);

    CHECK_FALSE(t1 == t1--);
}

TEST_CASE("Testing operator< ")
{
    Time t1{12, 21, 8};
    Time t2{12, 21, 9};
    Time t3{23, 59, 59};
    Time t4{0, 0, 0};

    CHECK(t1 < t2);
    CHECK(t4 < t3);
    CHECK_FALSE(t2 < t1);
    CHECK_FALSE(t3 < t4);
}

TEST_CASE("Testing operator>")
{
    Time t1{12, 21, 10};
    Time t2{12, 21, 9};
    Time t3{23, 59, 59};
    Time t4{0, 0, 0};

    CHECK(t1 > t2);
    CHECK(t3 > t4);
    CHECK_FALSE(t2 > t1);
    CHECK_FALSE(t4 > t3);
}

TEST_CASE("Testing operator <=")
{
    Time t1{12, 21, 8};
    Time t2{12, 21, 9};
    Time t3{12, 21, 9};

    CHECK(t1 <= t2);
    CHECK(t2 <= t3);
    CHECK_FALSE(t2 <= t1);
}

TEST_CASE("Testing operator >=")
{
    Time t1{12, 21, 11};
    Time t2{12, 21, 10};
    Time t3{12, 21, 10};

    CHECK(t1 >= t2);
    CHECK(t2 >= t3);
    CHECK_FALSE(t2 >= t1);
}

TEST_CASE("Testing operator<<()")
{
    Time h{9, 21, 00};
    ostringstream oss{};

    oss << h;
    CHECK(oss.str() == "09:21:00");
    CHECK_FALSE(oss.str() == "9:21:0");
}

TEST_CASE("Testing operator>>()")
{
    istringstream iss{"12:21:00"};
    istringstream iss2{"100:100:100"};
    Time t;
    Time t2;
    iss >> t;
    iss2 >> t2;
    CHECK_FALSE(iss.fail());
    CHECK(iss2.fail());
    CHECK(to_string(t) == "12:21:00");
}
