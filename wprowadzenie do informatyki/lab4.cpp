#include <string.h>
#include <stdio.h>
int main(){
char Expected[]= "Warsaw";
char Provided[100];
scanf("%s", &Provided);
if (!strcmp(Expected, Provided))
printf("%s %s\n", Expected, Provided);
else printf("%s %s\n", Expected, Provided);
return 0; }
