/*
    Murat Kadir Yilmaz - 252104012
    Dönem ödevi 1.Soru 2.Alıstırma
    -------------------------------------------
    Program, 12 ayin ciro degerlerini 1K - 10K araliginda rastgele uretir.
    Bu degerleri dikey bir yildiz (*) grafigi olarak terminalde gosterir.
*/

// Kütüphaneler:
#include <stdio.h> // Ekrana yazı yazdırmak veya veri almak için kullanılır.
#include <stdlib.h> // Rastgele sayı üretme fonksiyonlarını içerir.
#include <time.h>  // time() fonksiyonu için (rastgele sayılar için farklı sonuçlar üretir).

int main() { // Ana fonksiyon.

    srand(time(NULL)); // Rastgele sayı üretmek için zaman bazlı fonksiyon.

    int dizi[12]; // 12 ayın ciro değerlerini saklayacak dizi.
    int max = 0; // En yüksek ciro değerini tutmak için değişken (grafiğin yüksekliğini belirler).
    
    printf("### Ciro Grafigi (Dikey Gorunum) ###\n\n");
    printf("12 Aylik ciro hesaplaniyor...\n\n");
    
    // 1. Aşama: rastegle ciro degerlerini oluştur. 
    for (int i = 0; i < 12; i++){
        dizi[i] = rand() % 10 + 1; // 1 ile 10 arasında.
        if (dizi[i] > max)
            max = dizi[i];
    }

    // Üretilen ciro degerlerini ekrana yazdir.
    printf("12 Aylik ciro (1K - 10K):\n");
    for(int i = 0; i<12; i++){
        printf("%2dK ",dizi[i]); // Her degeri K (bin) birimiyle yaz.
    }
    printf("\n\n");
    
    // 2. Aşama: Dikey grafiği oluştur (yukarıdan aşağıya doğru).
    for (int i = max; i > 0; i--){ // En yüksek değerden 1’e kadar satır satır in.
        for (int j = 0; j < 12; j++){ // Her ay için bir sutun oluştur.
            if (i <= dizi[j])
                printf("  *  "); // Yıldız çiz.
            else
                printf("     "); // Değilse boşluk bırak.
        }
        printf("\n"); // Satır sonu.
    }

    // 3. Aşama: Alt kısama ay numaralarını yazdır. 
    for (int i = 0; i < 12; i++){ // Ay numaralarini yazdir.
        printf("%4d.", i + 1);
    }
    printf("\n");

    return 0; // Programı başarıyla sonlandır.

}
