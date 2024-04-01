#include "String.h"

ostream &operator<<(ostream &os, const String &str)
{
    os << str.sPtr;
    return os;
}

String::String(const char *s)
{
    length = 0;
    while (s[length] != '\0')
        length++;
    sPtr = new char[++length];
    strcpy(sPtr, s);
}

String::String(const String &str)
{
    length = str.length;
    sPtr = new char[length];
    strcpy(sPtr, str.sPtr);
}

String::~String()
{
    delete[] sPtr;
    sPtr = NULL;
}

const String &String::operator=(const String &str)
{
    if (this == &str)
        return *this;
    delete[] sPtr;
    sPtr = NULL;
    length = str.length;
    sPtr = new char[length];
    strcpy(sPtr, str.sPtr);
    return *this;
}

String String::operator+(const String &str) const
{
    String newStr;
    newStr.length = length + str.length - 1;
    newStr.sPtr = new char[newStr.length];
    strcpy(newStr.sPtr, sPtr);
    strcat(newStr.sPtr, str.sPtr);
    return newStr;
}
