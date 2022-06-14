#include <stdio.h>
#include <stdlib.h>

void angka(char blocks[],int no){
    int count=0;
    int tmp=no;
    char tempchar[4];
    do
    {
        tmp=tmp/10;
        count++;
    } while (tmp!=0);
    sprintf(tempchar,"%d",no);
    for(int i=0;i<count;i++){
        blocks[3+i]=tempchar[i];
    }
}
void ularAtauTangga(char block[],int ular[] ,int tangga[],int cou){
    int tmp;
    if(ular[cou]!=0){
        tmp=ular[cou];
        angka(block,tmp+1);
    }else if(tangga[cou]!=0){
        tmp=tangga[cou];
        angka(block,tmp+1);
    }else{
        block[4]='X';
    }

}
void upperblock(int cou,int player[]){/*P1 N P2*/
    char blocks[9];
    for(int i=0;i<9;i++){
        blocks[i]=' ';
    }
    if (player[0]==cou){
        blocks[0]='P';
        blocks[1]='1';
    }else {
        blocks[1]='X';
    }
    angka(blocks,cou+1);
    if (player[1]==cou){
        blocks[6]='P';
        blocks[7]='2';
    }else {
        blocks[7]='X';
    }
    for(int i=0;i<9;i++){
        printf("%c",blocks[i]);
    }
}
void middleblock(int cou,int tangga[],int uler[]){/*X T/U X*/
    char blocks[9];
    for(int i=0;i<9;i++){
        blocks[i]=' ';
    }
    blocks[9]='\n';
    if(uler[cou]!=0){
        blocks[4]='U';
    }else if(tangga[cou]!=0){
        blocks[4]='T';
    }
    blocks[1]='X';
    blocks[7]='X';
    for(int i=0;i<9;i++){
        printf("%c",blocks[i]);
    }
}
void lowerblock(int cou,int player[],int tangga[],int uler[]){/*P3 TT/TU P4*/
    char blocks[9];
        for(int i=0;i<9;i++){
            blocks[i]=' ';
        }
    if (player[2]==cou){
        blocks[0]='P';
        blocks[1]='3';
    }else {
        blocks[1]='X';
    }
    ularAtauTangga(blocks,uler,tangga,cou);
    if (player[3]==cou){
        blocks[6]='P';
        blocks[7]='4';
    }else {
        blocks[7]='X';
    }
    for(int i=0;i<9;i++){
        printf("%c",blocks[i]);
    }
};

void kekanan(int player[],int tangga[],int uler[],int cou){
    for(int i=cou;i!=cou-10;i--){
        upperblock(i-1,player);
        printf(" | ");
    }
    printf("\n");
    for(int i=cou;i!=cou-10;i--){
        middleblock(i-1,tangga,uler);
        printf(" | ");
    }
    printf("\n");
    for(int i=cou;i!=cou-10;i--){
        lowerblock(i-1,player,tangga,uler);
        printf(" | ");
    }
    printf("\n");
    for(int i=0;i<119;i++){
        printf("-");
    };
    printf("\n");
};

void kekiri(int player[],int tangga[],int uler[],int cou){
    for(int i=cou-10;i!=cou;i++){
        upperblock(i,player);
        printf(" | ");
    }
    printf("\n");
    for(int i=cou-10;i!=cou;i++){
        middleblock(i,tangga,uler);
        printf(" | ");
    }printf("\n");

    for(int i=cou-10;i!=cou;i++){
        lowerblock(i,player,tangga,uler);
        printf(" | ");
    }
    printf("\n");
    for(int i=0;i<119;i++){
        printf("-");
    };
    printf("\n");
};

void display(int player[],int tangga[],int uler[]){
    for(int i=100;i!=0;i=i-10){
        if(i%20==0){
            kekanan(player,tangga,uler,i);
        }else{
            kekiri(player,tangga,uler,i);
        }
    };
};