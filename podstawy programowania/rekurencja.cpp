#include <stdio.h>

/*int fib(int);

main()
{
  int x;
  for(x=0; x<100; x++)
    printf("%d ", fib(x));
}

int fib(int x) {
  if (x == 0)
    return 0;
  else if (x == 1 || x == 2)
    return 1;
  else
    return (fib(x-1) + fib(x-2));
}



 int fib_it(int x)
{
	if (x == 0)
    	return 0;

  	else if (x == 1 || x == 2)
    	return 1;

  	else
  	{
  		int a = 1, b = 1, c;
  		for(int i=3; i<=x; i++)
  		{
  			c = a + b;
  			a = b;
  			b = c;
  		}
  	}
}


double power_it(double x, int n)
{
	if(n == 0)
		return 1.0;

	double wynik = 1.0;

	for(int i = 1; i<n; i++)
	{
		wynik *= x;
	}
}

*/

int silnia(int x)
{
	if(x == 0 || x == 1)
		return 1;
	else
	{
		return x*silnia(x-1);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int wynik = silnia(n);
	printf("Wynik: %d", wynik);
}