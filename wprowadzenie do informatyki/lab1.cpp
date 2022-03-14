#include <stdio.h>

/* int a(int n) {
 int a = 0;
 while (n != 0) {
 a = a * 2;
 a = a + n % 10;
 n = n / 10;
 }
 return a;
}
int main() {
 int n;
 scanf("%d", &n);
 printf("%d\n", a(n));
 return 0;
}

*/

int main() {
 int tab[] = { 17, 13, 11 };
 int *ptr = &tab[1];
 printf("%d ", *(tab + 2));
 printf("%d ", *(ptr--));
 printf("%d\n", *(ptr + 1));
 return 0;
}
