#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int licznik = 0;
float temp1[20];
char znak1[20];
float temp2[20];
char znak2[20];
float t1, t2;
char z1, z2;

void dodaj_wiersz(float t1, float t2, char z1, char z2)
{
    if(licznik <= 19){
    temp1[licznik]+= t1;
    temp2[licznik]+= t2;
    znak1[licznik]+= z1;
    znak2[licznik]+= z2;
    }
}

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
    printf("\t\t\t\t     PROGRAM DO PRZELICZANIA TEMPERATUR\n\n");
    while(1) {
    float temp;
    char stopnie, C, F, K;
    char opcja;
    printf("\n Wybierz jedna opcje z menu\n  1. Fahr na Kelw\n  2. Fahr na Cels\n  3. Cels na Fahr\n  4. Cels na Kelw\n  5. Kelw na Cels\n");
    printf("  6. Kelw na Fahr\n  7. Sprawdz zawartosc tablicy\n  8. Usun element z tablicy\n  9. Zmodyfikuj element tablicy\n");
    printf("  A. Wypelnij tablice wartosciami losowymi\n  B. Wyswietl dany zakres tablicy\n\n");
    printf("Wybrana opcja: ");
    scanf("%s", &opcja);

        switch(opcja)
            {
        case '1':
            {stopnie='F';
            printf("\nPodaj temperature: ");
            scanf("%f", &temp);
            if(sprawdz(temp, stopnie)==3) {
                float wynik=Fahr_na_Kelw(temp);
                printf("Przeliczona temperatura: %f\n\n", wynik);
                dodaj_wiersz(temp, Fahr_na_Kelw(temp), 'F', 'K');
                licznik++;
            }
            else {
                 printf("\nNie ma takiej temperatury\n");
            }
            }
            break;

        case '2':
            {stopnie='F';
            printf("\nPodaj temperature: ");
            scanf("%f", &temp);
            if(sprawdz(temp, stopnie)==3){
                float wynik=Fahr_na_Cels(temp);
                printf("Przeliczona temperatura: %f\n\n", wynik);
                dodaj_wiersz(temp, Fahr_na_Cels(temp), 'F', 'C');
               licznik++;
            }
            else {
                printf("\nNie ma takiej temperatury\n");
            }
            }
            break;

        case '3':
            {stopnie='C';
            printf("\nPodaj temperature: ");
            scanf("%f", &temp);
            if(sprawdz(temp,stopnie)==3) {
                float wynik=Cels_na_Fahr(temp);
                printf("Przeliczona temperatura: %f\n\n", wynik);
                dodaj_wiersz(temp, Cels_na_Fahr(temp), 'C', 'F');
                licznik++;
            }
            else {
                printf("\nNie ma takiej temperatury\n");
            }
            }
            break;

        case '4':
            {stopnie='C';
            printf("\nPodaj temperature: ");
            scanf("%f", &temp);
            if(sprawdz(temp, stopnie)==3) {
                float wynik=Cels_na_Kelw(temp);
                printf("Przeliczona temperatura: %f\n\n", wynik);
                dodaj_wiersz(temp, Cels_na_Kelw(temp), 'C', 'K');
                licznik++;
            }
            else {
                printf("\nNie ma takiej temperatury\n");
            }
            }
            break;

        case '5':
            {stopnie='K';
            printf("\nPodaj temperature: ");
            scanf("%f", &temp);
            if(sprawdz(temp,stopnie)==3){
                float wynik=Kelw_na_Cels(temp);
                printf("Przeliczona temperatura: %f\n\n", wynik);
                dodaj_wiersz(temp, Kelw_na_Cels(temp), 'K', 'C');
                licznik++;
            }
            else {
                printf("\nNie ma takiej temperatury\n");
            }
            }
            break;

        case '6':
            {stopnie='K';
            printf("\nPodaj temperature: ");
            scanf("%f", &temp);
            if(sprawdz(temp, stopnie)==3){
                float wynik=Kelw_na_Fahr(temp);
                printf("Przeliczona temperatura: %f\n\n", wynik);
                dodaj_wiersz(temp, Kelw_na_Fahr(temp), 'K', 'F');
               licznik++;
            }
            else {
                printf("\nNie ma takiej temperatury\n");
            }
            }
            break;

        case '7':
            {printf("Wyswietlanie tablicy: \n\n");
            printf("Nr indeksu\t Temperatura wprowadzona\t Temperatura przeliczona\n\n");
            for(int i=0; i<licznik; i++){
            printf("%d\t\t %f %c\t\t\t %f %c\n\n", i, temp1[i], znak1[i], temp2[i], znak2[i]);
            }
            }
            break;

        case '8':
            {
            int k;
            printf("Numer indeksu do usuniecia: \n");
            scanf("%d", &k);
            if(k<licznik){
            for(int i=k; i<=licznik; i++){
                temp1[i]=temp1[i+1];
                znak1[i]=znak1[i+1];
                temp2[i]=temp2[i+1];
                znak2[i]=znak2[i+1];
            }

            printf("Nr indeksu\t Temperatura wprowadzona\t Temperatura przeliczona\n\n");

            for(int i=0; i<(licznik -1); i++) {
            printf("%d\t\t %f %c\t\t\t %f %c\n\n", i, temp1[i], znak1[i], temp2[i], znak2[i]);
            }

            printf("Czy usunac kolejny wiersz? Wpisz 1, jesli tak lub 0, jesli nie.\n");
            int odpowiedz = 0;
            scanf("%d", &odpowiedz);

            if(odpowiedz == 1){
                int l;
                printf("Numer indeksu do usuniecia:\n");
                scanf("%d", &l);
                if(l<licznik){
                    for(int i=l; i<=licznik; i++){
                    temp1[i]=temp1[i+1];
                    znak1[i]=znak1[i+1];
                    temp2[i]=temp2[i+1];
                    znak2[i]=znak2[i+1];
                    }

                }
                else
                    printf("Podany numer indeksu nie jest wypelniony zadna wartoscia.\n");
            }
            else if(odpowiedz == 0)
                ;

            }

            else
                printf("Podany numer indeksu nie jest wypelniony zadna wartoscia.");
            }
            break;

        case '9':
            {printf("Numer indeksu do zmodyfikowania: \n");
            int indeks;
            scanf("%d", &indeks);
            if(indeks<=19){
                printf("Podaj nowa wartosc pierwszej temperatury oraz jej stopnie: \n");
                scanf("%f %s", &temp1[indeks], &znak1[indeks]);
                if(znak1[indeks] == 'F' && znak2[indeks] == 'K')
                    temp2[indeks] = Fahr_na_Kelw(temp1[indeks]);

                else if(znak1[indeks] == 'F' && znak2[indeks] == 'C')
                    temp2[indeks] = Fahr_na_Cels(temp1[indeks]);

                else if(znak1[indeks] == 'C' && znak2[indeks] == 'K')
                    temp2[indeks] = Cels_na_Kelw(temp1[indeks]);

                else if(znak1[indeks] == 'C' && znak2[indeks] == 'F')
                    temp2[indeks] = Cels_na_Fahr(temp1[indeks]);

                else if(znak1[indeks] == 'K' && znak2[indeks] == 'C')
                    temp2[indeks] = Kelw_na_Cels(temp1[indeks]);

                else if(znak1[indeks] == 'K' && znak2[indeks] == 'F')
                    temp2[indeks] = Kelw_na_Fahr(temp1[indeks]);
                }
            else
                printf("Podany indeks nie istnieje\n");
            }

            break;

        case 'A':                                                       // zamiast opcji "10" jest "A", bo po dodaniu zabezpieczen z zad 9
                                                                        // i wywolaniu z menu opcji 10, program zamiast opcji 10 wywolywal
                                                                        // opcje 1 i prosil o podanie temperatury
            {printf("Wypelnianie tablicy wartosciami losowymi\n\n");

            srand(time(NULL));

            for(int i=0; i<licznik; i++){
                int randomChar = rand() % 3;
                int randomChar2 = rand() % 2;


                temp1[i] = rand();
                znak1[i] = randomChar;

                switch(randomChar) {
                    case 0:
                        znak1[i] = 'K';                                 // jezeli w randomChar wylosuje sie 0, to temperatura1 bedzie w Kelwinach
                        switch(randomChar2) {                           // losowanie znaku drugiej temperatury tak, aby nie byly to Kelwiny
                            case 0:
                                znak2[i] = 'C';
                                temp2[i] = Kelw_na_Cels(temp1[i]);
                                printf("Wylosowana temperatura zostala przeliczona z Kelwinow na Celsjusze\n\n");
                            break;

                            case 1:
                                znak2[i] = 'F';
                                temp2[i] = Kelw_na_Fahr(temp1[i]);
                                printf("Wylosowana temperatura zostala przeliczona z Kelwinow na Fahrenheity\n\n");
                            break;
                        }
                        break;

                    case 1:
                        znak1[i] = 'C';                                 // jezeli w randomChar wylosuje sie 1, to temperatura1 bedzie w Celsjuszach
                        switch(randomChar2) {                           // losowanie znaku drugiej temperatury tak, aby nie byly to Celsjusze
                            case 0:
                                znak2[i] = 'K';
                                temp2[i] = Cels_na_Kelw(temp1[i]);
                                printf("Wylosowana temperatura zostala przeliczona z Celsjuszy na Kelwiny\n\n");
                            break;

                            case 1:
                                znak2[i] = 'F';
                                temp2[i] = Cels_na_Fahr(temp1[i]);
                                printf("Wylosowana temperatura zostala przeliczona z Celsjuszy na Fahrenheity\n\n");
                            break;
                        }
                        break;

                    case 2:
                        znak1[i] = 'F';                                 // jezeli w randomChar wylosuje sie 2, to temperatura1 bedzie w Fahrenheitach
                        switch(randomChar2) {                           // losowanie znaku drugiej temperatury tak, aby nie byly to Fahrenheity
                            case 0:
                                znak2[i] = 'K';
                                temp2[i] = Fahr_na_Kelw(temp1[i]);
                                printf("Wylosowana temperatura zostala przeliczona z Fahrenheitow na Kelwiny\n\n");
                            break;

                            case 1:
                                znak2[i] = 'C';
                                temp2[i] = Fahr_na_Cels(temp1[i]);
                                printf("Wylosowana temperatura zostala przeliczona z Fahrenheitow na Celsjusze\n\n");
                            break;
                        }
                        break;
                }

            }
            }
            break;



        case 'B':
                {int indeksy = licznik - 1;
                printf("Elementow w tablicy: %d\nNumer ostatniego zapelnionego indeksu w tablicy: %d\n", licznik, indeksy);

                int wartoscMin = 0;
                int wartoscMax = 0;

                printf("Podaj zakres tablicy, ktory chcesz wyswietlic: \nOd numeru indeksu:\n");
                scanf("%d", &wartoscMin);
                printf("Do numeru indeksu:\n");
                scanf("%d", &wartoscMax);

                printf("Nr indeksu\t Temperatura wprowadzona\t Temperatura przeliczona\n\n");

                if(wartoscMin <= licznik && wartoscMax <= licznik){
                    for(int i = wartoscMin; i<=wartoscMax; i++){
                        printf("%d\t\t %f %c\t\t\t %f %c\n\n", i, temp1[i], znak1[i], temp2[i], znak2[i]);
                    }

                }
                else
                    printf("Podane indeksy nie istnieja w tej tablicy.");
                }

                break;



        default:
                 printf("\nPodany znak nie jest obslugiwany.\n\n");

        }

        if(licznik > 19)
            printf("Brak miejsca w pamieci, dane nie beda dalej zapisywane. \n\n");
        }

}
