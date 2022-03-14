#include <stdio.h>
#include <stdlib.h>

/*
int t;

	struct trojkat
	{
		int a, b, c;
	};					// na koncu struktury po klamrze jest SREDNIK!!!!!

	///////////////////////////


	// struct trojkat t1;	// pierwszy sposob deklaracji struktury danego typu

	struct trojkat
	{
		int a, b, c;
	}t1;				// drugi sposob deklaracji struktury danego typu


int main()
{
	t1.a = 5;
	t1.b = 2;
	t1.c = 4;
}

*/

/* struct trojkat
{
    int a,b,c;
};


int obwod(struct trojkat);


main()
{
    struct trojkat tab[5];
    tab[0].a = 6;
    tab[0].b = 8;
    tab[0].c = 10;


	printf("result: %d", obwod(tab[0]));
    return 0;

}

int obwod(struct trojkat)
{
    return t.a+t.b+t.c;
}

*/


struct list
{
	int key;
	struct list *next;
};

struct list *ptr; 			//zmienna wskaznikowa wskazujaca na element listy

struct list *first = NULL;  // zmienna wskaznikowa wskazujaca na pierwszy element listy

struct list *prev;


int addAtEnd(int k)
{
	struct list *tmp, *newEl;
	newEl = (struct list*)malloc(sizeof(struct list));
	newEl->key = k;
	newEl->next = NULL;
	tmp = first;

	if(tmp==NULL)			// lista jest pusta
	{
		first = newEl;
		newEl->prev = NULL;
	}

	else 					// jeżeli lista nie jest pusta to wchodzimy w pętle
	{
		while(tmp->next)			// przechodzimy na ostatni element listy
			tmp = tmp->next;
		tmp->next = newEl;
		newEl->prev = tmp;
	}

	return 0;
}

int addAtBeginning(int k)
{
	struct list *newEl;
	newEl = (struct list*)malloc(sizeof(struct list));
	newEl->key = k;
	newEl->next = first;
	newEl->prev = NULL;
	if(first)					// sprawdzamy czy lista istnieje
		first->prev;			// poprzednik first czyli prev
	first = newEl;

	return 0;
}

void deleteFirstEl()
{
	struct list *tmp;
	if(first){
		tmp = first->next
		if(tmp)
			tmp->prev = NULL;
		free(first); 			// w C++: delete first;
		first = tmp;
	}
}

int deleteEl(int k)
{
	struct list *tmp;
	if(first)
	{
		if(first->key == k)
		{
			deleteFirstEl()
		}
		else
		{
			tmp = first;
			while((tmp)&&(tmp->key!=k))
				tmp = tmp->next;
			if(tmp)			// element o kluczu k istnieje;
			{
				tmp->prev->next = tmp->next;
				if(tmp->next)
					tmp->next->prev = tmp->prev;
			}
		}
	}
}

void showList()
{
	struct list *tmp;
	tmp = first;
	while(tmp)
	{
		printf("%d\n", tmp->key); 		//niech tmp wskazuje na key
		tmp = tmp->next;
	}
}


main()
{

	// SPOSOB W C++

		// ptr =  new list;


	// SPOSOB W C

	ptr = (struct list*)malloc(sizeof(struct list));

	ptr->key = 5;
	ptr->next = NULL; 	// przy zmiennych wskaźnikowych "->" zastępuje "." przy strukturach

	addAtEnd(5);
	addAtEnd(6);
	addAtEnd(9);

	showList();




}



/* otwieranie pliku: 

FILE *plik = fopen ("plik_teskstowy.txt", "w")	// jeżeli plik jest w tym samym folderze co program; "w" - do zapisu, "r" do odczytu
					"C:\...\plik_tekstowy.txt" 
					"..\plik_tekstowy.txt"		// jeżeli plik jest w folderze wyżej

					if(plik==NULL)				// dany plik nie istnieje albo sciezka jest zle podana -> plik nie został otwarty

		fclose(plik)							// pilk jest zamykany
