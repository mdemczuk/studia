#include <stdio.h>


float Fahr_na_Kelw(float f)                                 //  fahr -> kelwin
{
    if(f>=-459.67){
    return (f+459.67)*5.0/9.0;
    }
    else {
        return 0;
    }
}


float Fahr_na_Cels(float f)                                 // fahr -> celsjusz
{
    if(f>=-469.67) {
    return (f-32.0)*5.0/9.0;
    }
    else {
        return -273.15;
    }
}


float Cels_na_Fahr(float c)                                 // celsjusz -> fahr
{
    if(c>=-273.15) {
    return c*9/5+32;
    }
    else {
        return -459.67;
    }
}


float Cels_na_Kelw(float c)                                 // celsjusz -> kelwin
{
    if(c>=-273.15) {
    return c-273.15;
    }
    else {
        return 0;
    }
}


float Kelw_na_Cels(float k)                                 // kelwin -> celsjusz
{
    if(k>=0) {
    return k-273.15;
    }
    else {
        return -273.15;
    }
}


float Kelw_na_Fahr(float k)
{
    if(k>=0) {
    return k*9/5-459.67;
    }
    else {
        return -459.67;
    }
}

int sprawdz(float temp, char stopnie)
{
    switch(stopnie) {k*9/5-459.67
    case 'C':
        if(temp<-273.15){
            return 2;
        }
        else {
                return 3;
        }
        break;
    case 'F':
        if(temp<-459.67) {
           return 2;
        }
        else {
            return 3;
        }
        break;
    case 'K':
        if(temp<0) {
            return 2;
        }
        else {
            return 3;
        }
    }
}

main()
{
    float temp;
    char stopnie, C, F, K;
    printf("Wybierz jedna opcje z menu\n 1. Fahr na Kelw\n 2. Fahr na Cels\n 3. Cels na Fahr\n 4. Cels na Kelw\n 5. Kelw na Cels\n 6. Kelw na Fahr\n\n");
    int opcja;
    scanf("%d", &opcja);

    while(1){
            switch(opcja)
            {
                case 1:
            stopnie='F';
            printf("Podaj temperature\n");
            scanf("%f", &temp);
            if(sprawdz(temp, stopnie)==3) {
                float wynik=Fahr_na_Kelw(temp);
                printf("%f", wynik);
            }
            else {
                 printf("Nie ma takiej temperatury");
            }
            break;

        case 2:
            stopnie='F';
            printf("Podaj temperature\n");
            scanf("%f", &temp);
            if(sprawdz(temp, stopnie)==3){
                float wynik=Fahr_na_Cels(temp);
                printf("%f", wynik);
            }
            else {
                printf("Nie ma takiej temperatury");
            }
            break;

        case 3:
            stopnie='C';
            printf("Podaj temperature\n");
            scanf("%f", &temp);
            if(sprawdz(temp,stopnie)==3) {
                float wynik=Cels_na_Fahr(temp);
                printf("%f", wynik);
            }
            else {
                printf("Nie ma takiej temperatury");
            }
            break;

        case 4:
            stopnie='C';
            printf("Podaj temperature\n");
            scanf("%f", &temp);
            if(sprawdz(temp, stopnie)==3) {
                float wynik=Cels_na_Kelw(temp);
                printf("%f", wynik);
            }
            else {
                printf("Nie ma takiej temperatury");
            }
            break;

        case 5:
            stopnie='K';
            printf("Podaj temperature\n");
            scanf("%f", &temp);
            if(sprawdz(temp,stopnie)==3){
                float wynik=Kelw_na_Cels(temp);
                printf("%f", wynik);
            }
            else {
                printf("Nie ma takiej temperatury");
            }
            break;

        case 6:
            stopnie='K';
            printf("Podaj temperature\n");
            scanf("%f", &temp);
            if(sprawdz(temp, stopnie)==3){
                float wynik=Kelw_na_Fahr(temp);
                printf("%f", wynik);
            }
            else {
                printf("Nie ma takiej temperatury");
            }
            break;

        case 7:
            return -1;
            }
    }
}



/* int licznik =0;
float temp1[20];
char znak1[20];
float temp2[20];
char znak2[20];

temp1[licznik]=10;
znak1[licznik]='C';
temp2[licznik]= ...;
znak2[licznik]='...';
licznik++;

printf("%f %c\t %f %c\n", temp1[licznik], znak1[licznik], temp2[licznik], znak2[licznik]);


int Dodaj_wiersz(float t1, float t2, char z1, char z2)
{
temp1[licznik]= +1;
temp2[licznik]= +2;
znak1[licznik]= z1;
znak2[licznik]= z2;
}
return 0;
scanf("%f", &fahr);

*/



   /* debbugowanie

    int a=5;
    for(int i=3; i<10; i++) {
        a=i*2;
        printf("%d\t%d\n", i, a);
    }
    */
    /* float fahr;
    scanf("%f", &fahr);
    printf("\n");
    float wynik1=Fahr_na_Kelw(fahr);
    float wynik2=Fahr_na_Cels(fahr);
    printf("F: %f\t K: %f\t C: %f\t", fahr, wynik1, wynik2); */

    /* scanf("%d", opcja);

    while(1){
        if(opcja==1){
            cels_na_kelw....
        }

        else if(opcja==2){
            ....}
        else if(opcja==7){
            return;
            }
            break;
            }
*/




