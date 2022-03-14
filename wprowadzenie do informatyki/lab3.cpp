#include <stdio.h>
int main(void) {
int n, i, x[10];
scanf("%d", &n);
for (i = 0; i < n; i++) {
    scanf("%d", &x[i]);
}
for (i--; i >= 0; i--) {
    printf("%d", x[i]);
}
printf("\n");
return 0;
}
