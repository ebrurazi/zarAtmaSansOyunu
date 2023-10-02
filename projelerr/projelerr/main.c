#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

/*
 İki zar atılır
 Zarların toplamı hesaplanır İlk atışta 7 veya 11 gelirse oyuncu kazanır
 İlk atışta 2,3 veya 12 gelirse oyuncu kaybeder
 İlk atışta 4,5,6,8,9,10 gelirse bu oyuncunun puanı oluyor Oyuncu 7 atmadan önce kendi puanınını tutturmalıdı
 */

int main(void){
    srand(time(NULL));
    int zar1,zar2;
    int puan1,puan2;
    char isim1[50],isim2[50];
    int sonuc=0;
    
    printf("******************ZAR ATMA OYUNU******************\n\n");
    printf("\t\t\t\tHOŞ GELDİNİZ\n\n");
    
    printf("Birinci ismi giriniz : ");
    scanf("%s",isim1);
    
    printf("İkinci ismi giriniz : ");
    scanf("%s",isim2);
    
    printf("\nBirinci kullanıcı zar atışı yapmakta...\n");
    sleep(2);
    //İki zar atılır 1-6 arasında rastgele değerler atanır.
    zar1=1+rand()%6;
    zar2=1+rand()%6;
    puan1=zar1+zar2;
    printf("%s nin attığı zar sonuçları : %d ve %d",isim1,zar1,zar2);
    
    printf("\nİkinci kullanıcı zar atışı yapmakta...\n");
    sleep(2);
    
    zar1=1+rand()%6;
    zar2=1+rand()%6;
    puan2=zar1+zar2;
    printf("%s nin attığı zar sonuçları : %d ve %d\n",isim2,zar1,zar2);
    //Zarların toplamı hesaplanır İlk atışta 7 veya 11 gelirse 1.oyuncu kazanır
    if(puan1==7 || puan1==11){
        printf("%s kazandı\n",isim1);
        sonuc=1;
        return 0;
    }
    //Zarların toplamı hesaplanır İlk atışta 2,3 veya 11 gelirse 1.oyuncu kaybeder
    else if(puan1==2 || puan1==3 || puan1==12){
        printf("%s kaybetti\n",isim1);
        sonuc=1;
        return 0;
    }
    //Zarların toplamı hesaplanır İlk atışta 7 veya 11 gelirse 2.oyuncu kazanır
    if(puan2==7 || puan2==11){
        printf("%s kazandı\n",isim2);
        sonuc=1;
        return 0;
    }
    //Zarların toplamı hesaplanır İlk atışta 2,3 veya 11 gelirse 2.oyuncu kaybeder
    else if(puan2==2 || puan2==3 || puan2==12){
        printf("%s kaybetti\n",isim2);
        sonuc=1;
        return 0;
    }
    else{
        
        //İlk atışta 4,5,6,8,9,10 gelirse bu oyuncunun puanı oluyor.O puanı zarların toplamı ile tutturması lazım
        //O sayıyı tuttursa oyunu kazanır.İkisi de tuturamazsa kazanan yoktur.
        printf("%s'in puanı : %d\n",isim1,puan1);
        printf("%s'in puanı : %d\n",isim2,puan2);
        
        for (int i=2;i<7;i++) {
            zar1=1+rand()%6;
            zar2=1+rand()%6;
            printf("%s nin %d zar atışı : %d ve %d\n",isim1,i,zar1,zar2);
            
            if(puan1==(zar1+zar2)){
                printf("%s kazandı\n",isim1);
                sonuc=1;
                return 0;
            }
            zar1=1+rand()%6;
            zar2=1+rand()%6;
            printf("%s nin %d zar atışı : %d ve %d\n",isim2,i,zar1,zar2);
            
            if(puan2==(zar1+zar2)){
                printf("%s kazandı\n",isim2);
                sonuc=1;
                return 0;
            }
        }
    }
    if(sonuc != 1)
        printf("Kazanan olmadı!!!\n");
    printf("\n");
    return 0;
}
