// #include <stdint.h>  <-- Bunu sil veya yorum satırı yap

// Türleri kendimiz tanımlıyoruz
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

uint8_t inb(uint16_t port) {
    uint8_t result;
    asm volatile("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}
char scancode_to_ascii[128] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' '
};

// ... kodun kalanı (volatile uint16_t* vga_buffer...)
// VGA Metin Modu Belleği
volatile uint16_t* vga_buffer = (uint16_t*)0xB8000;

// İmlecin nerede olduğunu tutan küresel değişken
int vga_index = 0;

// Ekranı temizleme fonksiyonu
void clear_screen() {
    for (int i = 0; i < 80 * 25; i++) {
        vga_buffer[i] = (uint16_t)(' ' | (0x0F << 8));
    }
    vga_index = 0;
}



// Yeni satıra geçme fonksiyonu
void print_newline() {
    // Bir satır 80 karakterdir.
    // Bulunduğumuz konumu 80'e tamamlayıp alt satırın başına atıyoruz.
    vga_index = vga_index + (80 - (vga_index % 80));
}

// Ekrana YAZI basma fonksiyonu
void print_string(const char* str) {
    int i = 0;
    while(str[i] != '\0') {
        // Eğer özel karakterse (yeni satır \n) işlem yap
        if(str[i] == '\n') {
            print_newline();
        } else {
            vga_buffer[vga_index] = (uint16_t)str[i] | (uint16_t)(0x0F << 8);
            vga_index++;
        }
        i++;
    }
}

// Ekrana SAYI basma fonksiyonu (Integer to String)
void print_int(int num) {
    char str[16];
    int i = 0;

    // Sayı 0 ise direkt bas
    if (num == 0) {
        print_string("0");
        return;
    }

    // Sayıyı ters çevirerek karakter dizisine at (Örn: 123 -> "321")
    while (num > 0) {
        str[i] = (num % 10) + '0'; // Rakamı ASCII karaktere çevir
        num = num / 10;
        i++;
    }

    // Diziyi tersyüz edip ekrana bas (Örn: "321" -> "123")
    i--;
    while (i >= 0) {
        char temp_str[2];
        temp_str[0] = str[i];
        temp_str[1] = '\0';
        print_string(temp_str);
        i--;
    }
}
void girdi(){
}


extern "C" void kernel_main() {
    clear_screen(); // Önce ekranı temizle

    print_string("OS Baslatildi...\n");
    print_string("Hesap makinesi modu (Manuel Giris)\n");
    print_string("----------------------------------\n");

    // Şimdilik cin olmadığı için sayıları elle veriyoruz
    int x = 25;
    int y = 14;

    print_string("Sayi 1: ");
    print_int(x);
    print_string("\n");

    print_string("Sayi 2: ");
    print_int(y);
    print_string("\n");

    print_string("Toplam Sonucu: ");

    // Toplama işlemi ve sonucu basma
    print_int(x + y);

    // Sonsuz döngü
    while(1);
}