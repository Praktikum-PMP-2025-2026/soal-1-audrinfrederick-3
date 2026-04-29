/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 3 Structures and Dynamic Array
 *   Hari dan Tanggal    : Rabu, 29 April 2026
 *   Nama (NIM)          : Audrin Naufal Fikri Frederick (13224044)
 *   Nama File           : Arsip Artefak Terkategori.c
 *   Deskripsi           : Membuaat struct data artefak yang berisi N buah Nama, Kategori, Tahun, Nilai.
 *                         Kemudian, data tersebut akan diurutkan berdasarkan alfabet kategori. 
 *                         Jika terdapat kategori yang sama, maka data akan diurutkan berdasarkan tahun secara naik.
 *                         Jika tahun sama, maka data diurutkan berdasarkan nilai secara turun.  
 *                         lalu ditampilkan sesuai dengan kategori yang dipilih oleh pengguna.
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct Arsip{
    char *nama;
    char *kategori;
    int tahun;
    int nilai;
} Arsip;

Arsip *arr = NULL;
int size = 0;
 int main() {
  
// Fungsi memasukan data dengan format (n data nama kategori tahun nilai)
   // penulisan data (n, nama 1, kategori 1, tahun 1, nilai 1, nama 2, kategori 2, tahun 2, nilai 2, ..., nama n, kategori n, tahun n, nilai n)
    int n;
    scanf("%d", &n);
    
    arr = malloc(n * sizeof(Arsip));
    
    for (int i = 0; i < n; i++) {
        char bufferNama[100], bufferKategori[100];
        scanf("%s %s %d %d", bufferNama, bufferKategori, &arr[i].tahun, &arr[i].nilai);
        
        arr[i].nama = malloc(strlen(bufferNama) + 1);
        strcpy(arr[i].nama, bufferNama);
        
        arr[i].kategori = malloc(strlen(bufferKategori) + 1);
        strcpy(arr[i].kategori, bufferKategori);
    }

// Fungsi mengurutkan data berdasarkan alfabet kategori, tahun secara naik, dan nilai secara turun
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].kategori, arr[j + 1].kategori) > 0 ||
                (strcmp(arr[j].kategori, arr[j + 1].kategori) == 0 && arr[j].tahun > arr[j + 1].tahun) ||
                (strcmp(arr[j].kategori, arr[j + 1].kategori) == 0 && arr[j].tahun == arr[j + 1].tahun && arr[j].nilai < arr[j + 1].nilai)|| 
                (strcmp(arr[j].kategori, arr[j + 1].kategori) == 0 && arr[j].tahun == arr[j + 1].tahun && arr[j].nilai == arr[j + 1].nilai && strcmp(arr[j].nama, arr[j + 1].nama) > 0)) {
                Arsip temp = arr[j];    
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

        }
    }   
// menampilkan data yang telah diurutkan berdasarkan kategori, tahun, dan nilai
    for (int i = 0; i < n; i++) {
        printf("%s %s %d %d\n", arr[i].nama, arr[i].kategori, arr[i].tahun, arr[i].nilai);
    }
    char kategori[100];
    
    // Free memory
    for (int i = 0; i < n; i++) {
        free(arr[i].nama);
        free(arr[i].kategori);
    }
    free(arr);
    
    return 0;
}
