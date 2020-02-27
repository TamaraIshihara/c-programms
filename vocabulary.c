#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CHAR_SIZE 100 

struct voc {
			//int number;
			char *word;
			char *str;
			};

			
FILE *new_file;
void write(char *filename, struct voc *v);
void find(char *filename, struct voc *v);

int main(int argc, char* argv[] )
{	
	if (argc != 2)
	{
		printf ("There are no arguments\n");
		exit(0);
	}
	
	char *filename = argv[1];
	
	struct voc *v;
	v = malloc(sizeof(struct voc));
	
	v->word = malloc(CHAR_SIZE);
	v->str = malloc(CHAR_SIZE);
	
	for (;;)
	{
		int menu;
		int check;
		
		printf("1. Занести новое слово в словарь\n");
		printf("2. Поиск по словарю\n");
		printf("3.Выйти\n");
		
		scanf("%d", &menu);
		
		/*check = isdigit(menu);
		
		if (check == 0)
		{
			printf("FALSE\n");
		}
		else
		{
			printf("TRUE\n");
		}*/
		
		
		switch (menu)
		{
			case 1:
				write(filename, v);
				menu = 0;
				break;
			
			case 2:
				find(filename, v);
				break;
					
			case 3:
				exit(0);
				
			default:
				exit(0);
		}		
		
		
	}
	free (v);
	free(v->word);
	free(v->str);
	
	return 0;
}


void write(char *filename, struct voc *v )
{
	new_file = fopen(filename, "a+");
	
	if (feof(new_file) == 0)
	{
		feof(new_file);
	}
	
	printf("Введите слово: ");
	scanf("%99s", v->word);
	fprintf(new_file, "%s - ", v->word);
	
	printf("Введите перевод: ");
	scanf("%99s", v->str);
	fprintf(new_file, "%s\n", v->str);
	
	feof(new_file);
	
	fclose(new_file);
	
}

void find(char *filename, struct voc *v)
{
	char *key;
	key = malloc(CHAR_SIZE);
	printf("Введите ключ: ");
	scanf("%99s", key);
	
	
	
	
}
