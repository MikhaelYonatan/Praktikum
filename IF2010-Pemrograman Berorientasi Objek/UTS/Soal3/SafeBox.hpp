#ifndef SAFE_BOX_HPP
#define SAFE_BOX_HPP

#include <iostream>
#include <functional>
#include <stack>
#include <vector>
#include "SafeBoxException.hpp"
// include header lain jika diperlukan (stack, vector, algorithm, etc.)

using namespace std;

// Template class SafeBox<T>:
// Menyimpan elemen bertipe T secara LIFO dengan kapasitas terbatas.
// Implementasi internal dibebaskan, dapat menggunakan stack, vector, atau struktur data lain sesuai kebutuhan.
template<typename T>
class SafeBox {
private : 
    int cap;
    stack<T> st;
    function<bool(const T&)> validator;
    // TODO: deklarasikan atribut private yang diperlukan
public:
    // Inisialisasi box dengan kapasitas maksimum dan validator opsional.
    // Jika validator diberikan, store() akan melempar InvalidItemException
    // untuk item yang tidak lolos validasi.
    SafeBox(int capacity, function<bool(const T&)> validator = nullptr) : cap(capacity), validator(validator){}

    // Menyimpan item ke dalam box.
    // Lakukan hal berikut secara berurutan:
    // 1. Lempar InvalidItemException jika validator ada dan item tidak valid.
    // 2. Lempar BoxFullException(cap) jika items.size() >= cap.
    // 3. Tambahkan item ke box jika valid
    // Hint: Gunakan validator(item) untuk validasi, dan periksa apakah validator tidak nullptr sebelum dipanggil.
    void store(const T& item){
        if (validator && !validator(item)) throw InvalidItemException<T>(item);
        if (st.size() >= cap) throw BoxFullException(cap);
        st.push(item);
    }

    // Mengambil dan menghapus item teratas (LIFO).
    // Lempar BoxEmptyException jika kosong.
    T retrieve(){
        if (st.empty()) throw BoxEmptyException();
        T item = st.top();
        st.pop();
        return item;
    }

    // Melihat item teratas tanpa menghapusnya.
    // Lempar BoxEmptyException jika kosong.
    T peek() const{
        if (st.empty()) throw BoxEmptyException();
        return st.top();
    }

    // Membalik urutan semua elemen dalam box.
    // Lempar BoxEmptyException jika box kosong saat dipanggil.
    void reverse(){
    if (st.empty()) throw BoxEmptyException();

    vector<T> temp;

    while (!st.empty()) {
        temp.push_back(st.top());
        st.pop();
    }

    for (auto &x : temp) {
        st.push(x);
    }
}

    // Mengembalikan jumlah item saat ini.
    int size() const{
        return int(st.size());
    }

    // Mengembalikan kapasitas maksimum box.
    int capacity() const{
        return cap;
    }

    // Mengembalikan true jika box kosong.
    bool isEmpty() const{
        return st.empty();
    }

    // Mencetak isi box dari bawah ke atas: [item_bawah, ..., item_atas]
    // Jika kosong, cetak [].
    friend ostream& operator<<(ostream& os, const SafeBox<T>& box) {
        if(box.st.empty()){
            os << "[]";
            return os;
        }
        stack<T> temp = box.st;
        vector<T> temp1;
        while (!temp.empty()){
            temp1.push_back(temp.top());
            temp.pop();
        }
        os << "[";
        for (auto i = temp1.rbegin(); i != temp1.rend(); i++){
            os << *i;
            if (i!= temp1.rend() -1) os <<", ";
        }
        os << "]";
        return os;
    }
};

// Template function safeMerge:
// Memindahkan item dari src ke dst satu per satu (urutan LIFO).
// Hentikan jika dst penuh (tangkap BoxFullException secara internal).
// Kembalikan jumlah item yang berhasil dipindahkan.
template<typename T>
int safeMerge(SafeBox<T>& src, SafeBox<T>& dst) {
    int count = 0;
    while (!src.isEmpty()){
    try {
        T item = src.peek();    
        dst.store(item);         
        src.retrieve();      
        count++;
    }
    catch (BoxFullException&) {
        break;
    }
    }
    return count; 

}

#endif