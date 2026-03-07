#include <iostream>
#include "Penganan.hpp"
using namespace std;

int Penganan::uang = 0;
int Penganan::n_rumah = 0;

Penganan::Penganan() {
    keik = 0;
    panekuk = 0;
}

// ctor dengan parameter
Penganan::Penganan(int keik, int panekuk) {
    this->keik = keik;
    this->panekuk = panekuk;
}

//mengembalikan bagian jumlah keik
int Penganan::GetKeik() const {
    return this->keik;
}

// mengembalikan bagian jumlah panekuk
int Penganan::GetPanekuk() const {
    return this->panekuk;
}

// mengisi bagian keik
void Penganan::SetKeik(int a) {
    keik = a;
}

// mengisi bagian panekuk
void Penganan::SetPanekuk(int a) {
    panekuk = a;
}

// operator overloading

// operator+ 
Penganan operator+ (const Penganan& a, const Penganan& b) {
    Penganan::n_rumah++;
    return Penganan(a.GetKeik() + b.GetKeik(), a.GetPanekuk() + b.GetPanekuk());
}

// operator- 
Penganan operator- (const Penganan& a, const Penganan& b) {
    int k1 = a.GetKeik();
    int k2  = b.GetKeik();
    int sisaK;
    int jualK;
    if (k1 < k2) {
        sisaK = 0;
        jualK = k1;
    }
    else {
        sisaK = k1 - k2;
        jualK = k2;
    }

    int p1 = a.GetPanekuk();
    int p2 = b.GetPanekuk();
    int sisaP;
    int jualP;
    if (p1 < p2) {
        sisaP = 0;
        jualP = p1;
    }
    else {
        sisaP = p1 - p2;
        jualP = p2;
    }

    Penganan::uang += 51*jualK + 37*jualP;
    return Penganan(sisaK, sisaP);
}

// operator^ 
Penganan operator^ (const Penganan& a, const int b) {
    Penganan res = a;
    if (a.keik >= b){
        res.keik = a.keik - b;
    }else{
        res.keik = 0;
        Penganan::uang -= (b - a.keik) * 51;
    }

    if (a.panekuk >= b){
        res.panekuk = a.panekuk - b;
    }else{
        res.panekuk = 0;
        Penganan::uang -= (b - a.panekuk) * 37;
    }
    
    return res;
}

// operator^ (sifat komutatif)
Penganan operator^ (const int a, const Penganan& b) {
    return b ^ a;
}

// mengembalikan jumlah uang yang diperoleh
int Penganan::JumlahUang() {
    return uang;
}

// mengembalikan jumlah kunjungan ke rumah
int Penganan::HitungNRumah() {
    return n_rumah;
}

// mencetak isi kantong
// Jangan lupa tambahkan endline di akhir print
// Contoh:
// 0keik-0panekuk
// 111keik-122panekuk
void Penganan::Print() {
    cout << keik << "keik" << "-" << panekuk << "panekuk" << endl;
}