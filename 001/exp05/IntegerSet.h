#ifndef INTEGERSET_H
#define INTEGERSET_H

class IntegerSet
{
public:
    IntegerSet();
    IntegerSet(const IntegerSet &);
    IntegerSet(const int[], int);
    // 析构默认即可

    void inputSet();

    IntegerSet unionOfSets(const IntegerSet &) const;
    IntegerSet intersectionOfSets(const IntegerSet &) const;
    void insertElement(int);
    void deleteElement(int);
    void printSet() const;
    bool isEqualTo(const IntegerSet &) const;

private:
    int validEntry(int) const;
    bool set[101] = {0};
};

#endif // INTEGERSET_H