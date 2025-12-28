/*  
    Murat Kadir Yılmaz - 252104012
    Dönem Ödevi 4.Soru 1.Alıstırma
    -------------------------------------------
    Bu program, girilen bir metni ve anahtar değerini kullanarak
    Sezar şifreleme yöntemiyle metni şifreler.

    Örnek Çıktı:
    -------------------------------------------
    Sifrelemek istediginiz mesaji giriniz: Gizli operasyon basladi
    Anahtar degeri giriniz: 13
    Sifrelenmis mesaj: Tvmyv bcrenflba onfynqv
*/

// Kütüphaneler:
#include <stdio.h> // Ekrana yazı yazdırmak veya veri almak için kullanılır.
int main(){ // Ana fonksiyon.

    char cumle[100]; // Kullanıcının gireceği mesajı tutacak karakter dizisi.
    int anahtar; // Şifreleme işlemi için kaydırma miktarı (anahtar).

    printf("Sifrelemek istediginiz mesaji giriniz: "); // Kullanıcıdan metin istiyoruz.
    fgets(cumle, 100, stdin); // Mesajı boşluklarıyla birlikte alıyoruz (fgets daha güvenli).
    printf("Anahtar degeri giriniz: "); // Şifreleme anahtarını istiyoruz.
    scanf("%d",&anahtar); // Kullanıcının girdiği anahtar değerini alıyoruz.

    printf("Sifrelenmis mesaj: ");
    // Her karakteri tek tek kontrol edip şifreliyoruz.
    for (int i=0; cumle[i] != '\0'; i++){ // '\0' karakter dizisinin sonudur.
    int c = cumle[i]; // O anki karakteri alıyoruz.

    // Eğer küçük harfse (a-z arası)
    if (c >= 'a' &&  c <= 'z'){
        c = ( (c - 'a' + anahtar) % 26 ) + 'a'; // Harfi anahtar kadar kaydır.
    }
    // Eğer büyük harfse (A-Z arası)
    else if (c >='A' && c <='Z'){
        c = ( (c - 'A' + anahtar) % 26 ) + 'A'; // Büyük harfler için aynı işlem.
    }
    printf("%c",c); // Şifrelenmiş karakteri ekrana yazdır.
}

    return 0; // Program başarıyla sonlandırıldı.

}
