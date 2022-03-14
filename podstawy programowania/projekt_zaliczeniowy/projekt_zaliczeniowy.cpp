#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date
{
	int Year;
	int Month;
	int Day;
}StatusDate;

struct Book
{
	int ID;
	char Title[100];
	char AName[50];
	char ASurname[50];
	char Category[50];
	struct Date StatusDate;
	int Status;
	char PName[50];
	char PSurname[50];
	char Other[50];
	struct Book *next;
	struct Book *prev;
};

struct Book *ptr;
struct Book *first = NULL;
struct Book *last = NULL;

void AddBook();
void DeleteBookID(int k);
void DeleteBookTitle();
void EditBook();
void ChangeStatus();
void ShowList();


int main()
{

struct Book *temp;
char Option;
int run = 1;

printf("\t\t\t\t\t\tBAZA DANYCH: KSIAZKI");

while(run == 1)
{
	printf("\n\n\nMenu:\n\n1) Dodaj nowa ksiazke\n2) Usun ksiazke\n3) Edytuj dane ksiazki\n4) Zmien status ksiazki\n");
	printf("5) Wyszukaj ksiazke\n6) Wyswietl baze po tytulach\n7) Wyswietl ksiazki wypozyczone\n8) Zapisz do pliku\n9) Odczytaj z pliku\n");
	printf("X) Koniec pracy\n\n\nWybierz opcje: ");

	scanf("%s", &Option);

	switch(Option)
	{
		case '1':			// dodawanie książki do bazy danych
			{
			printf("\n1) Dodawanie nowej ksiazki\n");
			while(1)
			{
				AddBook();
				printf("Czy chcesz dodac kolejna ksiazke do bazy danych? Jezeli tak, wpisz 1. Jezeli nie, wpisz 0.\n");
				char addAnother;
				scanf("%s", &addAnother);

				if(addAnother == '1')
					continue;

				else if(addAnother == '0')
					break;
				else
				{
					printf("\nNieprawidlowa wartosc. Nastapi przeniesienie do menu.\n\n");
					break;
				}
			}
			break;
        	}

		case '2':			// usuwanie ksiazek
			{
				printf("\n2) Usun ksiazke\n\n");

				if(first)
				{
					printf("Jezeli chcesz usunac ksiazke po ID, wpisz 1. Jezeli chcesz usunac ksiazke po tytule, wpisz 2.\n");
					char DeleteOption;
					scanf("%s", &DeleteOption);
					switch(DeleteOption)
					{
						case '1':
						{
							int id;
							printf("Wprowadz ID ksiazki do usuniecia:\n");
							scanf("%d", &id);
							DeleteBookID(id);
							break;
						}

						case'2':
						{
							DeleteBookTitle();
							break;
						}

						default:
							printf("Wprowadzono niewlasciwy znak. Nastapi przeniesienie do menu.\n\n");
							break;
					}
				}

				else
				{
					printf("Brak ksiazek w bazie danych.\n\n");
					break;
				}

				break;
			}

		case '3':			// edytowanie ksiazek
			{
			printf("\n3) Edytuj dane ksiazki\n\n");

			if(first)
			{
				printf("Jezeli chcesz edytowac ksiazke po jej ID, wpisz 1. Jezeli chcesz edytowac ksiazke po jej tytule, wpisz 2.\n");
				char EditOption;
				scanf("%s", &EditOption);

				switch(EditOption)
				{
					case '1':
					{
						printf("\nPodaj ID ksiazki, ktorej dane chcesz edytowac.\n");
						int id;
						scanf("%d", &id);
						for(ptr = first; ptr != NULL; ptr = ptr->next)
						{
							if(temp != NULL)
								{
									if(ptr->ID == id)
									{
										EditBook();
										break;
									}
								}
							else
								{
										printf("Ksiazka o podanym ID nie istnieje.\n\n");
										break;
								}

						}
						break;
					}

					case '2':
					{
						printf("\nPodaj tytul ksiazki, ktorej dane chcesz edytowac.\n");
						char tedit[100];
						char titl;
						int i = 0;
						fflush(stdin);
						while(titl != '\n')
							{
								titl = getc(stdin);
								tedit[i++] = titl;
							}

						tedit[--i]='\0';

						for(ptr = first; ptr != NULL; ptr = ptr->next)
							if(temp != NULL)
								{
									if(strcmp(ptr->Title, tedit) == 0)
									{
										EditBook();
										break;
									}
								}

								else
								{
									printf("\nKsiazka o danym tytule nie istnieje.\n");
									break;
								}

						titl = '\0';
						break;
					}

					default:
						printf("\nWprowadzono niewlasciwy znak. Nastapi przeniesienie do menu.\n\n");
						break;
				}
			}

			else
			{
				printf("Brak ksiazek w bazie danych.\n\n");
				break;
			}

			break;
			}

		case '4':			// zmiana statusu wypozyczenia
			{
				printf("\n4)Zmien status ksiazki\n\n");
				if(first)
				{
					printf("Jezeli chcesz zmienic status ksiazki po jej ID, wpisz 1. Jezeli chcesz zmienic status ksiazki po jej tytule, wpisz 2.\n");
					char StatusOption;
					scanf("%s", &StatusOption);

					switch(StatusOption)
					{
						case '1':
						{
							printf("\nPodaj ID ksiazki, ktorej status chcesz zmienic.\n");
							int id = 0;
							scanf("%d", &id);
							for(ptr = first; ptr != NULL; ptr = ptr->next)
								{
									if(temp != NULL)
									{
										if(ptr->ID == id)
										{
											ChangeStatus();
											break;
										}

									}
									else
									{
										printf("Ksiazka o podanym ID nie istnieje w bazie danych.\n\n");
										break;
									}

								}

							break;
						}

						case '2':
						{
							printf("\nPodaj tytul ksiazki, ktorej status chcesz zmienic.\n");
							char titl;
							char tstatus[100];
							int i = 0;
							fflush(stdin);
							while(titl != '\n')
							{
								titl = getc(stdin);
								tstatus[i++] = titl;
							}

							tstatus[--i]='\0';

							for(ptr = first; ptr != NULL; ptr = ptr->next)
							{
								if(ptr != NULL)
								{
									if(strcmp(ptr->Title, tstatus) == 0)
									{
										ChangeStatus();
										break;
									}
								}

								else
								{
									printf("\nKsiazka o danym tytule nie istnieje w bazie danych.\n\n");
									break;
								}

							}

							titl = '\0';
							break;
						}

						default:
							printf("\nWprowadzono niewlasciwy znak. Nastapi przeniesienie do menu.\n\n");
							break;
					}
				}

				else
				{
					printf("Brak ksiazek w bazie danych.\n\n");
					break;
				}

				break;
			}

		case '5':			// wyszukaj ksiazke
			{
				printf("\n5) Wyszukaj ksiazke\n\n");
				if(first)
				{
					printf("Jezeli chcesz wyszukac dane ksiazki po jej ID, wpisz 1.\nJezeli chcesz wyszukac dane ksiazki po jej tytule, wpisz 2.\nJezeli chcesz wyszukac dane ksiazek po nazwisku wypozyczajacego, wpisz 3.\n");
					char SearchOption;
					scanf("%s", &SearchOption);
					switch(SearchOption)
					{
						case '1':
						{
							printf("\nPodaj ID ksiazki, ktorej dane chcesz wyszukac.\n");
							int id;
							scanf("%d", &id);
							for(ptr = first; ptr != NULL; ptr = ptr->next)
							{
								if(temp != NULL)
								{
									if(ptr->ID == id)
									{
										temp = ptr;
										printf("\nDane ksiazki:\n\n");
										printf("ID: %d\nTytul: %s\nImie autora: %s\nNazwisko autora: %s\nKategorie ksiazki: %s\nInne dane: %s\n", temp->ID, temp->Title, temp->AName, temp->ASurname, temp->Category, temp->Other);
										if(temp->Status == 1)
											printf("Imie wypozyczajacego: %s\nNazwisko wypozyczajacego: %s\nData wypozeczenia: %d.%d.%dr.\n\n", temp->PName, temp->PSurname, temp->StatusDate.Day, temp->StatusDate.Month, temp->StatusDate.Year);

									break;
									}

								}
								else
								{
									printf("Ksiazka o podanym ID nie istnieje w bazie danych.\n\n");
									break;
								}
							}

							break;
						}

						case '2':
						{
							printf("\nPodaj tytul ksiazki, ktorej dane chcesz wyszukac.\n");
							char titl;
							char tsearch[100];
							int i = 0;
							fflush(stdin);
							while(titl != '\n')
							{
								titl = getc(stdin);
								tsearch[i++] = titl;
							}

							tsearch[--i]='\0';

							for(ptr = first; ptr != NULL; ptr = ptr->next)
							{
								if(temp != NULL)
								{
									if(strcmp(ptr->Title, tsearch) == 0)
									{
										temp = ptr;
										printf("\nDane ksiazki:\n\n");
										printf("ID: %d\nTytul: %s\nImie autora: %s\nNazwisko autora: %s\nKategorie ksiazki: %s\nInne dane: %s\n", temp->ID, temp->Title, temp->AName, temp->ASurname, temp->Category, temp->Other);
										if(ptr->Status == 1)
											printf("Imie wypozyczajacego: %s\nNazwisko wypozyczajacego: %s\nData wypozeczenia: %d.%d.%dr.\n\n", temp->PName, temp->PSurname, temp->StatusDate.Day, temp->StatusDate.Month, temp->StatusDate.Year);

									break;
									}
								}

								else
								{
									printf("Ksiazka o danym tytule nie istnieje w bazie danych.\n\n");
									break;
								}
							}

							titl = '\0';
							break;
						}

						case '3':
						{
							printf("\nPodaj nazwisko wypozyczajacego, ktorego dane wypozyczonych ksiazek chcesz wyszukac.\n");
							char surn;
							char ssearch[100];
							int i = 0;
							fflush(stdin);
							while(surn != '\n')
							{
								surn = getc(stdin);
								ssearch[i++] = surn;
							}

							ssearch[--i]='\0';

							for(ptr = first; ptr != NULL; ptr = ptr->next)
							{
								if(temp != NULL)
								{
									printf("\nKsiazki wypozyczone przez osobe o nazwisku %s:\n\n", ptr->PSurname);
									for(temp = first; temp != NULL; temp = temp->next)
									{
										if((temp->Status == 1) && (strcmp(temp->PSurname, ssearch) == 0))
										{
											printf("ID: %d\n\nTytul: %s\nImie autora: %s\nNazwisko autora: %s\nKategorie ksiazki: %s\nInne dane: %s\n", temp->ID, temp->Title, temp->AName, temp->ASurname, temp->Category, temp->Other);
											printf("Imie wypozyczajacego: %s\nNazwisko wypozyczajacego: %s\nData wypozeczenia: %d.%d.%dr.\n\n", temp->PName, temp->PSurname, temp->StatusDate.Day, temp->StatusDate.Month, temp->StatusDate.Year);
											break;
										}
									}
								}

								else
								{
									printf("Osoba o takim nazwisku nie istnieje w bazie danych.\n\n");
									break;
								}
							}

							surn = '\0';
							break;
						}

						default:
							printf("Wprowadzono nieprawidlowy znak. Nastapi przeniesienie do menu.\n\n");
							break;
					}
				}

				else
					printf("Brak ksiazek w bazie danych.\n\n");

				break;
			}

		case '6':			// wyswietl baze po tytulach
			{
				printf("\n6) Wyswietl ksiazki po tytulach\n\n");
				if(first)
					ShowList();
				else
					printf("Brak ksiazek w bazie danych.\n\n");

				break;
			}

		case '7':			// wyswietl tytuly ksiazek wypozyczonych
			{
				printf("\n7) Wyswietl ksiazki wypozyczone\n\n");
				if(first)
				{
					printf("ID:\t\t Tytul:\n\n");
					for(ptr = first; ptr != NULL; ptr = ptr->next)
					{
						temp = ptr;
						if(temp->Status == 1)
						{
							printf("%d\t\t%s", temp->ID, temp->Title);
							break;
						}

						else
						{
							printf("\nZadna ksiazka nie jest aktualnie wypozyczona.\n");
							break;
						}
					}
				}

				else
					printf("Brak ksiazek w bazie danych.\n\n");

				break;
			}


		case '8':			// zapisz do pliku
			{
				printf("\n8) Zapisz do pliku\n\n");
				FILE *fptr;
				char fil[30];
				memset(fil, 0, 30*sizeof(char));
				printf("Podaj nazwe pliku do zapisu (bez rozszerzenia):\n");
				scanf("%s", fil);
				strcat(fil, ".txt");

				fptr = fopen(fil, "w");

				if(fptr == NULL)
				{
					printf("Blad otwierania pliku. Plik nie zostal otwarty.\n\n");
					break;
				}

				else
				{
					temp = first;

					for(int i = 0; temp; i++)
    				{
    					fprintf(fptr, "\n%d\n", temp->ID);
    					fprintf(fptr, "%s\n", temp->Title);
    					fprintf(fptr, "%s\n", temp->AName);
    					fprintf(fptr, "%s\n", temp->ASurname);
    					fprintf(fptr, "%s\n", temp->Category);
    					fprintf(fptr, "%s\n", temp->Other);
    					fprintf(fptr, "%d\n", temp->Status);
    					fprintf(fptr, "%d\n", (temp->StatusDate.Day));
    					fprintf(fptr, "%d\n", (temp->StatusDate.Month));
    					fprintf(fptr, "%d\n", (temp->StatusDate.Year));
						fprintf(fptr, "%s\n", temp->PName);
						fprintf(fptr, "%s\n", temp->PSurname);

						temp = temp->next;
    				}

    				printf("\nZapisano dane do pliku %s\n\n", fil);
    			}

    			fclose(fptr);
				break;
			}

		case '9':			// odczytaj z pliku
			{
				printf("\n9)Odczytaj z pliku\n\n");
				char fil[30];
				FILE *fread;
				memset(fil, 0, 30*sizeof(char));
				printf("Podaj nazwe pliku do oczytu (bez rozszerzenia):\n");
				scanf("%s", fil);
				strcat(fil, ".txt");

				fread = fopen(fil, "r");

				if(fread == NULL)
				{
					printf("Blad otwierania pliku. Plik nie zostal otworzony.\n\n");
        			break;
				}

				else
				{
					if(first)							// czyszczenie listy
					{
						ptr = first;
						while(ptr->next)
						{
							temp = ptr;
							ptr = ptr->next;
							free(temp);
						}
					}

					char t[100];
					char c;
					first = NULL;
					last = NULL;
					memset(t, 0, 100*sizeof(char));
					int i = 0;
					int j = 0;
					c = getc(fread);

					while(c != EOF)
					{
						if(c == '\n')
							j++;
						c = getc(fread);
					}

					j = j/12;


				fseek(fread, 0, 0);					// kursor na początek

				c = getc(fread);

				while((c = fgetc(fread)) != EOF)
				{
					fseek(fread, 0, 0);
					for( ; j>0; j--)
					{
						struct Book *El;
						El = (struct Book*)malloc(sizeof(struct Book));		//tworzenie nowej listy

						if((first == NULL) && (last == NULL))
						{
							first = El;
							last = El;
							El->prev = NULL;
							El->next = NULL;
						}

						else
						{
							El->prev = temp;
							temp->next = El;
							El->next = NULL;
							last = El;
						}

						fscanf(fread, "%d\n", &(El->ID));			//pobranie pierwszej linijki, wrzucenie na początek listy

						i = 0;
						c = getc(fread);
						while(c != '\n')
						{
		 		       		t[i++]=c;
			   				c=getc(fread);
						}

						t[i]='\0';
						strcpy(El->Title, t);

						fscanf(fread, "%s\n", &(El->AName));
						fscanf(fread, "%s\n", &(El->ASurname));
						fscanf(fread, "%s\n", &(El->Category));
						fscanf(fread, "%s\n", &(El->Other));
						fscanf(fread, "%d\n", &(El->Status));
						fscanf(fread, "%d\n", &(El->StatusDate.Day));
						fscanf(fread, "%d\n", &(El->StatusDate.Month));
						fscanf(fread, "%d\n", &(El->StatusDate.Year));

						if(El->Status == 1)
						{
							fscanf(fread, "%s\n", &(El->PName));
							fscanf(fread, "%s\n", &(El->PSurname));
						}

						else
						{
							char x[50];
							memset(x, 0, 50*sizeof(char));
							strcpy(El->PName, x);
							strcpy(El->PSurname, x);
						}

						temp = El;
					}
				}

				fclose(fread);

				printf("\nUtworzono nowa liste na podstawie pliku %s\n\n", fil);
			}

					break;
			}

		case 'X':			// koniec pracy programu
			{
				printf("\nX) KONIEC PRACY PROGRAMU\nDziekujemy za skorzystanie z programu.\n\n");
				run = 0;
				break;
			}

		case 'x':
			{
				printf("\nX) KONIEC PRACY PROGRAMU\nDziekujemy za skorzystanie z programu.\n\n");
				run = 0;
				break;
			}

		default:
			printf("\nPodano niewlasciwy znak.\n\n");
			break;
	}
}

return 0;
}

void AddBook()
	{
		struct Book *temp, *newEl;
		newEl = (struct Book*)malloc(sizeof(struct Book));

		char tit[100];
		char c;
		int i = 0;
		fflush(stdin);
		printf("\nPodaj tytul ksiazki:\n");
		while(c != '\n')
		{
			c = getc(stdin);
			tit[i++] = c;
		}

		tit[--i]='\0';
		strcpy(newEl->Title, tit);
		i = 0;

		printf("\nPodaj imie autora ksiazki:\n");
		char name[50];
		char n;
		fflush(stdin);
		while(n != '\n')
		{
			n = getc(stdin);
			name[i++] = n;
		}

		name[--i]='\0';
		strcpy(newEl->AName, name);
		i = 0;

		printf("\nPodaj nazwisko autora ksiazki:\n");
		char sname[50];
		char s;
		fflush(stdin);
		while(s != '\n')
		{
			s = getc(stdin);
			sname[i++] = s;
		}

		sname[--i]='\0';
		strcpy(newEl->ASurname, sname);
		i = 0;


		printf("\nPodaj kategorie ksiazki:\n");
		char cat[50];
		char ca;
		fflush(stdin);
		while(ca != '\n')
		{
			ca = getc(stdin);
			cat[i++] = ca;
		}

		cat[--i]='\0';
		strcpy(newEl->Category, cat);
		i = 0;
		ca = '\0';

		memset(newEl->Other, 0, 50*sizeof(char));

		printf("\nInne informacje o ksiazce (jesli brak, kliknij ENTER):\n");
		char oth[50];
		char o;
		fflush(stdin);
		o = getc(stdin);
		if(o != '\n')
		{
			while(o != '\n')
			{
				oth[i++] = o;
				o = getc(stdin);
			}

			oth[i]='\0';
			strcpy(newEl->Other, oth);
			i = 0;
		}

		else
		{
			char oth[] = "Brak.\0";
			strcpy(newEl->Other, oth);
		}
		o = '\0';


		newEl->Status = 0;

		newEl->StatusDate.Day = NULL;
    	newEl->StatusDate.Month = NULL;
    	newEl->StatusDate.Year = NULL;
    	memset(newEl->PName, 0, 50*sizeof(char));
    	memset(newEl->PSurname, 0, 50*sizeof(char));

		newEl->next = NULL;
		temp = first;

		if(temp==NULL)			// lista jest pusta
		{
			first = newEl;
			newEl->prev = NULL;
		}

		else 					// jeżeli lista nie jest pusta to wchodzimy w pętle
		{
			while(temp->next)			// przechodzimy na ostatni element listy
				temp = temp->next;
			temp->next = newEl;
			newEl->prev = temp;
		}

		last = newEl;
		temp = first;

		for(int i=1; temp; i++)
		{
			if(temp->ID == i)
			{
				temp = temp->next;
				continue;
			}

			else
			{
				newEl->ID = i;
				for(temp=first; temp = NULL; temp = temp->next)
					if(newEl->ID != temp->ID)
						continue;
			}
		}

		printf("\nDodano nowa ksiazke o ID: %d i tytule: '%s'.\n\n", newEl->ID, newEl->Title);
	}


void DeleteBookID(int k)
{
	struct Book *temp;
	if(first->ID == k)
	{
		temp = first->next;
		if(temp)
			temp->prev = NULL;
		free(first);
		first = temp;
		printf("\nUsunieto ksiazke o ID %d.\n", k);
	}

	else
	{
		temp = first;
			while((temp)&&(temp->ID != k))
				temp = temp->next;
			if(temp)			// element o danym id istnieje;
			{
				temp->prev->next = temp->next;
				if(temp->next)
					temp->next->prev = temp->prev;
				printf("\nUsunieto ksiazke o ID %d.\n", k);
				free(temp);
			}



			else
				printf("Ksiazka o danym ID nie istnieje.\n\n");
	}

}


void DeleteBookTitle()
{
	struct Book *temp;
	char tdelete[100];
	printf("Podaj tytul ksiazki, ktora chcesz usunac.\n");
	char t;
	int i = 0;
	fflush(stdin);
	while(t != '\n')
	{
		t = getc(stdin);
		tdelete[i++] = t;
	}

	tdelete[--i]='\0';

	if(strcmp(first->Title, tdelete) == 0)
	{
		temp = first->next;
		if(temp)
			temp->prev = NULL;
		free(first);
		first = temp;
		printf("\nUsunieto ksiazke o tytule %s.\n", tdelete);
	}

	else
	{
		temp = first;
			while((temp)&&(strcmp(temp->Title, tdelete) != 0))
				temp = temp->next;
			if(temp)			// element o danym tytule istnieje;
			{
				temp->prev->next = temp->next;
				if(temp->next)
					temp->next->prev = temp->prev;
				printf("\nUsunieto ksiazke o tytule %s.\n", tdelete);
			}

			else
				printf("Ksiazka o danym tytule nie istnieje.\n\n");
	}

	t = '\0';
}


void EditBook()
{
    struct Book *temp;
	temp = ptr;
	printf("\nUWAGA: W przypadku klikniecia ENTER bez wpisywania nowych danych, stare dane nie zostana zmienione.\n\n");
	printf("Podaj nowy tytul ksiazki:\n");
	char c;
	fflush(stdin);
	int i = 0;
	c = getc(stdin);
	if(c != '\n')
	{
		char tit[100];
		while(c != '\n')
		{
			tit[i++] = c;
			c = getc(stdin);
		}

		tit[i]='\0';
		strcpy(temp->Title, tit);
		i = 0;
	}

	else
		;
	c = '\0';

	printf("\nPodaj nowe imie autora ksiazki:\n");
	char n;
	fflush(stdin);
	n = getc(stdin);

	if(n != '\n')
	{
		char name[50];
		while(n != '\n')
		{
			name[i++] = n;
			n = getc(stdin);
		}

		name[i]='\0';
		strcpy(temp->AName, name);
		i = 0;
	}
	else
		;
	n = '\0';

	printf("\nPodaj nowe nazwisko autora ksiazki:\n");
	char s;
	fflush(stdin);
	s = getc(stdin);

	if (s != '\n')
	{
		char sname[50];
		while(s != '\n')
		{
			sname[i++] = s;
			s = getc(stdin);
		}

		sname[i]='\0';
		strcpy(temp->ASurname, sname);
		i = 0;
	}
	else
		;
	s = '\0';

	printf("\nPodaj nowe kategorie ksiazki:\n");
	char ca;
	fflush(stdin);
	ca = getc(stdin);
	if(ca != '\n')
	{
		char cat[50];
		while(ca != '\n')
		{
			cat[i++] = ca;
			ca = getc(stdin);
		}

		cat[i]='\0';
		strcpy(temp->Category, cat);
		i = 0;
	}
	else
		;
	ca = '\0';

	printf("\n Podaj nowe inne informacje o ksiazce: \n\n");
	char o;
	fflush(stdin);
	o = getc(stdin);
	if(o != '\n')
	{
		char oth[50];
		while(o != '\n')
		{
			oth[i++] = o;
			o = getc(stdin);
		}

		oth[i]='\0';
		strcpy(temp->Other, oth);
		i = 0;
	}

	else
		;
	o = '\0';

	printf("\nPomyslnie edytowano dane ksiazki.\n\n");
}

void ChangeStatus()
{
	struct Book *temp;
	if(ptr->Status == 0)
	{
		temp = ptr;
		printf("\nKsiazka nie jest wypozyczona.\n\nPodaj imie osoby wypozyczajacej ksiazke:\n");
		char pname[50];
		char pn;
		int i = 0;
		fflush(stdin);
		while(pn != '\n')
		{
			pn = getc(stdin);
			pname[i++] = pn;
		}

		pname[--i]='\0';
		strcpy(temp->PName, pname);
		i = 0;
		pn = '\0';

		printf("\nPodaj nazwisko osoby wypozyczajacej ksiazke:\n");
		char sname[50];
		char s;
		fflush(stdin);
		while(s != '\n')
		{
			s = getc(stdin);
			sname[i++] = s;
		}

		sname[--i]='\0';
		strcpy(temp->PSurname, sname);
		i = 0;
		s = '\0';

		printf("\nPodaj date wypozyczenia. UWAGA: date nalezy wpisac za pomoca cyfr.\n\nDzien: ");
		scanf("%d", &(temp->StatusDate.Day));
		printf("\nMiesiac: ");
		scanf("%d", &(temp->StatusDate.Month));
		printf("\nRok: ");
		scanf("%d", &(temp->StatusDate.Year));
		
		temp->Status = 1;
		printf("\nPomyslnie zmieniono status ksiazki.\n\n");
		
	}

	else
	{
		temp = ptr;
		printf("\nKsiazka jest wypozyczona.\n\nDane ksiazki:\n\nTytul: %s\nImie autora: %s\nNazwisko autora: %s\n", temp->Title, temp->AName, temp->ASurname);
        printf("Kategorie ksiazki: %s\nInne dane: %s\nImie osoby wypozyczajacej: %s\nNazwisko osoby wypozyczajacej: %s\nData wypozyczenia: %d.%d.%dr.\n\n", temp->Category, temp->Other, temp->PName, temp->PSurname, temp->StatusDate.Day, temp->StatusDate.Month, temp->StatusDate.Year);

			while(1)
			{
				printf("\nCzy zmienic status ksiazki na oddana? Jezeli tak, wpisz 1. Jezeli nie, wpisz 2.\n\n");
				char ans;
				scanf("%s", &ans);
				if(ans == '1')
				{
					memset(ptr->PName, 0, 50*sizeof(char));
					memset(ptr->PSurname, 0, 50*sizeof(char));
					ptr->StatusDate.Day = 0;
					ptr->StatusDate.Month = 0;
					ptr->StatusDate.Year = 0;
					ptr->Status = 0;
					printf("\nPomyslnie zmieniono status ksiazki.\n\n");
					break;
				}

				else if(ans == '2')
					break;

				else
				{
					printf("\nPodano nieprawdlowy znak.\n");
					continue;
				}
			}
	}
}


void ShowList()
{
	struct Book *temp;
	temp = first;
	if(temp)
	{
		printf("\nID:\t\tTytul:\n");
		while(temp)
		{
			printf("%d\t\t%s\n", temp-> ID, temp->Title); 		//niech temp wskazuje na Title
			temp = temp->next;
		}
	}
	else
		printf("Brak ksiazek w bazie danych.\n\n");
}

