#include "chessLib.h"
#include <stdio.h>
#include <stdlib.h>
int i, j;
int x; // hareket say�s� sayac�
struct poz sonuc;

void hareketYazdir(char tas, struct poz ilkPozisyon) {
    int z; 
	z= tasIndex(tas); //istenilen fonksiyonu �a��rmak i�in istenilen ta� indexi.
    x = 0;

    struct poz * (*satrancFonksiyonlari[6]) (struct poz ilkPoz); // 6 adet ta� i�in onlar�n hareket fonksiyonlar�n� tutan dizi
    satrancFonksiyonlari[0] = hareketPiyon;
    satrancFonksiyonlari[1] = hareketKale;
    satrancFonksiyonlari[2] = hareketAt;
    satrancFonksiyonlari[3] = hareketFil;
    satrancFonksiyonlari[4] = hareketVezir;
    satrancFonksiyonlari[5] = hareketSah;


    struct poz* a = (*satrancFonksiyonlari[z]) (ilkPozisyon);
    int** tahta = (int **) calloc(8, sizeof (int*)); //  8x8 lik tahta i�in yer ay�rma
    for (i = 0; i < 8; i++) {
        tahta[i] = (int *) calloc(sizeof (int), 8);
    }

    // tahtaya ilk de�er atama
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            tahta[i][j] = 0;
        }
    }

    for (i = 0; i < x; i++) {
        tahta[a[i].yatay][harfPoz(a[i].dusey)] = 1; // ta��n gidebilece�i yerlere 1 yazar    
    }

    tahta[ilkPozisyon.yatay - 1][harfPoz(ilkPozisyon.dusey)] = 2; // ta��n bulundu�u noktaya 2 yazar main.c de verdi�im de�ere g�re
    //tahtaya yukar�dakileri yazd�r�r.
    for (i = 7; i >= 0; i--) {
        for (j = 0; j < 8; j++) {
            printf("%d ", tahta[i][j]);
        }
        printf("\n");
    }

}
// ta�a g�re atama yapar

int tasIndex(char t) {

    if (t == 'P') {
        return 0;
    } else if (t == 'K') {
        return 1;
    } else if (t == 'A') {
        return 2;
    } else if (t == 'F') {
        return 3;
    } else if (t == 'V') {
        return 4;
    } else {
        return 5;
    }
}
//konuma g�re

char harf(int h) {

    switch (h) {
        case 0:
            return 'A';
            break;

        case 1:
            return 'B';
            break;

        case 2:
            return 'C';
            break;

        case 3:
            return 'D';
            break;

        case 4:
            return 'E';
            break;

        case 5:
            return 'F';
            break;

        case 6:
            return 'G';
            break;

        case 7:
            return 'H';
            break;
    }
}

// d��eye g�re y�nlendirir.

int harfPoz(char s) {

    switch (s) {
        case 'A':
            return 0;
            break;

        case 'B':
            return 1;
            break;

        case 'C':
            return 2;
            break;

        case 'D':
            return 3;
            break;

        case 'E':
            return 4;
            break;

        case 'F':
            return 5;
            break;

        case 'G':
            return 6;
            break;

        case 'H':
            return 7;
            break;

    }
}
//1-P�YON

struct poz *hareketPiyon(struct poz ilkPoz) {

    struct poz* a = (struct poz*) malloc((sizeof (struct poz))*4); // 4 hareketi var �n sa� �apraz sol �apraz ve iki �n.
    //verilen konumuna g�re a��a��daki ko�ullar devreye giriyor
    int yatay = ilkPoz.yatay - 1;
    int dusey = harfPoz(ilkPoz.dusey);
    //oldu�u  pozisyonda gidebililece�i her yer i�in ko�ul.
    if (yatay + 1 != 8) {
        sonuc.yatay = yatay + 1;
        sonuc.dusey = ilkPoz.dusey;
        a[x] = sonuc;
        x++;
    }

    if (yatay + 1 != 8) {
        sonuc.yatay = yatay + 2;
        sonuc.dusey = ilkPoz.dusey;
        a[x] = sonuc;
        x++;
    }
    if (dusey + 1 != 8 && yatay + 1 != 8) {
        sonuc.yatay = yatay + 1;
        sonuc.dusey = harf(dusey + 1);
        a[x] = sonuc;
        x++;
    }
    if (dusey + 1 != 8 && yatay + 1 != 8) {
        sonuc.yatay = yatay + 1;
        sonuc.dusey = harf(dusey - 1);
        a[x] = sonuc;
        x++;
    }

    return a;
}

struct poz *hareketKale(struct poz ilkPoz) {

    struct poz* a = (struct poz*) malloc((sizeof (struct poz))*49); //7*7 den 49 hamle yapar(8-1(kendi oldu�u kare) yer ay�rma)
    //verilen konumuna g�re a��a��daki ko�ullar devreye giriyor
    int yatay = ilkPoz.yatay - 1;
    int dusey = harfPoz(ilkPoz.dusey);
    // kale nin tek gitmek gibi �art� olmad��� i�in dikey ve d��eyde sona kadar gidebilsin diye d�ng� ile yapt�m b�ylece her kareye 1 yazacak.

    while (yatay + 1 != 8) {
        yatay++;
        sonuc.dusey = ilkPoz.dusey;
        sonuc.yatay = yatay;

        a[x] = sonuc;
        x++;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfPoz(ilkPoz.dusey);

    while (yatay - 1 != -1) {

        yatay--;
        sonuc.yatay = yatay;
        sonuc.dusey = ilkPoz.dusey;
        a[x] = sonuc;
        x++;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfPoz(ilkPoz.dusey);

    while (dusey + 1 != 8) {
        dusey++;
        sonuc.dusey = harf(dusey);
        sonuc.yatay = yatay;

        a[x] = sonuc;
        x++;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfPoz(ilkPoz.dusey);

    while (dusey - 1 != -1) {
        dusey--;
        sonuc.yatay = yatay;
        sonuc.dusey = harf(dusey);
        a[x] = sonuc;
        x++;
    }

    return a;
}
//2-AT

struct poz *hareketAt(struct poz ilkPoz) {

    struct poz* a = (struct poz*) malloc((sizeof (struct poz)*8)); //8 hamle yapar L �eklinde

    // verilen konumuna g�re a��a��daki ko�ullar devreye giriyor
    int yatay = ilkPoz.yatay - 1;
    int dusey = harfPoz(ilkPoz.dusey);
    //her bir hamle ihtimali i�in ko�ul
    if (dusey - 1 != -1 && yatay + 2 != 8) {
        sonuc.yatay = yatay + 2;
        sonuc.dusey = harf(dusey - 1);
        a[x] = sonuc;
        x++;
    }

    if (dusey - 1 != -1 && yatay - 2 != -1) {
        sonuc.dusey = harf(dusey - 1);
        sonuc.yatay = yatay - 2;


        a[x] = sonuc;
        x++;
    }

    if (dusey + 1 != 8 && yatay - 2 != -1) {
        sonuc.dusey = harf(dusey + 1);
        sonuc.yatay = yatay - 2;

        a[x] = sonuc;
        x++;
    }

    if (dusey + 1 != 8 && yatay + 2 != 8) {
        sonuc.yatay = yatay + 2;
        sonuc.dusey = harf(dusey + 1);
        a[x] = sonuc;
        x++;
    }

    if (dusey - 2 != -1 && yatay + 1 != 8) {
        sonuc.yatay = yatay + 1;
        sonuc.dusey = harf(dusey - 2);
        a[x] = sonuc;
        x++;
    }

    if (dusey - 2 != -1 && yatay - 1 != -1) {
        sonuc.yatay = yatay - 1;
        sonuc.dusey = harf(dusey - 2);
        a[x] = sonuc;
        x++;
    }

    if (dusey + 2 != 8 && yatay - 1 != -1) {

        sonuc.dusey = harf(dusey + 2);
        sonuc.yatay = yatay - 1;


        a[x] = sonuc;
        x++;
    }

    if (dusey + 2 != 8 && yatay + 1 != 8) {
        sonuc.yatay = yatay + 1;
        sonuc.dusey = harf(dusey + 2);
        a[x] = sonuc;
        x++;
    }

    return a;
}

//3-�AH

struct poz *hareketSah(struct poz ilkPoz) {

    struct poz* a = (struct poz*) malloc((sizeof (struct poz))*8); //�ah'�n 8 hareketi var sa� sol arka �n ve 4 �apraz. 

    //verilen konumuna g�re a��a��daki ko�ullar devreye giriyor
    int yatay = ilkPoz.yatay - 1;
    int dusey = harfPoz(ilkPoz.dusey);
    //  oldu�u ilk  pozisyonda gidebilece�i her yer i�in bir ko�ul olu�turuyor.
    if (yatay + 1 != 8) {
        sonuc.yatay = yatay + 1;
        sonuc.dusey = ilkPoz.dusey;
        a[x] = sonuc;
        x++;
    }
    if (dusey + 1 != 8) {
        sonuc.yatay = yatay;
        sonuc.dusey = harf(dusey + 1);
        a[x] = sonuc;
        x++;
    }

    if (yatay - 1 != -1) {
        sonuc.yatay = yatay - 1;
        sonuc.dusey = ilkPoz.dusey;
        a[x] = sonuc;
        x++;
    }



    if (dusey - 1 != -1) {
        sonuc.yatay = yatay;
        sonuc.dusey = harf(dusey - 1);
        a[x] = sonuc;
        x++;
    }

    if (dusey - 1 != -1 && yatay + 1 != 8) {
        sonuc.yatay = yatay + 1;
        sonuc.dusey = harf(dusey - 1);
        a[x] = sonuc;
        x++;
    }

    if (dusey - 1 != -1 && yatay - 1 != -1) {

        sonuc.dusey = harf(dusey - 1);
        sonuc.yatay = yatay - 1;

        a[x] = sonuc;
        x++;
    }
    if (dusey + 1 != 8 && yatay + 1 != 8) {
        sonuc.dusey = harf(dusey + 1);
        sonuc.yatay = yatay + 1;

        a[x] = sonuc;
        x++;
    }

    if (dusey + 1 != 8 && yatay - 1 != -1) {
        sonuc.yatay = yatay - 1;
        sonuc.dusey = harf(dusey + 1);
        a[x] = sonuc;
        x++;
    }

    return a;
}
//5-VEZ�R

struct poz *hareketVezir(struct poz ilkPoz) {

    struct poz* a = (struct poz*) malloc((sizeof (struct poz))*49); //vezirin 7x7 49 hareketi var.
    //verilen konumuna g�re a��a��daki ko�ullar devreye giriyor
    int dusey = harfPoz(ilkPoz.dusey);
    int yatay = ilkPoz.yatay - 1;
    //her bir ihtimal i�in d�ng� tek girme gibi zorunlulu�u yok o y�zden gidebileceklerinin hepsine 1 yazs�n diye d�ng� kulland�m

    while (yatay + 1 != 8) {
        yatay++;
        sonuc.yatay = yatay;
        sonuc.dusey = ilkPoz.dusey;
        a[x] = sonuc;
        x++;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfPoz(ilkPoz.dusey);

    while (yatay - 1 != -1) {
        yatay--;
        sonuc.yatay = yatay;
        sonuc.dusey = ilkPoz.dusey;
        a[x] = sonuc;
        x++;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfPoz(ilkPoz.dusey);

    while (dusey + 1 != 8) {
        dusey++;
        sonuc.yatay = yatay;
        sonuc.dusey = harf(dusey);
        a[x] = sonuc;
        x++;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfPoz(ilkPoz.dusey);

    while (dusey - 1 != -1) {
        dusey--;
        sonuc.yatay = yatay;
        sonuc.dusey = harf(dusey);
        a[x] = sonuc;
        x++;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfPoz(ilkPoz.dusey);

    while (dusey - 1 != -1 && yatay + 1 != 8) {
        yatay++;
        dusey--;
        sonuc.yatay = yatay;
        sonuc.dusey = harf(dusey);
        a[x] = sonuc;
        x++;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfPoz(ilkPoz.dusey);

    while (dusey - 1 != -1 && yatay - 1 != -1) {
        yatay--;
        dusey--;
        sonuc.yatay = yatay;
        sonuc.dusey = harf(dusey);
        a[x] = sonuc;
        x++;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfPoz(ilkPoz.dusey);

    while (dusey + 1 != 8 && yatay - 1 != -1) {
        dusey++;
        yatay--;

        sonuc.yatay = yatay;
        sonuc.dusey = harf(dusey);
        a[x] = sonuc;
        x++;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfPoz(ilkPoz.dusey);

    while (dusey + 1 != 8 && yatay + 1 != 8) {
        dusey++;
        yatay++;

        sonuc.yatay = yatay;
        sonuc.dusey = harf(dusey);
        a[x] = sonuc;
        x++;
    }

    return a;
}
//6-F�L

struct poz *hareketFil(struct poz ilkPoz) {

    struct poz* a = (struct poz*) malloc((sizeof (struct poz))*16); //4x4 den 16 hamle yapar
    //verilen konumuna g�re a��a��daki ko�ullar devreye giriyor

    int yatay = ilkPoz.yatay - 1;
    int dusey = harfPoz(ilkPoz.dusey);

    yatay = ilkPoz.yatay - 1;
    dusey = harfPoz(ilkPoz.dusey);
    //her bir ihtimal i�in d�ng� tek girme gibi zorunlulu�u yok o y�zden gidebileceklerinin hepsine 1 yazs�n diye d�ng� kulland�m
    while (dusey - 1 != -1 && yatay + 1 != 8) {
        yatay++;
        dusey--;
        sonuc.yatay = yatay;
        sonuc.dusey = harf(dusey);
        a[x] = sonuc;
        x++;
    }

    while (dusey + 1 != 8 && yatay - 1 != -1) {
        dusey++;
        yatay--;

        sonuc.yatay = yatay;
        sonuc.dusey = harf(dusey);
        a[x] = sonuc;
        x++;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfPoz(ilkPoz.dusey);

    while (dusey - 1 != -1 && yatay - 1 != -1) {
        yatay--;
        dusey--;
        sonuc.yatay = yatay;
        sonuc.dusey = harf(dusey);
        a[x] = sonuc;
        x++;
    }

    yatay = ilkPoz.yatay - 1;
    dusey = harfPoz(ilkPoz.dusey);

    while (dusey + 1 != 8 && yatay + 1 != 8) {

        dusey++;
        yatay++;

        sonuc.yatay = yatay;
        sonuc.dusey = harf(dusey);
        a[x] = sonuc;
        x++;
    }

    return a;
}






