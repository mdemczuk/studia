#include <stdio.h>

//zad5

int main(void){
    int x, y, z;
    printf("Podaj trzy liczby naturalne\n");
    scanf("%d\n", &x);
    scanf("%d\n", &y);
    scanf("%d", &z);
    if(x+y>z) {
        printf("Moze byc trojkat\n\n");
        if((x==y)||(y==z)||(x==z)) {
            printf("Moze byc trojkatem rownoramiennym lub rownobocznym\n\n");
        }
        else {
            printf("Ale nie moze byc trojkat rownoboczny lub rownoramienny\n\n");
        }
    }
    else {
        printf("Nie moze byc trojkat\n\n");
    }

 return 0;
}

/*
int digi(int a){
 int r, p;
 r = 1;
 p = 10;
 while(a>= p) {
 r = r + 1;
 p = p * 10;
 }
 return r;
}
int main(){
 int x;
 scanf("%d", &x);
 printf("%d\n", digi(x));
 return 0;
}
*/
