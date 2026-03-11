#include "Authenticator.hpp"

Authenticator::Authenticator() {
    for (int i = 0 ; i < MAX_USERS ; i++) {
        users[i] = nullptr;
    }
    userCount = 0;
    currentUser = nullptr;
    secretResource = "Ini adalah data rahasia!";
}

void Authenticator::registerUser(const string &username, const string &password, bool isAdmin) {
    bool found = false;
    if (userCount < MAX_USERS) {
        for (int i = 0 ; i < userCount && !found ; i++) {
            if (users[i]->getUsername() == username) {
                found = true;
            }
        }

        if (!found) {
            User* user;
            if (isAdmin) {
                user = new AdminUser(username, password);
            }
            else {
                user = new User(username, password);
            }
            users[userCount] = user;
            userCount++;
            cout << "Sukses: User " << username << " berhasil terdaftar!" << endl;
        }
        else {
            cout << "Gagal: Username sudah digunakan!" << endl;
        }
    }
    else {
        cout << "Gagal: Kapasitas user penuh!" << endl;
    }
}

void Authenticator::login(const string &username, const string &password) {
    bool found = false;
    for (int i = 0 ; i < userCount && !found ; i++) {
        if (users[i]->getUsername() == username) {
            if (users[i]->checkPassword(password)) {
                currentUser = users[i];
                cout << "Sukses: Login berhasil! Selamat datang, " << username << "." << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "Gagal: Username atau password salah!" << endl;
    }
}

void Authenticator::logout() {
    if (currentUser == nullptr) {
        cout << "Gagal: Tidak ada user yang sedang login!" << endl;
    }
    else {
        cout << "Sukses: User " << currentUser->getUsername() << " telah logout." << endl;
        currentUser = nullptr;
    }
}

void Authenticator::accessResource() const {
    if (currentUser == nullptr) {
        cout << "Akses ditolak! Silakan login terlebih dahulu." << endl;   
    }
    else {
        cout << "Resource: " << secretResource << endl;
    }
}

void Authenticator::setResource(const string &newResource) {
    if (currentUser == nullptr) {
        cout << "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu." << endl;
    }
    else {
        if (currentUser->isAdmin()) {
            secretResource = newResource;
            cout << "Sukses: Resource telah diperbarui oleh " << currentUser->getUsername() << "." << endl;
        }
        else {
            cout << "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat melakukan ini." << endl;
        }
    }
}

Authenticator::~Authenticator() {
    for (int i = 0 ; i < userCount ; i++) {
        delete users[i];
    }
}