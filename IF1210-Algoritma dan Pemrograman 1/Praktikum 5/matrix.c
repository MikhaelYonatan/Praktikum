#include "matrix.h"
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Konstruktor */
void CreateMatrix(int rows, int cols, Matrix *M){
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            M->data[i][j] = 0.0;
        }
    }
    M->cols = cols;
    M->rows = rows;
}
/* I.S. rows dan cols terdefinisi dan valid (1 <= rows,cols <= MAX) */
/* F.S. Terbentuk matrix M dengan ukuran rows x cols */
/* Semua elemen diinisialisasi dengan 0.0 */

/* Selector */
int GetRows(Matrix M){
    return M.rows;
}
/* Mengembalikan jumlah baris matrix M */

int GetCols(Matrix M){
    return M.cols;
}
/* Mengembalikan jumlah kolom matrix M */

float *GetElement(Matrix *M, int row, int col){
    if (row >= 0 && col >= 0 && row < M->rows && col < M->cols){
        return &M->data[row][col];
    }
    else {
        return NULL;
    }
}
/* Mengembalikan pointer ke elemen matrix M pada baris row dan kolom col */
/* Mengembalikan NULL jika row atau col tidak valid untuk matrix M */

/* Mutator */
bool SetElement(Matrix *M, int row, int col, float value){
    if (row >= 0 && col >= 0 && row < M->rows && col < M->cols){
        (M->data[row][col]) = value;
        return true;
    }
    else{
        return false;
    }
}
/* I.S. M terdefinisi */
/* F.S. Jika row dan col valid, elemen M pada baris row dan kolom col bernilai value, mengembalikan true */
/*      Jika row atau col tidak valid, mengembalikan false */

/* Operasi Baca/Tulis */
void ReadMatrix(Matrix *M){
    int rows, cols;
    // meminta input ukuran matrix hingga valid
    do{
    scanf("%d %d", &rows, &cols);
    } while (rows <= 0 || rows > MAX_ROWS || cols <= 0 || cols > MAX_COLS);
    CreateMatrix(rows, cols, M); //inisialisasi matrix
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            scanf("%f", &M->data[i][j]);
        }
    }

}
/* I.S. M belum terdefinisi */
/* F.S. M terdefinisi dan diisi dengan nilai-nilai yang dibaca dari input */
/*      Meminta input ukuran matrix (rows, cols) hingga valid
        Valid: 0 < rows < MAX_ROWS and 0 < cols < MAX_COLS */
/*      Meminta input elemen matrix M sebanyak rows * cols 
        Format input: Setiap elemen dipisahkan oleh spasi
        Contoh input: 
        2 3
        1.0 2.0 3.0
        4.0 5.0 6.0
        Contoh input tidak valid:
        -1 -1
        2 3
        1.0 2.0 3.0
        4.0 5.0 6.0
*/

void PrintMatrix(Matrix M){
    for (int i = 0 ; i < M.rows ; i++){
        for (int j = 0 ; j < M.cols ; j++){
            printf("%.2f", M.data[i][j]);
            if (j < M.cols-1){
                printf(" ");
            }
        }
        printf(" \n");
    }
}
/* I.S. M terdefinisi */
/* F.S. Seluruh elemen M tertulis ke layar dalam format matrix */
/* Baris dipisahkan oleh newline, kolom dipisahkan oleh spasi */
/* Format output: Setiap elemen diformat "%.2f" */

/* Operator Relasional */
bool IsSquare(Matrix M){
    return (M.rows == M.cols);
}
/* Mengembalikan true jika M adalah matrix persegi (rows = cols) */

bool IsSymmetric(Matrix M){
    if (IsSquare(M)){
        for (int i = 0 ; i < M.rows ; i++){
            for (int j = 0 ; j < M.cols ; j++){
                if (M.data[i][j] != M.data[j][i]){
                    return false;
                }
            }
        }
        return true;
    }
    else return false;
}
/* Mengembalikan true jika M adalah matrix simetrik terhadap diagonal */
/* Matrix simetrik adalah matrix yang memiliki elemen tercermin oleh diagonal*/
/* Prekondisi: M adalah matrix persegi */

bool IsDiagonallyDominant(Matrix M){
    for (int i = 0 ; i < M.rows ; i++){
        float sum = 0;
        for (int j = 0 ; j < M.cols ; j++){
            if (j != i){
                sum += fabsf(M.data[i][j]);
            }
        }
        if ((fabs(M.data[i][i])) <= sum){
            return false;
        }
    }
    return true;
}
/* Mengembalikan true jika M adalah matrix diagonal dominant */
/* |a[i][i]| > sum(|a[i][j]|) untuk j != i pada setiap baris i */
/* Hint: Gunakan fabs untuk melakukan abs terhadap float */

/* Operator Aritmatika */
Matrix *MultiplyMatrix(Matrix M1, Matrix M2){
    if (M1.cols != M2.rows) return NULL;

    Matrix* M = (Matrix *)malloc(sizeof(Matrix));
    CreateMatrix(M1.rows, M2.cols, M);
    for (int i = 0 ; i < M1.rows ; i++){
        for (int j = 0 ; j < M2.cols ; j++){
            float value = 0;
            for (int k = 0 ; k < M1.cols ; k++){
                value += M1.data[i][k] * M2.data[k][j];
            }
            M->data[i][j] = value;
        }
    }
    
    return M;
}
/* Menghasilkan hasil perkalian matrix M1 dan M2 */
/* Mengembalikan NULL jika jumlah kolom M1 != jumlah baris M2 */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */

Matrix *AddMatrix(Matrix M1, Matrix M2){
    if (M1.cols != M2.cols || M1.rows != M2.rows){
        return NULL;
    }
    else{
        Matrix* M = (Matrix *)malloc(sizeof(Matrix));
        CreateMatrix(M1.rows, M2.cols, M);
        for(int i = 0; i < M1.rows; i++){
            for(int j = 0; j < M1.cols; j++){
                M->data[i][j] = M1.data[i][j] + M2.data[i][j];
            }
        }
    
        return M;
    }
}
/* Menghasilkan hasil penjumlahan matrix M1 dan M2 */
/* Mengembalikan NULL jika ukuran matrix M1 dan M2 berbeda */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */

Matrix *SubtractMatrix(Matrix M1, Matrix M2){
    if (M1.cols != M2.cols || M1.rows != M2.rows){
        return NULL;
    }
    else{
        Matrix* M = (Matrix *)malloc(sizeof(Matrix));
        CreateMatrix(M1.rows, M2.cols, M);
        for(int i = 0; i < M1.rows; i++){
            for(int j = 0; j < M1.cols; j++){
                M->data[i][j] = M1.data[i][j] - M2.data[i][j];
            }
        }
    
        return M;
    }
}
/* Menghasilkan hasil pengurangan matrix M1 dan M2 (M1 - M2) */
/* Mengembalikan NULL jika ukuran matrix M1 dan M2 berbeda */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */

Matrix MultiplyScalar(Matrix M, float scalar){
    Matrix M_New;
    CreateMatrix(M.rows, M.cols, &M_New);
    for(int i = 0; i < M.rows; i++){
        for(int j = 0; j < M.cols; j++){
            M_New.data[i][j] = M.data[i][j] * scalar;
        }
    }
    return M_New;
}
/* Menghasilkan hasil perkalian matrix M dengan skalar scalar */
/* Prekondisi: M terdefinisi dan skalar terdefinisi */
/* Hint: Buat matrix baru untuk menyimpan hasil */

Matrix GetTranspose(Matrix M){
    Matrix M_New;
    CreateMatrix(M.cols, M.rows, &M_New);
    for(int i = 0; i < M.cols; i++){
        for(int j = 0; j < M.rows; j++){
            M_New.data[i][j] = M.data[j][i];
        }
    }
    return M_New;
}
/* Menghasilkan matrix transpose dari M */
/* Hint: Buat matrix baru untuk menyimpan hasil */