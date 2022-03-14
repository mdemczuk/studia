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
    switch(stopnie) {
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
