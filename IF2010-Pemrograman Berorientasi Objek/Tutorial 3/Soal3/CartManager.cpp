#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct GameEntry {
    string title;
    float price;

    GameEntry(string t, float p) {
        title = t;
        price = p;
    }
};

class CartManager {
private:
    vector<GameEntry> cart;
    vector<GameEntry> purchase;

public:
    void addToCart(string title, float price) {
        // TODO: Menambahkan game ke akhir keranjang. Judul yang sama boleh muncul lebih dari sekali.
        cart.push_back(GameEntry(title, price));
    }

    bool removeFromCart(string title) {
        // TODO: Menghapus kemunculan pertama game dengan judul tersebut. Kembalikan true jika berhasil, false jika tidak ditemukan. Urutan harus tetap terjaga.
        for (auto it = cart.begin() ; it != cart.end() ; it++) {
            if (it->title == title) {
                cart.erase(it);
                return true;
            }
        }
        return false;
    }

    void checkout() {
        // TODO: Memindahkan semua game dari keranjang ke library, lalu mengosongkan keranjang. Jika keranjang kosong, tidak melakukan apa-apa.
        if (cart.size() == 0) return;

        purchase.insert(purchase.end(), cart.begin(), cart.end());
        cart.clear();
    }

    float cartTotal() {
        // TODO: Mengembalikan total harga semua item di keranjang.
        float total = 0.0;
        for (const GameEntry& g : cart) {
            total += g.price;
        }
        return total;
    }

    float applyDiscount(float percent) {
        // TODO: Menerapkan diskon (misalnya 10.0 = 10%) ke semua item dalam keranjang secara langsung (price game dalam keranjang berubah). Mengembalikan total baru. Jika keranjang kosong, kembalikan 0.0.
        float total = 0.0;
        float discount = (100.0 - percent) / 100;
        for (auto it = cart.begin() ; it != cart.end() ; it++) {
            it->price = it->price * discount;
            total += it->price;
        }
        return total;
    }

    int countInCart(string title) {
        // TODO: Menghitung berapa kali game dengan judul tersebut muncul di keranjang.
        int occurr = 0;
        for (const GameEntry& g : cart) {
            if (g.title == title) {
                occurr++;
            }
        }
        return occurr;
    }

    void printCart() {
        // TODO: sesuaikan nama variablenya
        if (cart.size() == 0) {
            cout << "Cart is empty." << endl;
            return;
        }
        for (int i = 0; i < cart.size(); i++) {
            cout << "[" << i << "] " << cart[i].title << " - $" << cart[i].price << endl;
        }
    }

    void printPurchased() {
        // TODO: sesuaikan nama variablenya
        if (purchase.size() == 0) {
            cout << "No purchases yet." << endl;
            return;
        }
        for (int i = 0; i < purchase.size(); i++) {
            cout << "[" << i << "] " << purchase[i].title << " - $" << purchase[i].price << endl;
        }
    }

    int totalPurchased() {
        // TODO: Mengembalikan jumlah total game yang ada di library.
        return purchase.size();
    }
};

int main() {
    CartManager cm;
    int q;
    
    if (!(cin >> q)) return 0;

    cout << fixed << setprecision(2);

    for (int i = 0; i < q; i++) {
        string op;
        cin >> op;

        if (op == "ADD") {
            string title; float price;
            cin >> title >> price;
            cm.addToCart(title, price);
        } else if (op == "REMOVE") {
            string title; cin >> title;
            if (cm.removeFromCart(title))
                cout << "Removed: " << title << "\n";
            else
                cout << "Not found: " << title << "\n";
        } else if (op == "CHECKOUT") {
            cm.checkout();
        } else if (op == "TOTAL") {
            cout << "Cart total: $" << cm.cartTotal() << "\n";
        } else if (op == "DISCOUNT") {
            float pct; cin >> pct;
            cout << "After discount: $" << cm.applyDiscount(pct) << "\n";
        } else if (op == "COUNT") {
            string title; cin >> title;
            cout << title << ": " << cm.countInCart(title) << " in cart\n";
        } else if (op == "PRINT_CART") {
            cm.printCart();
        } else if (op == "PRINT_PURCHASED") {
            cm.printPurchased();
        } else if (op == "PURCHASED_COUNT") {
            cout << "Total purchased: " << cm.totalPurchased() << "\n";
        }
    }

    return 0;
}