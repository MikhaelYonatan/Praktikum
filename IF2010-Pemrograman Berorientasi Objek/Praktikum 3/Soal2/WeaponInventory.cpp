#include "WeaponInventory.hpp"

/**
 * @brief Menambahkan senjata baru ke inventaris.
 * @param id ID unik senjata.
 * @param name Nama senjata.
 * @param type Tipe senjata (Sword/Bow/Staff).
 * @param damage Nilai damage senjata.
 * @param rarity Tingkat kelangkaan (1-5).
 */
void WeaponInventory::add(const string &id, const string &name, const string &type, int damage, int rarity){
    Weapon newWeapon(id, name, type, damage, rarity);
    weapons.push_back(newWeapon);
};

/**
 * @brief Menghapus senjata berdasarkan id.
 * @param id ID senjata yang akan dihapus.
 * @return true jika senjata ditemukan dan dihapus, false jika tidak
 * ditemukan.
 */
bool WeaponInventory::remove(const string &id){
    auto it = remove_if(weapons.begin(), weapons.end(), [&](const Weapon& w){
        return w.id == id;
    });

    if (it == weapons.end()) {
        return false;
    }

    weapons.erase(it, weapons.end());
    return true;
};

/**
 * @brief Mencari senjata berdasarkan id.
 * @param id ID senjata yang dicari.
 */
const Weapon *WeaponInventory::find(const string &id) const{
    auto it = find_if(weapons.begin(), weapons.end(), [&](const Weapon& w){
        return w.id == id;
    });

    if(it != weapons.end()) return &(*it);
    return nullptr;
};

/**
 * @brief Memperbarui data senjata yang sudah ada berdasarkan id.
 * @param id ID senjata target.
 * @param name Nama baru.
 * @param type Tipe baru.
 * @param damage Damage baru.
 * @param rarity Rarity baru.
 */
void WeaponInventory::update(const string &id, const string &name, const string &type, int damage, int rarity){
    transform(weapons.begin(), weapons.end(), weapons.begin(), [&](Weapon w){
    if(w.id == id){
        w.name = name;
        w.type = type;
        w.damage = damage;
        w.rarity= rarity;
    }
    return w;
    });
};

/**
 * @brief Mengurutkan senjata.
 * @details Urutan: rarity menurun, jika sama damage menurun, jika masih sama id menaik (leksikografis).
 */
void WeaponInventory::sort(){
    std::sort(weapons.begin(), weapons.end(), [](Weapon w1, Weapon w2){
    if(w1.rarity != w2.rarity){
    return w1.rarity > w2.rarity;
    }

    if(w1.damage != w2.damage){
        return w1.damage > w2.damage;
    }
    
    return w1.id < w2.id;
    });
};  

/**
 * @brief Menghitung total damage semua senjata bertipe tertentu.
 * @param type Tipe senjata yang dihitung.
 * @return Total damage.
 */
long long WeaponInventory::totalDamage(const string &type) const{
    return accumulate(weapons.begin(), weapons.end(), 0LL,
        [&](long long sum, const Weapon& w){
            if(w.type == type){
                return sum + w.damage;
            }
            return sum;
        }
    );
};

/**
 * @brief Menghitung jumlah senjata dengan rarity >= minRarity.
 * @param minRarity Batas minimum rarity.
 * @return Jumlah senjata yang memenuhi syarat.
 */
int WeaponInventory::countByRarity(int minRarity) const{
    return count_if(weapons.begin(), weapons.end(), [&](Weapon w){
        return w.rarity >= minRarity;
    });
};

/**
 * @brief Menampilkan semua senjata bertipe tertentu menggunakan iterator.
 * @param type Tipe senjata yang ditampilkan.
 * @details Cetak "EMPTY" jika tidak ada senjata bertipe tersebut.
 */
void WeaponInventory::printByType(const string &type) const{
    bool found = false;
    for(auto w : weapons){
        if(w.type == type){
        found = true;
        cout << w.id << "|" << w.name << "|" << w.type << "|" << w.damage << "|" << w.rarity << endl;
        }
    }

    if (!found) cout << "EMPTY\n";
};

/**
 * @brief Menampilkan seluruh senjata sesuai urutan saat ini di container.
 * @details Cetak "EMPTY" jika container kosong.
 */
void WeaponInventory::print() const{
    for(auto w : weapons){
        cout << w.id << "|" << w.name << "|" << w.type << "|" << w.damage << "|" << w.rarity << endl ;
    }

    if(weapons.empty()) cout << "EMPTY\n";
};

/**
 * @brief Menambahkan bonus damage ke semua senjata bertipe tertentu.
 * @param type Tipe senjata yang di-upgrade.
 * @param bonusDamage Nilai tambahan damage.
 * @return Jumlah senjata yang ter-upgrade.
 */
int WeaponInventory::upgradeAll(const string &type, int bonusDamage){
    int count = 0;

    for_each(weapons.begin(), weapons.end(), [&](Weapon& w){
        if(w.type == type){
            w.damage = w.damage + bonusDamage;
            count++;
        }
    });

    return count;
};