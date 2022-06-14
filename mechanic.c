#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./display.c"
int roll_dice(int dice_amount){
    srand(time(0));
    int random_dice = rand();
    if(random_dice % dice_amount == 0) return dice_amount;
    else return random_dice % dice_amount;
}
void delay(){
    int mili_seconds = 1000;
    clock_t start_time = clock();
    while (clock() < start_time + mili_seconds);
}
void win_condition(int player_now){
    printf("Player %d has won the game!\n",player_now+1);
}
void ladderboard(int player[], int banyak_pemain,int surrender[]){
    int sort, ladderboard[banyak_pemain-1], cekwin = 0,tempwin = 0;
    for(int x = 0; x < banyak_pemain; x++) ladderboard[x] = x+1;
    for(int x = 0; x< banyak_pemain; x++){
        if(player[x] != -1) cekwin++;
    }
    if(cekwin == 1){
        for(int x = 0; x<banyak_pemain; x++){
            if(player[x] != -1){
                tempwin = player[x];
                player[x] = 99;
            }
        }
    }
    for(int x = 0; x< banyak_pemain; x++){
        if(player[x] == -1) player[x] = surrender[x];
    }
    for(int x = 0; x < banyak_pemain; x++){
        for(int y = x+1; y < banyak_pemain; y++){
            if(player[x] < player[y]){
                sort = player[x];
                player[x] = player[y];
                player[y] = sort;
                sort = ladderboard[x];
                ladderboard[x] = ladderboard[y];
                ladderboard[y] = sort;
            }
        }
    }
    if (cekwin == 1) player[0] = tempwin;
    printf("Current Ladderboard :\n");
    for(int x = 0; x < banyak_pemain; x++) printf("Rank %d : Player %d - %d points\n",x+1,ladderboard[x],player[x]+1);
    printf("\n\n");
}
int start(int  langkah_maksimal,int pemain){
    int  temp_loop = 0,data_angka[100],temp_ulartangga;
    int uler[100]={0,0};
    int tangga[100]={0,0};
    time_t t;
    for(int x = 0 ;x < 100; x++) data_angka[x] = x;
    srand((unsigned) time(&t));
    for(int x = 0; x < 5; x++){
        temp_loop = rand() % 98 + 1;
        temp_ulartangga = rand() % 98+1;
        if(data_angka[temp_loop] == temp_loop && data_angka[temp_ulartangga] == temp_ulartangga){
            data_angka[temp_loop] = temp_ulartangga;
        }else x--;
    }
    for(int x = 99; x >= 0; x--){
        if(data_angka[x]<x){
            uler[x]=data_angka[x];
        }else if (data_angka[x]>x){
            tangga[x]=data_angka[x];
        }
    }
    int player[pemain],surrender_status[pemain];
    //inisiasi lokasi
    for(int x = 0; x < pemain; x++) player[x] = surrender_status[x] = 0;
    system("cls");
    display(player,tangga,uler);
    //turn in play
    while(1){
        int cek_surrender = 0;
        for(int x = 0; x < pemain; x++){
            if(player[x] == -1){
                cek_surrender++;
                if(cek_surrender == (pemain - 1)){
                    system("cls");
                    printf("All players has surrendered, game stopped!\n");
                    for(int y = 0; y < pemain; y++){
                        if (player[y] != -1){
                            surrender_status[y] = player[y];
                            player[y] = -1;
                            break;
                        }
                    }
                    ladderboard(player,pemain,surrender_status);
                    return 0;
                }
            }else{
                printf("Player %d turn!", x+1);
                printf("\nMenu\n1. Roll Dice\n2. Surrender\nYour input : ");
                int turn, roll, temp;
                scanf("%d",&turn);
                switch(turn){
                    case 1:
                    roll = roll_dice(langkah_maksimal);
                    player[x] = player[x] + roll;
                    if(player[x] == 99){
                        system("cls");
                        display(player,tangga,uler);
                        win_condition(x);
                        ladderboard(player,pemain,surrender_status);
                        return 0;
                    }
                    else if (player[x] >= 100){
                        temp = player[x] - 99;
                        player[x] = 99 - temp;
                    }
                    player[x]=data_angka[player[x]];
                    system("cls");
                    display(player,tangga,uler);
                    printf("Your roll is %d!\n",roll);
                    printf("Player %d location now : %d\n\n",x+1,player[x]+1);
                    break;
                    case 2:
                    printf("Player %d has surrendered!\n",x+1);
                    surrender_status[x] = player[x];
                    player[x] = -1;
                    cek_surrender++;
                    if(cek_surrender == (pemain - 1)){
                        x = -1;
                        system("cls");
                        display(player,tangga,uler);
                        printf("All players has surrendered, game stopped!\n");
                        ladderboard(player,pemain,surrender_status);
                        return 0;
                    }
                    break;
                    default :
                    printf("Your input is not valid! Try again!\n");
                    x--;
                }
            }
        }
    }
}