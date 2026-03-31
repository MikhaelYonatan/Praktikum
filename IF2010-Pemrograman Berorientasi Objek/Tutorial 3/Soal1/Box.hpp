#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>
using namespace std;

template <class T>
class Box {
private:
    T value;

public:
    // constructor
    Box();
    Box(T value);

    // getter setter
    void setValue(T value);
    T getValue() const;
    
    // cetak dengan format: "Value: [nilai]"
    void printValue() const;
};

// ================= IMPLEMENTATION =================

template <class T>
Box<T>::Box():value(T()) {};

template <class T>
Box<T>::Box(T value):value(value) {};

template <class T>
void Box<T>::setValue(T value) {
    this->value = value;
}

template <class T>
T Box<T>::getValue() const {
    return value;
}

template <class T>
void Box<T>::printValue() const {
    cout << "Value: " << value << endl;
}

template <class T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

#endif