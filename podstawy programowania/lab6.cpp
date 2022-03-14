#include <stdio.h>
#include <stdlib.h>

   /* zad 1

    main() {
    int a;
    int *ptr;

    ptr = &a;

    printf("Podaj wartosc: ");
    scanf("%d", a);
    printf("Wartosc pokazywana przez wskaznik: %d", *ptr);

    }

    */

    /* zad 2
    main(){

	int x = 11;
	int y = 20;
    int z[10] = {0};

	// deklaracja zmiennej wskaznikowej dla typu int:
    int *ip;

    // przypisuję wskaźnikowi ip adres pierwszego elementu tablicy z:
  	ip = z;

    int indeks = 0;

 	for(int i=x; i<=y; i++){

 		*ip = i;

 		ip++;

 		printf("Indeks tablicy: %d\t Wartosc: %d\n", indeks, i);

 		indeks++;

    }
    }


    */


    // zad3

	/*
    main(){

    int jakas_tablica[10];
    int *wsk;
    wsk = jakas_tablica;



    for(int i = 0; i<10; i++) {
        if(i==7) {
            *(wsk+i) = 77;
        }

        printf("%d\n", *(wsk+i));

    }
    }
*/


    // zad4


/*  main() {

  int *tab, *pom;
    tab = (int*)malloc(sizeof(int)*10);
    pom = tab;

    printf("Podaj elementy tablicy\n");

    for(int i = 0; i < 10; i++)
    {
        scanf("%d", tab);
        tab++;
    }

    tab = pom;

    printf("\nElementy tablicy: \n");

    for(int k = 0; k < 10; k++){

        printf("%d\n", *tab);
        tab++;
    }

    free(tab);

    }
*/

    // zad5

/*

void sum(int *firstTab, int *secondTab, int *result);

void multi(int *firstTab, int *secondTab, int *result);

void subtr(int *maxEl, int *minEl, int *result);


int main(){

    printf("Z ilu elemenow maja skladac sie obie tablice?\n");

    int sizeTab = 0;

    scanf("%d", &sizeTab);

    int *tab1, *pom1, *tab2, *pom2;
    tab1 = (int*)malloc(sizeof(int)*sizeTab);
    pom1 = tab1;

    tab2 = (int*)malloc(sizeof(int)*sizeTab);
    pom2 = tab2;

    printf("\nWpisz elementy do pierwszej tablicy: \n");

    for(int i=0; i < sizeTab; i++) {
        scanf("%d", tab1);
        tab1++;
    }

    printf("\nWpisz elementy do drugiej tablicy: \n");

    for(int j=0; j < sizeTab; j++) {
        scanf("%d", tab2);
        tab2++;
    }

    tab1 = pom1;
    tab2 = pom2;

    int result1 = 0;

    printf("\nDodawanie: \n");

    for(int k = 0; k < sizeTab; k++){
        sum(tab1, tab2, &result1);
        printf("Dodawanie elementow o indeksie %d z obu tablic: %d + %d = %d\n", k, *tab1, *tab2, result1);
        tab1++;
        tab2++;

    }

    tab1 = pom1;
    tab2 = pom2;

    int result2 = 0;

    printf("\nMnozenie: \n");

    for(int l = 0; l < sizeTab; l++){
        multi(tab1, tab2, &result2);
        printf("Mnozenie elementow o indeksie %d z obu tablic: %d * %d = %d\n", l, *tab1, *tab2, result2);
        tab1++;
        tab2++;
    }

    tab1 = pom1;
    tab2 = pom2;

    int min1 = *tab1;
    int min2 = *tab2;
    int maks1 = *tab1;
    int maks2 = *tab2;
    tab1++;
    tab2++;

    int *pom1_1, *pom2_2;

    pom1_1 = tab1;
    pom2_2 = tab2;

    for(int h = 1; h < sizeTab; h++){
        if(min1>=(*tab1)){
            min1=*tab1;
            tab1++;
        }
    }

    tab1 = pom1_1;

    for(int g = 1; g < sizeTab; g++){
        if(maks1<=(*tab1)){
            maks1=*tab1;
            tab1++;
        }
    }

    for(int f = 1; f < sizeTab; f++)
    {
        if(min2>=(*tab2)){
            min2=*tab2;
            tab2++;
        }
    }

    tab2 = pom2_2;

    for(int d = 1; d < sizeTab; d++){
        if(maks2<=(*tab2)){
            maks2=*tab2;
            tab2++;
        }
    }

    int result3 = 0;
    int result4 = 0;

    subtr(&maks1, &min1, &result3);
    printf("\nOdejmowanie najmniejszego elementu tablicy od najwiekszego dla tablicy pierwszej:\n%d - %d = %d\n", maks1, min1, result3);

    subtr(&maks2, &min2, &result4);
    printf("\nOdejmowanie najmniejszego elementu tablicy od najwiekszego dla tablicy drugiej:\n%d - %d = %d\n", maks2, min2, result4);


    free(tab1);
    free(tab2);

    }




void sum(int *firstTab, int *secondTab, int *result)
{
    *result = (*firstTab + *secondTab);
}


void multi(int *firstTab, int *secondTab, int *result)
{
    *result = (*firstTab * *secondTab);
}

void subtr(int *maxEl, int *minEl, int *result)
{
    *result = (*maxEl - *minEl);
}


*/

//zad6

    // Napisz program, który prosi użytkownika o podanie n zbiorów składających się z k liczb typu double, a
    // następnie:
    // Zapisuje te dane w tablicy o wymiarach n x k, OK
    // Oblicza średnią dla każdego zbioru z osobna.  OK
    // Oblicza średnią dla wszystkich wartości,      OK
    // Znajduje największą spośród wartości.
    // Wyświetla wyniki.                             OK


int main()
{
    int n = 0;
    int k = 0;

    printf("Ile zbiorow ma znajdowac sie w tablicy?\n");
    scanf("%d", &n);
    printf("Ile liczb ma znajdowac sie w kazdym zbiorze?\n");
    scanf("%d", &k);

    // tab[n][k]

    double **tab, **pom;
    tab = (double**)malloc(n*sizeof(double*));

    for(int i=0; i<n; i++){
        tab[i]=(double*)malloc(k*sizeof(double));

    }

    pom = tab;


    int l = 1, j, h;

    for(j = 0; j<n; j++){
        printf("Wpisz liczby do zbioru %d:\n", l++);
        for(h = 0; h<k; h++){
            scanf("%lf", &tab[j][h]);

        }
    }

    l = 1;

    // wyswietlanie zawartosci tablicy

    printf("Zawartosc tablicy %d x %d:\nZbior:\n", n, k);

    for(j = 0; j<n; j++){
        printf("%d\t\t", l++);
        for(h = 0; h<=k; h++){
            if(h==k)
                printf("\n\n");

            else
                printf("%lf\t\t", tab[j][h]);

        }
    }


    // obliczanie sredniej dla kazdego zbioru z osobna

    l = 1;

    for(j = 0; j<n; j++)
    {
        printf("Obliczanie sredniej dla zbioru %d\n", l);

        double sumaZbioru, sredniaZbioru;

        for(h = 0; h<k; h++)
        {
            sumaZbioru += tab[j][h];
        }

        sredniaZbioru = sumaZbioru/k;

        printf("Srednia zbioru %d: %lf\n\n", l++, sredniaZbioru);

        sredniaZbioru = 0;
        sumaZbioru = 0;

    }

    // obliczanie sredniej dla wszystkich zbiorow

    printf("Obliczanie sredniej dla wszystkich zbiorow\n\n");

    double sumaZbiorow, sredniaZbiorow;

    for(j = 0; j<n; j++)
    {
        for(h = 0; h<k; h++)
        {
            sumaZbiorow += tab[j][h];
        }
    }

    sredniaZbiorow = sumaZbiorow/(n*k);

    printf("Srednia zbiorow wynosi: %lf\n\n", sredniaZbiorow);


    double *maks;


    for(j = 0; j<n; j++)
    {
        for(h = 0; h<k; h++)
        {
            if(*maks < tab[j][h]) {
                maks = &tab[j][h];
            }
        }
    }

    printf("Najwieksza wartosc to: %lf", *maks);

    free(tab);

    return 0;

}
