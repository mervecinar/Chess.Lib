// header dosyas�
#ifndef chessLib
#define chessLib

struct poz {
    short yatay; // say� olan s�ra
    char dusey; // harf olan s�ra
};
// tan�mlamalar
void hareketYazdir(char tas, struct poz ilkPozisyon);

struct poz *hareketSah(struct poz ilkPoz);
struct poz *hareketVezir(struct poz ilkPoz);
struct poz *hareketFil(struct poz ilkPoz);
struct poz *hareketAt(struct poz ilkPoz);
struct poz *hareketKale(struct poz ilkPoz);
struct poz *hareketPiyon(struct poz ilkPoz);
int tasIndex(char tas);
char harf(int pozisyon);
int harfPoz(char dusey);

#endif


