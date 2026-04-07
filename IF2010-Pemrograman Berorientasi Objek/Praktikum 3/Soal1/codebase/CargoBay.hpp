#ifndef CARGO_BAY_HPP
#define CARGO_BAY_HPP

#include "Item.hpp"
#include "CargoException.hpp"

template <class T>
class CargoBay {
private:
    Item<T>* arr;
    int capacity;
    int size;

public:
    // TODO Constructor & Destructor
    // Constructor: inisialisasi capacity, size = 0, alokasi array arr.
    // Destructor: Dealokasi array arr.
    CargoBay(int cap) {
        capacity = cap;
        size = 0;
        arr = new Item<T>[cap];
    }

    ~CargoBay() {
        delete[] arr;
        arr = nullptr;
    }

    // TODO Push & Pop (Standard)
    // push: Lempar CargoFullException jika size >= capacity. Taruh item ke index terakhir array
    // pop: Lempar CargoEmptyException jika size <= 0. Return item terakhir (LIFO) dan update size.
    void push(Item<T> item) {
        if (size >= capacity) {
            throw CargoFullException();
        }
        arr[size] = item;
        size++;
    }

    Item<T> pop() {
        if (size <= 0) {
            throw CargoEmptyException();
        }
        size--;
        return arr[size];
    }

    // TODO extractItem
    // Cari item PERTAMA (dimulai dari index 0 hingga size-1)
    // yang nilai `data`-nya SAMA DENGAN `targetData`.
    // Jika ketemu:
    //     - Return Item tersebut.
    //     - Hapus Item tersebut dari array,
    //       lalu geser seluruh Item di kanannya ke kiri agar array tidak bolong.
    //     - Update size.
    // Jika tidak ketemu, lempar ItemNotFoundException.
    Item<T> extractItem(T targetData) {
        int idx = -1;
        for (int i = 0 ; i < size ; i++) {
            if (arr[i].getData() == targetData) {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            throw ItemNotFoundException();
        }

        Item<T> res = arr[idx];
        for (int i = idx ; i < size - 1 ; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        return res;
    }

    // TODO forge
    // Menempa (Menggabungkan) dua Item teratas menjadi satu Item baru.
    // Cek apakah size < 2. Jika ya, lempar NotEnoughItemsException.
    // Jika aman, keluarkan (pop) item pertama dan item kedua.
    // Buatlah data baru hasil penjumlahan berurutan: `baseData` + data Top 1 + data Top 2.
    //   (Contoh: Jika baseData = "X", Top 1 = "Y", Top 2 = "Z", maka data baru = "XYZ").
    // Dipastikan tipe data T support operator+
    // Buatlah durability baru: rata-rata dari durability item pertama dan kedua (integer division).
    // Buat objek Item baru dengan data & durability baru tersebut, lalu push() ke CargoBay.
    void forge(T baseData) {
        if (size < 2) {
            throw NotEnoughItemsException();
        }

        Item<T> first = pop();
        Item<T> second = pop();

        int newDur = (first.getDurability() + second.getDurability())/2;
        Item<T> res = Item<T>(baseData + first.getData() + second.getData(), newDur);
        push(res);
    }

    // TODO transferTo
    // Pindahkan sejumlah `count` item dari atas cargo `this` ke cargo `other`.
    // PROSES TRANSFER dilakukan satu per satu (LIFO).
    // Perhatikan bahwa urutan item akan terbalik.
    // Jika, size < count, lempar NotEnoughItemsException
    // PENANGANAN EXCEPTION:
    //    - Jika other ternyata penuh di tengah jalan (melempar CargoFullException),
    //      TANGKAP error tersebut dengan try-catch!
    //    - Kembalikan 1 item yang gagal masuk itu ke cargo `this`.
    //    - Lempar TransferFailedException ke luar fungsi untuk memberitahu bahwa transfer terhenti.
    void transferTo(CargoBay<T>& other, int count) {
        if (this->size < count) {
            throw NotEnoughItemsException();
        }
        for (int i = 0 ; i < count ; i++) {
            Item<T> popItem = pop();       
            try {
                other.push(popItem);     
            } 
            catch (CargoFullException& e) {
                push(popItem);
                throw TransferFailedException(); 
            }
        }
    }
};

#endif
