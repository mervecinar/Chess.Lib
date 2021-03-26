#include "chessLib.h"
#include <stdio.h>
#include <stdlib.h>


int main(void){
// konum ve yazdýrma
    struct poz k;
    k.dusey = 'E';
    k.yatay = 4;
    printf("     PIYON  \n");
    hareketYazdir('P', k);
    puts("------------------\n");
    puts(" \n");
    printf("     KALE  \n");
    hareketYazdir('K', k);
    puts("------------------\n");
    puts(" \n");
    printf("      AT  \n");  
	hareketYazdir('A', k);
	puts("------------------\n");
    puts(" \n") ;
	 printf("    FIL  \n"); 
    hareketYazdir('F', k);
    puts("------------------\n");
    puts(" \n");
    printf("     SAH  \n");
    hareketYazdir('S', k);
    puts("------------------\n");
    puts(" \n");
    printf("     VEZIR  \n");
    hareketYazdir('V', k);
    puts("------------------");


}

