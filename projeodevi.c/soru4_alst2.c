/*  
    Murat Kadir Yılmaz - 252104012
    Dönem Ödevi 4.Soru 2.Alıstırma
    -------------------------------------------
    Bu program, daha önce Sezar şifreleme yöntemiyle
    şifrelenmiş bir metni çözer.
    
    Örnek Çıktı:
    ------------------------------
    Cözmek istediginiz mesajı giriniz: Gizli operasyon basladi
    Anahtar degeri giriniz: 13
    Cozulmus mesaj: Tvmyv bcrenflba onfynqv
*/

// Kütüphaneler:
#include <stdio.h> // Ekrana yazı yazdırmak veya veri almak için kullanılır.

int main(){ // Ana fonksiyon.

    char cumle[100]; // Kullanıcının gireceği şifreli metni tutacak karakter dizisi.
    int anahtar; // Şifre çözme işlemi için kullanılacak anahtar değeri.

    printf("Cozmek istediginiz mesaji giriniz: "); // Kullanıcıdan şifreli metni istiyoruz.
    fgets(cumle, 100, stdin); // Metni boşluklarıyla birlikte alıyoruz (fgets sayesinde).

    printf("Anahtar degeri giriniz: "); // Kullanıcıdan çözme anahtarını istiyoruz.
    scanf("%d", &anahtar); // Anahtar değerini alıyoruz.

    printf("Cozulmus mesaj: "); // çözülen metin burada yazılacak.

    // Metindeki her karakteri tek tek kontrol edip çözülür.
    for (int i = 0; cumle[i] != '\0'; i++){ // '\0' karakter dizisinin bittiğini gösterir.
        int c = cumle[i]; // O anki karakteri alıyoruz.

        // Eğer küçük harfse (a-z arası)
        if (c >= 'a' && c <= 'z'){
            c = ( (c - 'a' - anahtar + 26) % 26 ) + 'a'; 
            // Şifre çözmede + yerine - kullanılır (geri kaydırma yapılır).
            // +26 eklemek, negatif sonucu önlemek içindir.
        }
        // Eğer büyük harfse (A-Z arası)
        else if (c >= 'A' && c <= 'Z'){
            c = ( (c - 'A' - anahtar + 26) % 26 ) + 'A';
            // Aynı işlem büyük harfler için yapılır.
        }

        printf("%c", c); // Çözülen karakteri ekrana yazdır.
    }

    return 0; // Program başarıyla sonlandırıldı.
}

