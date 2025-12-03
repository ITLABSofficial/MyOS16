; boot.s
; Multiboot Header ve Kernel Giris Noktasi

; Sabitleri Tanýmla (NASM Syntax: equ kullanilir)
MBALIGN  equ  1 << 0            ; Modülleri sayfa sýnýrlarýna hizala
MEMINFO  equ  1 << 1            ; Bellek haritasýný saðla
FLAGS    equ  MBALIGN | MEMINFO ; Bayraklarý birleþtir
MAGIC    equ  0x1BADB002        ; Bootloader'ýn bizi tanýmasý için sihirli sayý
CHECKSUM equ -(MAGIC + FLAGS)   ; Kontrol toplamý

section .multiboot
align 4
    dd MAGIC
    dd FLAGS
    dd CHECKSUM

section .bss
align 16
stack_bottom:
resb 16384 ; 16 KB Stack (Yýðýn) alaný
stack_top:

section .text
global _start:function (_start.end - _start)
_start:
    ; Stack pointer'ý ayarla (C++ çalýþmasý için þart)
    mov esp, stack_top

    ; kernel.cpp içindeki ana fonksiyonu çaðýr
    extern kernel_main
    call kernel_main

    ; Eðer kernel dönerse (dönmemeli), sonsuz döngüye gir
    cli
.hang:
    hlt
    jmp .hang
.end: