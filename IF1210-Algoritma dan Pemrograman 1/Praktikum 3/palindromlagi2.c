#include <stdio.h>
#include <string.h>

int canRearrangeToPalindrome(char s[]) {
    int count[26] = {0};
    int length = strlen(s);
    
    // Menghitung frekuensi tiap karakter
    for (int i = 0; i < length; i++) {
        count[s[i] - 'a']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0) { // Jika frekuensi ganjil
            odd++;
        }
    }
    // Tentukan apakah bisa membentuk palindrom
    if (length % 2 == 0) {
        // Untuk string panjang genap, semua frekuensi harus genap
        return (odd == 0);
    } else {
        // Untuk string panjang ganjil, hanya boleh 1 frekuensi ganjil
        return (odd == 1);
    }
}

int main() {
    char s[1001];
    scanf("%s", s);
    
    if (canRearrangeToPalindrome(s)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}