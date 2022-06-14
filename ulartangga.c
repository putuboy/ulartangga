#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mechanic.c"

int main(){
    int stop=1,pillihan,jum=2,dadu=6;
    while(stop!=0){
        printf("Ular tangga\nMenu permainan:\n1.start\n2.jumlah player (default = 2)\n3.dadu (default = 6)\n4.Keluar\n");
        scanf("%d",&pillihan);
    switch (pillihan)
    {
    case 1:
        start(dadu,jum);
        break;
    case 2:
    do {
        printf("\nMasukkan jumlah pemain valid(1 - 4) : ");
        scanf("%d",&jum);
    }while(jum > 4 || jum == 0);
    break;
    case 3:
    do {
        printf("Masukkan langkah maksimal(1 - 10) : ");
        scanf("%d",&dadu);
    }while(dadu > 10 || dadu == 0);
    break;
    case 4:
        return 0;
    default:
        break;
    }
    }
}