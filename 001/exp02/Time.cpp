#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Time.h"
using namespace std;

Time::Time(int h, int m, int s)
{
    setTime(h, m, s);
}

void Time::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void Time::setHour(int h)
{
    if (h >= 0 && h < 24)
        hour = h;
    else
        throw invalid_argument("hour must be 0-23");
}

void Time::setMinute(int m)
{
    if (m >= 0 && m < 60)
        minute = m;
    else
        throw invalid_argument("minute must be 0-59");
}
void Time::setSecond(int s)
{
    if (s >= 0 && s < 60)
        second = s;
    else
        throw invalid_argument("second must be 0-59");
}
void Time::printUniversal() const
{
    cout << setfill('0') << setw(2) << getHour() << ":" << setw(2) << getMinute() << ":" << setw(2) << getSecond();
}
void Time::printStandard() const
{
    cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":" << setfill('0') << setw(2) << getMinute() << ":" << setw(2) << getSecond() << (hour < 12 ? " AM" : " PM");
}

unsigned int Time::getHour() const
{
    return hour;
}
unsigned int Time::getMinute() const
{
    return minute;
}
unsigned int Time::getSecond() const
{
    return second;
}

void Time::tick_InsideTime()
{
    if (second < 59)
        second++;
    else
    {
        second = 0;
        if (minute < 59)
            minute++;
        else
        {
            minute = 0;
            if (hour < 23)
                hour++;
            else
                hour = 0;
        }
    }
}

void tick_Friend(Time &t)
{
    if (t.second < 59)
        t.second++;
    else
    {
        t.second = 0;
        if (t.minute < 59)
            t.minute++;
        else
        {
            t.minute = 0;
            if (t.hour < 23)
                t.hour++;
            else
                t.hour = 0;
        }
    }
}
