/*  Murat Kadir Yılmaz - 252104012
    Dönem Ödevi 2.Soru 2.Alıstırma
    -------------------------------------------
    Bu program, kullanıcıdan alınan bir n değeriyle
    n(n+1)/2 formülüne göre sayıları kullanarak
    eşkenar üçgen şeklinde bir sayı deseni çizer.
*/

// Kütüphaneler:
#include <stdio.h> // Ekrana yazı yazdırmak veya veri almak için kullanılır.

int main() { // Ana fonksiyon.

    int ntane; // Kullanıcının gireceği üçgenin satır sayısını tutar.
    int sayi = 1;  // 1'den başlayarak artacak.

    printf("Bir tam sayi giriniz: "); // Kullanıcıdan bir tam sayi istiyoruz.
    scanf("%d", &ntane); // Kullanıcıdan kac tane ucgen sayı istediğini alıyoruz.

    // Her satırda satir numarası kadar sayı olacak.
    for (int satir = 1; satir <= ntane; satir++) {

        // Boşlukları yaz (üçgeni ortalamak için).
        for (int bosluk = 0; bosluk < ntane - satir; bosluk++) {
            printf(" "); // Her döngüde bir boşluk basar.
        }

        // Her satırda artan sayıları yaz.
        for (int sutun = 1; sutun <= satir; sutun++) {
            printf("%2d ", sayi); // Sayıyı hizalı bir şekilde yazdır.('2' koymamızın sebebi).            
            sayi++;  // sayıyı 1 artır.
        }

        printf("\n"); // Görüntü düzgün olsun diye satır sonu.
    }

    return 0; // Programı başarıyla sonlandır.
}
