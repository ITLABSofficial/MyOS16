# MyOS16
Os16 Bit dor starter
📖 Kullanım Rehberi / Usage GuideMyOS V3 _ITLABS, komut satırı arayüzü (CLI) üzerinden çalışır. Aşağıda sistemin modları ve komutları için detaylı kullanım kılavuzu bulunmaktadır.
MyOS V3 _ITLABS operates via a Command Line Interface (CLI). Below is the detailed user manual for system modes and commands.🇹🇷 Türkçe (Turkish)🏁
Genel Komutlar (Her Modda Geçerli)Bu komutları sistemin herhangi bir yerinde kullanabilirsiniz.
KomutAçıklamaexBulunduğunuz moddan çıkar ve Ana Menüye döner.temizleEkranı temizler.
kapanSistemi ve emülatörü (QEMU) güvenli bir şekilde kapatır.
1️⃣ Mod 1: Bilimsel Fonksiyon ve İntegralKendi matematiksel fonksiyonlarınızı tanımlayın, kaydedin ve integralini (alanını) hesaplayın.
Fonksiyonları Listele:Bashliste
(Sisteme kayıtlı tüm fonksiyonları ve formülleri gösterir.)Yeni Fonksiyon Kaydet:
Bash
kaydet <isim> <formul>
Örnek: kaydet f1 x*x+5 veya kaydet dalga sin(x)Fonksiyon Değeri Hesapla:Bashdeger <isim> <x_sayisi>
Örnek: deger f1 5 (f1 fonksiyonunda x yerine 5 koyar ve çözer)İntegral (Alan) Hesapla:Bashintegral <isim> <baslangic> <bitis>
Örnek: integral kare 0 10 (0 ile 10 arasındaki alanı hesaplar)
2️⃣ Mod 2: Nükleer Enerji SimülasyonuElementlerin kütle ve çarpışma hızına göre ortaya çıkan enerji, TNT eşdeğeri ve yıkım çapını hesaplar.
Giriş Formatı
:Bash
<element_id> <kutle_gram> <hiz_m/s>
Element Kodları: 1: Uranyum, 2: Plütonyum, 3: Toryum, 4: Hidrojen (Füzyon)Örnek:Bash1 500 300
(500 gram Uranyum'un 300 m/s hızla çarpışmasını simüle eder.)
3️⃣ Mod 3: Hızlı Hesap MakinesiMatematiksel işlemleri doğrudan yazarak anında sonuç alabilirsiniz.
Örnekler:
Bash
Calc> 10+5*2
Calc> 100/4
Calc> sin(1.57)
Calc> 5^2
🇬🇧 English (English)🏁 General Commands (Global)These commands work in every mode and menu.CommandDescriptionexExits the current mode and returns to the Main Menu.
temizle Clears the screen (CLS).
kapan Safely shuts down the system (ACPI/QEMU Shutdown).
1️⃣ Mode 1: Scientific Functions & Integral Define your own functions, save them to memory, and calculate definite integrals.List 
Functions:
Bash
liste
(Displays all registered functions and their formulas.)Save New Function:Bashkaydet <name> <formula>
Example: kaydet f1 x*x+5 or kaydet wave sin(x)Calculate Value:Bashdeger <name> <x_value>
Example: deger f1 5 (Solves f1 where x = 5)Calculate Integral (Area):Bashintegral <name> <start> <end>
Example: integral kare 0 10 (Calculates area between 0 and 10)
2️⃣ Mode 2: Nuclear Energy Simulation Simulates energy output, TNT equivalent, and blast radius based on element mass and collision velocity.
Input Format:
Bash
<element_id> <mass_grams> <velocity_m/s>
Element IDs: 1: Uranium, 2: Plutonium, 3: Thorium, 4: Hydrogen (Fusion)Example:Bash1 500 300
(Simulates 500g of Uranium colliding at 300 m/s.)
3️⃣ Mode 3: Quick Calculator Perform arithmetic and trigonometric operations directly in the command line.
Examples:
Bash
Calc> 10+5*2
Calc> 100/4
Calc> sin(1.57)
Calc> 5^2
