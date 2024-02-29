#include <iostream>
#include "IntegerSet.h"
using namespace std;

IntegerSet::IntegerSet() {}

IntegerSet::IntegerSet(const IntegerSet &other)
{
    // 调用复制构造
    *this = other;
}

IntegerSet::IntegerSet(const int array[], int size)
{
    if (size > 101 || size < 0)
    {
        throw "Array size is out of range";
        return;
    }
    for (int i = 0; i < size; i++)
    {
        if (validEntry(array[i]) == 0)
        {
            cout << "Invalid insert attempted!" << endl;
            continue;
        }
        this->set[array[i]] = 1;
    }
}

void IntegerSet::inputSet()
{
    while (1)
    {
        cout << "Enter an element (-1 to end): ";
        int temp;
        cin >> temp;
        if (temp == -1)
        {
            cout << "Entry complete" << endl;
            break;
        }
        if (validEntry(temp) == 0)
        {
            throw "Element is out of range";
        }
        this->set[temp] = 1;
    }
}

IntegerSet IntegerSet::unionOfSets(const IntegerSet &other) const
{
    IntegerSet result;
    for (int i = 0; i < 101; i++)
        result.set[i] = (this->set[i] | other.set[i]);
    return result;
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet &other) const
{
    IntegerSet result;
    for (int i = 0; i < 101; i++)
        result.set[i] = (this->set[i] & other.set[i]);
    return result;
}

void IntegerSet::insertElement(int element)
{
    if (validEntry(element) == 0)
    {
        throw "Invalid insert attempted!";
        return;
    }
    set[element] = 1;
}

void IntegerSet::deleteElement(int element)
{
    if (validEntry(element) != 1)
    {
        throw "Invalid entry";
        return;
    }
    set[element] = 0;
}

void IntegerSet::printSet() const
{
    cout << "{  ";
    for (int i = 0; i < 101; i++)
        if (set[i])
            cout << i << "  ";
    cout << "}" << endl;
}

bool IntegerSet::isEqualTo(const IntegerSet &other) const
{
    for (int i = 0; i < 101; i++)
        if (set[i] != other.set[i])
            return false;
    return true;
}

int IntegerSet::validEntry(int element) const
{ // 存在1 不存在-1 越界0
    if (element < 0 || element > 100)
        return 0;
    if (set[element] == 0)
        return -1;
    return 1;
}