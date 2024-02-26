#ifndef TIME_H
#define TIME_H

class Time
{
public:
    explicit Time(int = 0, int = 0, int = 0);
    void setTime(int, int, int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    unsigned getHour() const;
    unsigned getMinute() const;
    unsigned getSecond() const;

    void printUniversal() const;
    void printStandard() const; // 打印时间，12小时制
    void tick_InsideTime();
    friend void tick_Friend(Time &);

private:
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
};

#endif // TIME_H