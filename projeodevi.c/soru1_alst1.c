/*  Murat Kadir Yılmaz - 252104012
    Dönem ödevi 1.Soru 1.Alıstırma
    -------------------------------------------
    Program, 12 ayin ciro degerlerini 1K - 10K araliginda rastgele uretir.
    Bu degerleri yatay bir yildiz (*) grafiği olarak terminalde gosterir.
 */

// Kütüphanler:
#include <stdio.h> // Ekrana yazı yazdırmak veya veri almak için kullanılır.
#include <stdlib.h> // Rastgele sayı üretme fonksiyonlarını içerir.
#include <time.h> // time() fonksiyonu sayesinde her çalıştırmada farklı rastgele değerler üretilir.

int main() { // Ana fonksiyon.

    srand(time(NULL)); // Rastegele sayı üretmek için zaman bazlı fonksiyon.
    
    int dizi[12]; // 12 ayın ciro degerlerini tutacak dizi.
    
    
    for(int i = 0; i < 12; i++){ // Rastgele ciro değerlerini oluşturur.
        dizi[i] = rand() %10 + 1; // Rastgele değer üret (1 ile 10 arasında).
    }

    printf("### Ciro Grafigi (Yatay Gorunum) ###\n\n");
    printf("12 Aylik ciro hesaplaniyor...\n\n");
    printf("12 Aylik ciro (1K - 10K):\n");
    for(int i = 0; i < 12; i++){ // Ciro değerlerini yazdır.
        printf("%2dK ",dizi[i]); 
    }
    printf("\n\n");

    for(int i = 0; i < 12; i++){ // Yatay grafik oluşturma.
        printf("%02d.:",i+1); // Ay numarasını iki haneli yazdır.
    
    for(int j = 0; j < dizi[i]; j++){ // Ciro değerleri kadar yıldız çiz
        printf("  *");
    }
    printf(" (%dK)\n",dizi[i]); // Satırın sonunda ayın ciro miktarını parantez içinde göster.
}
    
    return 0; // Programı başarıyla sonlandır.
}
