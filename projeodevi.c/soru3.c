/*  Murat Kadir Yılmaz - 252104012
    Dönem Ödevi 3.Soru
    -------------------------------------------
    Bu program 3 harfli "isim" kombinasyonları üretir.
    Kurallar:
     - 1. ve 3. harf aynı olacak.
     - Üç harfin ASCII değerleri toplamı asal sayı olacak.
     - Harf dizilimi C-V-C veya V-C-V (Sessiz-Sesli-Sessiz veya Sesli-Sessiz-Sesli) olacak.
*/

// Kütüphaneler:
#include <stdio.h> // Ekrana yazı yazdırmak veya veri almak için kullanılır.

int main() { // Ana fonksiyon.
    char h1, h2, h3; // 3 harfli isim oluşturmak için kullanılacak karakterler.
    int toplam; // ASCII değerlerinin toplamını tutacak değişken.
    int isim = 0; // geçerli isim sayısını saymak için.
    char unlu[] = "aeiou"; // Sesli harfler listesi.
    int h1_unlu, h2_unlu, h3_unlu; // Harflerin sesli olup olmadığını kontrol eden değişkenler

    printf("Gecerli isimler:\n");


    for (h1 = 'a'; h1 <= 'z'; h1++) { // 1. döngü: 1. harf 'a'dan 'z'ye kadar değişir.
        for (h2 = 'a'; h2 <= 'z'; h2++) {
            h3 = h1; // 1. ve 3. harf aynı olacak.

            toplam = (int)h1 + (int)h2 + (int)h3; // ASCII değerlerinin toplamını bul.

            int sayac =0; // Asal sayı kontrolü için sayaç.
            // Asal sayı kontrolü. (toplamın kaç böleni var diye bakıyoruz)
            for (int i = 1; i <= toplam; i++) { // 2. döngü: 2. harf de 'a'dan 'z'ye kadar değişir.
                if (toplam % i == 0) 
                sayac++; // Her bölünebildiğinde sayacı artır.
            }
            if (sayac != 2) continue; // asal değilse atla.

            // Sesli-sessiz durumu kontrol et.
            h1_unlu = h2_unlu = h3_unlu = 0;
            for (int i = 0; i < 5; i++) {
                if (h1 == unlu[i]) h1_unlu = 1; // h1 sesliyse 1 yap.
                if (h2 == unlu[i]) h2_unlu = 1; // h2 sesliyse 1 yap.
                if (h3 == unlu[i]) h3_unlu = 1; // h3 sesliyse 1 yap.
            }

            // C-V-C (sessiz-sesli-sessiz) veya V-C-V (sesli-sessiz-sesli) kontrolü:
            if ( (h1_unlu && !h2_unlu && h3_unlu) || (!h1_unlu && h2_unlu && !h3_unlu) ) {
                printf("%c%c%c  ", h1, h2, h3); // Geçerli ismi ekrana yaz.
                printf("\n");
                isim++; // Geçerli isim sayısını 1 artır.
            }
        }
    }

    printf("\nToplam %d gecerli isim bulundu.\n", isim); // Toplam kaç geçerli isim bulunduğunu yazdır.

    return 0; // Programı başarıyla sonlandır.
}