/*  Murat Kadir Yılmaz - 252104012
    Dönem Ödevi 2.Soru 1.Alıstırma
    -------------------------------------------
    Bu program özyinelemeli (recursive) fonksiyon kullanarak
    n tane üçgen sayısını ekrana yazdırır.
    Örnek: N=5 için üçgen sayılar = 1 3 6 10 15
*/

// Kütüphaneler:
#include <stdio.h> // Ekrana yazı yazdırmak veya veri almak için kullanılır.

// Üçgen sayıyı hesaplayan özyinelemeli fonksiyon.
int ucgenSayi(int n){
    if(n == 1) // 1. üçgen sayı her zaman 1'dir.
        return 1; // Fonksiyonun durma noktası.(artık kendini çağırmayı bırakır)
    else
        return n + ucgenSayi(n - 1); // kendini çağırarak toplama işlemini yapıyor.
}

int main() { // Ana Fonksiyon.

    int ntane; // Kullanıcının girecegi ucgen sayı değerini tutar.

    printf("Kac tane ucgen sayi yazdirmak istiyorsunuz? "); // Kullanıcıdan bir tam sayı istiyoruz
    scanf("%d", &ntane); // Kullanıcıdan kaç tane üçgen sayı istendiğini alıyoruz.

    printf("\n%d tane ucgen sayi:\n", ntane); // Ucgen sayı adedi.

    // 1'den N'e kadar olan üçgen sayıları yazdır.
    for(int i =1; i <= ntane; i++){
        printf("%d ", ucgenSayi(i)); // Her adımda fonksiyonu çağırıp sonucu yazdırıyoruz.
    }

    printf("\n"); // Görüntü düzgün olsun diye satır sonu.
    
    return 0; // Programı başarıyla sonlandır.
}