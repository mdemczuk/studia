#include <stdio.h>

/*zad 1

main()
{
int fahr, celsius; //zmienne ca³kowite int: fahr i celsius
int start, limit, krok; //zmienne ca³kowite int: start, limit, krok
start = 0; //przypisz 0 do start
limit = 200; //przypisz 200 do limit
krok = 20; //przypisz 20 do krok
fahr = start; //przypisz wartoœæ start do zmiennej fahr, czyli fahr = 0
while(fahr <= limit) //wykonuj pêtlê dopóki wartoœæ fahr jest <= od zmiennej limit
 {
     celsius = 5 * (fahr-32) / 9;//oblicz stopnie C i przypisz wynik do celsius
     printf("%d\t%d\n", fahr, celsius);//wypisz zmienne na ekran
     fahr = fahr + krok;//zwiêksz wartoœæ zmiennej fahr o wartoœæ zmiennej krok
     }
     return 0;
}

*/

/*zad 2
main ()
{
    float fahr, celsius; //zmienne ca³kowite int: fahr i celsius
    int start, limit, krok; //zmienne ca³kowite int: start, limit, krok
    start = 0; //przypisz 0 do start
    limit = 200; //przypisz 200 do limit
    krok = 20; //przypisz 20 do krok
    fahr = start; //przypisz wartoœæ start do zmiennej fahr, czyli fahr = 0

    for(fahr = 0.0; fahr <= limit; fahr = fahr + krok)
        { float celsius = (5.0/9.0)*(fahr - 32.0);
        printf("%3.0f %6.1f \n", fahr, celsius);
    }
     return 0;
}

*/

/*zad 3

main ()
{
    float fahr, celsius; //zmienne ca³kowite int: fahr i celsius
    int start, limit, krok; //zmienne ca³kowite int: start, limit, krok
    start = 0; //przypisz 0 do start
    limit = 200; //przypisz 200 do limit
    krok = 20; //przypisz 20 do krok
    fahr = start; //przypisz wartoœæ start do zmiennej fahr, czyli fahr = 0

    for(fahr = 0.0; fahr <= limit; fahr = fahr + krok){
            float celsius = (5.0/9.0)*(fahr - 32.0);
            printf("%f %6.1f \n", fahr, celsius);
        }
     return 0;
}

*/

/*zad 4

main ()
{
    float fahr, celsius; //zmienne ca³kowite int: fahr i celsius
    int start, limit, krok; //zmienne ca³kowite int: start, limit, krok
    start = 0; //przypisz 0 do start
    limit = 200; //przypisz 200 do limit
    krok = 20; //przypisz 20 do krok
    fahr = start; //przypisz wartoœæ start do zmiennej fahr, czyli fahr = 0

    for(fahr = 0.0; fahr <= limit; fahr = fahr + krok)
        {
            float celsius = (5.0/9.0)*(fahr - 32.0);    //wa¿ne jest to, ¿e 5/9=0, bo dziel¹ sie liczby ca³kowite, a przy 5.0=9 lub 5=9.0 wyjd¹ liczby rzeczywiste
            printf("%3.0f %6.1f \n", fahr, celsius);
        }
     return 0;
}

*/

/*zad 5

main()
{

    float fahr, celsius; //zmienne ca³kowite int: fahr i celsius
    int start, limit, krok; //zmienne ca³kowite int: start, limit, krok
    start = 0; //przypisz 0 do start
    printf("podaj limit\n");
    scanf("%d",&limit);
    printf("podaj krok\n");
    scanf("%d",&krok);
    fahr = start; //przypisz wartoœæ start do zmiennej fahr, czyli fahr = 0

         for(fahr = 0.0; fahr <= limit; fahr = fahr + krok){
            float celsius = (5.0/9.0)*(fahr-32.0);
            printf("%f %6.1f \n", fahr, celsius);
        }
     return 0;
}

*/


/*zad 6

main()

{
    printf("Podaj cztery liczby rzeczywiste\n");
    float a, b, c, d;
    scanf("%f %f %f %f", &a, &b, &c, &d);

    printf("\n");

    if(a>10) {
        printf("%f\n", a);
    }
    else {
        printf("Liczba jest za mala\n");
    }
        if(b>10) {
        printf("%f\n", b);
    }
    else {
        printf("Liczba jest za mala\n");
    }
        if(c>10) {
        printf("%f\n", c);
    }
    else {
        printf("Liczba jest za mala\n");
    }
        if(d>10) {
        printf("%f\n", d);
    }
    else {
        printf("Liczba jest za mala\n");
    }
return 0;
}
*/


/*zad 7

main() {
    int r=0;
    for(int a=1; a<100; a= a+2) {
        printf("%d\n", a);
        while(r<50) {
            r++;
        }
    }
    return r;
}

*/


/*zad 8

main()
{
    int x, n;
    printf("Podaj liczbe:\n");
    scanf("%d", &n);
    x = 0;
    while(1) {
        if(x%n==0) {
        printf ("%d\n\n", x);
        }
     x++;
    }
}


*/

/*zad 9

main()
{
    int a, b;
    printf("Podaj dwie liczby:\n");
    scanf("%d\n %d", &a, &b);
    int x;
    printf("\n");
    for(x=a; x<=b; x++) {
        if(x%3==0) {
            printf("%d\n", x);
        }
    }
}

*/


//zad 10

main()
{
    int n;
    float a, suma, srednia;
    suma=0;
    printf("Ile liczb:\n");
    scanf("%d", &n);
    if(n>0) {
        int x=1;
        while(x<=n) {
                printf("Podaj liczbe:\n");
                scanf("%f", &a);
            suma += a;
            x++;
        }
        float srednia=(suma/n);
        printf("Ich srednia arytmetyczna wynosi: ");
        printf("%f", srednia);
    }
else {
    printf("Ilosc liczb musi byc wartoscia dodatnia");
}
}
