#ifndef SAFE_BOX_EXCEPTION_HPP
#define SAFE_BOX_EXCEPTION_HPP

#include <exception>
#include <string>
#include <sstream>
using namespace std;

// Base class untuk semua exception SafeBox.
// Turunan dari std::exception override what() di setiap subclass.
class SafeBoxException : public exception {
public:
    // TODO: deklarasikan what() sebagai pure virtual
    virtual const char* what() const noexcept = 0;
};


class BoxFullException : public SafeBoxException {
private : 
    int capacity;
    string message; 
public:
    // TODO: konstruktor menerima kapasitas (int)
    BoxFullException(int capacity): SafeBoxException(), capacity(capacity){
        message = "Box penuh: kapasitas maks " + to_string(capacity);
    }

    // TODO: implementasi what() -> "Box penuh: kapasitas maks N"
    const char* what() const noexcept {
        return message.c_str();
    }
};


class BoxEmptyException : public SafeBoxException {
private : 
    string message; 
public:
    BoxEmptyException() {
        message = "Box kosong";
    }
    // TODO: implementasi what() -> "Box kosong"
    const char* what() const noexcept {
        return message.c_str();
    }
};


// Template: item yang tidak valid dapat bertipe apa saja (int, string, dll.)
// Gunakan ostringstream untuk mengonversi T ke string di dalam what().
// Contoh penggunaan ostringstream:
// int x = 42;
// ostringstream oss;
// oss << "Nilai x: " << x;
// string msg = oss.str(); // msg = "Nilai x: 42"
template<typename T>
class InvalidItemException : public SafeBoxException {
private:
    T item; 
    string message; 
public:
    // TODO: konstruktor menerima item (const T&)
    InvalidItemException(const T& item) : item(item){
        ostringstream oss; 
        oss << "Item tidak valid: " << item;
        message = oss.str();
    }
    // TODO: implementasi what() -> "Item tidak valid: <item>"
    const char* what() const noexcept{
        return message.c_str();
    }

};

#endif