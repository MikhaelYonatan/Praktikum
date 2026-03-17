#include "TodoItem.hpp"
using namespace std;

TodoItem::TodoItem(const string& name)
         :Activity(name) {
    isDone = false;            
}

int TodoItem::complete(){
    if (!isDone) {
        isDone = true;
        return 10;
    }
    else {
        return 0;
    }
}

string TodoItem::getStatus() const {
    string content;
    if (isDone) {
        content = "[TODO] " + name + " - Selesai";
    }
    else {
        content = "[TODO] " + name + " - Belum";
    }
    return content;
}

TodoItem::~TodoItem() {
    cout << "Menghapus TodoItem " << name << endl;
}