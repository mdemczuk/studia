#include <stdio.h>
#include <ctime>
#include <cstdlib>

int main()
{
 /*int tab[10] = {8, 3, 4, 6, 11, 5, 2, 0, 9, 10};

   int maksymalny;
   int pozycja = 0;

   maksymalny = tab[0];

   for(int i=0; i<10; i++){

   if(maksymalny<tab[i]){
    maksymalny=tab[i];
    pozycja=i;
    }
   }
   printf("Najwiekszy element tablicy: %d\n Jego pozycja: %d\n", maksymalny, pozycja);


*/

/*srand(time(NULL));



int tab[5] = {0};

for (int i = 0; i<5; i++){
    tab[i] = rand();
    printf("%d\n", tab[i]);
}


*/



/* int tab[10] = {8, 3, 4, 6, 11, 5, 2, 0, 9, 10};

   int maksymalny;
   int pozycja = 0;
   float suma = 0;
   float srednia = 0;

   maksymalny = tab[0];

   for(int i=0; i<10; i++){

   if(maksymalny<tab[i]){
    maksymalny=tab[i];
    pozycja=i;
    }
   }
   printf("Najwiekszy element tablicy: %d\n Jego pozycja: %d\n", maksymalny, pozycja);


   for(int j=0;j<10;j++){
    suma+=tab[j];  // suma = suma + tab[j]
   }
   srednia = suma / 10;

   printf("Srednia: %f\n", srednia);

   int mniejszeOdSr = 0; // i

   for(int k=0;k<10;k++){
    if(tab[k]<srednia){
        mniejszeOdSr++;
    }
   }
printf("Ilosc liczb mniejszych od sredniej: %d", mniejszeOdSr);

*/

float tab[10] = {0};

float pomocnicza = 0;

for(int i=0;i<10;i++){
    scanf("%f", &pomocnicza);
    pomocnicza = tab[i];

}
float srednia = 0;
float suma = 0;

for(int j=0;j<10;j++){
    suma+=tab[j];
}
srednia = suma/10;
printf("Srednia: %f\n", srednia);

float maksymalna = tab[0];
float minimalna = tab[0];

for(int k=0;k<10;k++){
        if(maksymalna<tab[k]){
    maksymalna = tab[k];
}
}
printf("Wartosc maksymalna to: %f\n", maksymalna);

for(int l=0;l<10;l++){
    if(minimalna>tab[l]){
        minimalna = tab[l];
    }
}

printf("Wartosc minimalna to: %f", minimalna);

    return 0;
}
