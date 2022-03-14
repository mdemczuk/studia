#include <stdio.h>

int main()

{
    int n;
    printf("podaj ilosc liczb: ");
    scanf ("%d", &n);

    int tab[n];

    for (int i = 0; i < n; i++)
    {
        tab[i]=i;
        printf("%d\n", tab[i]);
    }
    printf("\n%d\n", sizeof tab);
}
