#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Mahasiswa {
    private:
        string name;
        string nim;
        float ipk;
        int total_sks;

    public:
        static int counter;

    public:
        Mahasiswa() {
            this->name = "NPC";
            this->nim = "135" + to_string(counter);
            this->ipk = 0.00;
            this->total_sks = 0;
            Mahasiswa::counter++;
        }

        Mahasiswa(string name) {
            this->name = name;
            this->nim = "135" + to_string(counter);
            this->ipk = 0.00;
            this->total_sks = 0;
            Mahasiswa::counter++;
        }

        void tambahNilai(float nilai, int sksBaru) {
            ipk = ((ipk * total_sks) + (nilai * sksBaru)) / (total_sks + sksBaru);
            this->total_sks += sksBaru;
        }

        void info() {
            cout << "INFORMASI MAHASISWA" << endl;
            printf("Nama: %s\n", name.c_str());
            printf("NIM: %s\n", nim.c_str());
            printf("IPK: %.2f\n", ipk);
            printf("SKS: %d\n", total_sks);
        }
};
int Mahasiswa::counter = 0;

// int main() {
//     Mahasiswa satu("Ahmad");
//     Mahasiswa dua;
//     satu.info();
//     dua.info();

//     satu.tambahNilai(4.0, 4);
//     satu.info();
// }