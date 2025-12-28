/*  Murat Kadir Yılmaz - 252104012
    Dönem Ödevi 5.soru
    -------------------------------------------
    Bu program 5x5 boyutunda bir labirenti temsil eder ve
    başlangıç noktası (0,0) ile çıkış noktası (4,4) arasında
    geçerli bir yol olup olmadığını kontrol eder.
    Yol bulunduğunda labirent üzerinde X ile işaretlenir.
*/

// Kütüphaneler:
#include <stdio.h> // Ekrana yazı yazdırmak veya veri almak için kullanılır.

#define BOYUT 5 // Labirentin boyutu.

/* Labirent matrisi
   '1' —> geçilebilir alan
   '0' —> engel
*/
char labirent[BOYUT][BOYUT] = {
    {'1','1','0','0','1'},
    {'0','1','0','1','1'},
    {'0','1','1','1','0'},
    {'1','0','0','1','1'},
    {'1','1','1','0','1'}
};

// Ziyaret edilen yerleri tutar.(0: ziyaret edilmedi, 1: ziyaret edildi)
int ziyaret[BOYUT][BOYUT] = {0};

/*
    Bu fonksiyon, (x,y) konumundan cikisa yol bulmaya calisir.
    Yol bulursa 1, bulamazsa 0 dondurur.
*/
int yolBul(int x, int y) {

    // Sinir kontrolu.
    if (x < 0 || x >= BOYUT || y < 0 || y >= BOYUT)
        return 0;

    // Engel veya daha once gidilmisse.
    if (labirent[x][y] == '0' || ziyaret[x][y] == 1)
        return 0;

    // Cikis noktasina gelindiyse.
    if (x == 4 && y == 4) {
        labirent[x][y] = 'X';
        return 1;
    }

    // Bu noktayi ziyaret ettik.
    ziyaret[x][y] = 1;
    labirent[x][y] = 'X';

    if (yolBul(x + 1, y)) // Asagi.
        return 1;

    if (yolBul(x - 1, y)) // Yukarı.
        return 1;

    if (yolBul(x, y + 1)) // Saga.
        return 1;

    if (yolBul(x, y - 1)) // Sola.
        return 1;

    // Yol bulunamadi, geri al.
    labirent[x][y] = '1'; // Bu hücreyi tekrar açık yap
    return 0;
}

// Labirenti ekrana yazdirir.
void labirentiYazdir() {
    int i, j;
    for (i = 0; i < BOYUT; i++) {
        for (j = 0; j < BOYUT; j++) {
            printf("%c  ", labirent[i][j]);
        }
        printf("\n"); // Satır sonu.
    }
}

int main() { // Ana fonksiyon.

    if (labirent[0][0] == '0' || labirent[4][4] == '0') { // Labirent gecerlilik kontrolu.
        printf("Baslangic veya cikis kapali!\n");
        return 0;
    }

    if (yolBul(0, 0)) { // Yol arama.
        printf("Cikisa giden yol bulundu:\n");
        labirentiYazdir(); // Labirenti ekrana yazdir.
    } else {
        printf("Cikisa giden yol bulunamadi!\n");
    }

    return 0; // Programı başarıyla sonlandırıldı.
}