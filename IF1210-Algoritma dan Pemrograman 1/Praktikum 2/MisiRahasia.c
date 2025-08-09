#include <stdio.h>
#include <string.h>

/**
 * Fungsi untuk mengecek apakah tahun kabisat
 * @param int year
 * @return 1 jika tahun kabisat, 0 jika bukan
 */
int isLeapYear(int year) {
    if (((year % 100 != 0) && (year % 4 == 0)) || (year % 400 == 0)){
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * Fungsi untuk mendapatkan jumlah hari dalam bulan tertentu
 * @param int month, year
 * @param int year
 * @return total hari dalam bulan tertentu
 */
int getDaysInMonth(int month, int year) {
    if (month == 2){
        if (isLeapYear(year) == 1){
            return 29;
        }
        else{
            return 28;
        }
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        return 31;
    }
    else{
        return 30;
    }
}


/**
 * Fungsi untuk mengecek apakah suatu tanggal valid
 * @param int day
 * @param int month
 * @param int year
 * @return 1 jika valid, 0 untuk sebaliknya
 */
int isValidDate(int day, int month, int year) {
    if ((year >= 1) && (1 <= month && month <= 12) && (1 <= day && day <= getDaysInMonth(month, year))){
        return 1;
    }
    else {
        return 0;
    }
}


/**
 * Fungsi untuk mendapatkan hari dalam seminggu menggunakan Zeller’s Congruence
 * @param int day
 * @param int month
 * @param int year
 * @return string berupa hari apa pada tanggal tersebut
 */
const char* getDayOfWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int K = year % 100;
    int J = year / 100;
    int h = (day + (13 * (month + 1)) / 5 + K + (K / 4) + (J / 4) - (2 * J)) % 7;
    
    const char* days[] = {"Sabtu", "Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat"};
    return days[h];
}

/**
 * Fungsi untuk mendapatkan zodiak berdasarkan tanggal
 * @param int day
 * @param int month
 * @return string berupa zodiak dari tanggal tersebut
 */
const char* getZodiac(int day, int month) {
    const char* zodiacSigns[] = {
        "Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini",
        "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn"
    };
    int zodiacStartDays[] = {20, 19, 21, 20, 21, 21, 23, 23, 23, 23, 22, 22, 20};

    if (day < zodiacStartDays[month - 1]) return zodiacSigns[month - 1];
    return zodiacSigns[month];
}

/**
 * Fungsi untuk menghitung jumlah hari sejak 01-01-0001
 * @param int day
 * @param int month
 * @param int year
 * @return total hari sejak 01-01-0001 sampai tanggal yang diberikan
 */
long long daysFromBeginning(int day, int month, int year) {
    int total = 0;
    for (int i = 1 ; i < year ; i++){
        if (isLeapYear(i) == 1){
            total += 366;
        }
        else{
            total += 365;
        }
    }
    for (int i = 1 ; i < month ; i++){
        total += (getDaysInMonth(i, year));
    }
    total += day;
    return total;
}

/**
 * Fungsi untuk menghitung selisih hari antara dua tanggal
 * @param int d1
 * @param int m1
 * @param int y1
 * @param int d2
 * @param int m2
 * @param int y2
 * @return total selisih hari dari tanggal ke 1 menuju tanggal ke 2
 */
long long dateDifference(int d1, int m1, int y1, int d2, int m2, int y2) {
    return (daysFromBeginning(d2, m2, y2) - daysFromBeginning(d1, m1, y1));
}

/**
 * Fungsi untuk menghitung hari pasaran Jawa
 * @param int day
 * @param int month
 * @param int year
 * @return string hari pasaran jawa berdasarkan tanggal yang diberikan
 */
const char* getPasaran(int day, int month, int year) {
    const char* pasaran[] = {"Legi", "Pahing", "Pon", "Wage", "Kliwon"};
    return (pasaran[(daysFromBeginning(day, month, year)) % 5]);
}

/**
 * Gunakan strcmp(string1, string2) untuk mengecek apakah kedua string sama
 * Contoh:
 * strcmp("sabtu", "sabtu") --> 0
 * strcmp("senin", "sabtu") --> 1
 */
int main() {
    char Simpan[100];
    int d1,m1,y1,d2,m2,y2;
    scanf("%s", Simpan);
    while (strcmp(Simpan, "SELESAI") != 0){
        if (strcmp(Simpan, "VALIDASI") == 0){
            scanf("%d %d %d", &d1 , &m1, &y1);
            if (isValidDate(d1, m1, y1) == 1){
                printf("YA\n");
            }
            else{
                printf("TIDAK\n");
            }
        }
        else if (strcmp(Simpan, "HARI") == 0){
            scanf("%d %d %d", &d1 , &m1, &y1);
            printf("%s\n", getDayOfWeek(d1, m1, y1));
        }
        else if (strcmp(Simpan, "ZODIAK") == 0){
            scanf("%d %d", &d1 , &m1);
            printf("%s\n", getZodiac(d1, m1));
        }
        else if (strcmp(Simpan, "SELISIH") == 0){
            scanf("%d %d %d", &d1 , &m1, &y1);
            scanf("%d %d %d", &d2, &m2, &y2);
            printf("%lld\n", dateDifference(d1,m1,y1,d2,m2,y2));
        }
        else if (strcmp(Simpan, "PASARAN") == 0){
            scanf("%d %d %d", &d1 , &m1, &y1);
            printf("%s\n", getPasaran(d1,m1,y1));
        }
        scanf("%s", Simpan);
    }
    return 0;
}