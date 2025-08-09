#include "Boolean.h"
#include "matrix.h"

Matrix dilate(Matrix v, int scale){
    Matrix tempV;
    createMatrix(ROW_EFF(v) * scale, COL_EFF(v) * scale, &tempV);
    for (int i = 0 ; i < ROW_EFF(v) ; i++){
        for (int j = 0 ; j < COL_EFF(v) ; j++){
            ELMT(tempV, i * scale, j * scale) = ELMT(v, i, j);
        }
    }
    return tempV;
}
/* Setiap titik (x, y) menjadi (x*scale, y*scale) */

Matrix translate(Matrix v, int dx, int dy){
    Matrix tempV;
    createMatrix(ROW_EFF(v) + dx, COL_EFF(v) + dy, &tempV);
    for (int i = 0 ; i < ROW_EFF(v) ; i++){
        for (int j = 0 ; j < COL_EFF(v) ; j++){
            ELMT(tempV, i + dx, j + dy) = ELMT(v, i, j);
        }
    }
    return tempV;
}
/* Setiap titik (x, y) menjadi (x+dx, y+dy) */

Matrix reflect(Matrix v, char axis){
    Matrix tempV;
    createMatrix(ROW_EFF(v) , COL_EFF(v) , &tempV);
    if (axis == 'x')
    {
        for (int i = 0 ; i < ROW_EFF(v) ; i++){
            for (int j = 0 ; j < COL_EFF(v) ; j++){
                ELMT(tempV, i, -j % COL_EFF(v)) = ELMT(v, i, j);
            }
        }
    } else if (axis == 'y')
    {
       for (int i = 0 ; i < ROW_EFF(v) ; i++){
            for (int j = 0 ; j < COL_EFF(v) ; j++){
                ELMT(tempV, -i % ROW_EFF(v), j) = ELMT(v, i, j);
            }
        }
        
    }
    return tempV;
}

/* 'x' → y = -y, 'y' → x = -x */

Matrix rotate(Matrix v, int degree){
    int cos0 = 1, cos90 = 0, cos180 = -1, cos270 = 0;
    int sin0 = 0, sin90 = 1, sin180 = 0, sin270 = -1;
    Matrix tempV;
    createMatrix(ROW_EFF(v) , COL_EFF(v) , &tempV);
    if (degree == 0){
        for (int i = 0 ; i < ROW_EFF(v) ; i++){
            for (int j = 0 ; j < COL_EFF(v) ; j++){
                int newx = (i * cos0 + j * sin0) % ROW_EFF(v);
                int newy = (-i * cos0 + j * sin0) % COL_EFF(v);
                ELMT(tempV, newx, newy) = ELMT(v, i, j);
            }
        }
    }
    else if (degree == 90){
        for (int i = 0 ; i < ROW_EFF(v) ; i++){
            for (int j = 0 ; j < COL_EFF(v) ; j++){
                int newx = (i * cos90 + j * sin90) % ROW_EFF(v);
                int newy = (-i * cos90 + j * sin90) % COL_EFF(v);
                ELMT(tempV, newx, newy) = ELMT(v, i, j);
            }
        }
    }
    else if (degree == 180){
        for (int i = 0 ; i < ROW_EFF(v) ; i++){
            for (int j = 0 ; j < COL_EFF(v) ; j++){
                int newx = (i * cos180 + j * sin180) % ROW_EFF(v);
                int newy = (-i * cos180 + j * sin180) % COL_EFF(v);
                ELMT(tempV, newx, newy) = ELMT(v, i, j);
            }
        }
    }
    else if (degree == 270){
        for (int i = 0 ; i < ROW_EFF(v) ; i++){
            for (int j = 0 ; j < COL_EFF(v) ; j++){
                int newx = (i * cos270 + j * sin270) % ROW_EFF(v);
                int newy = (-i * cos270 + j * sin270) % COL_EFF(v);
                ELMT(tempV, newx, newy) = ELMT(v, i, j);
            }
        }
    }
    return tempV;
}
/* Memutar setiap titik (x, y) sebesar degree derajat searah jarum jam dari (0,0) */
/* Gunakan rumus rotasi:
   x' = x * cosθ + y * sinθ
   y' = -x * sinθ + y * cosθ
   degree hanya 0, 90, 180, 270 (bisa pakai konstanta tanpa trigonometri float) */
/* cos0 = 1, sin0 = 0*/
/* cos90 = 0, sin90 = 1*/
/* cos180 = -1, sin180 = 0*/
/* cos270 = 0, sin270 = -1*/
/* DEGREE SUDAH PASTI 4 JENIS, HARDCODE SAJA, TIDAK PERLU PAKE <math.h> */