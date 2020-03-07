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
void sort(char *filename);
static int compare(const void *up, const void *down)
{
	const struct voc *v_up = (const struct voc *)up;
	const struct voc *v_down = (const struct voc *)down;
	
	int result = strcmp(v_up->word, v_down->word);
	
	if(result <0)
	{
		return -1;
	}
	else if(result >0)
	{
		return 1;
	}
	
	return 0;
}

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
				sort(filename);
				//exit(0);
				
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
	char *ans;
	char chk_ans1[2] = "Y";
	char chk_ans2[2] = "y";
	int result1, result2;
	
	ans = malloc(CHAR_SIZE);
	
	printf("Сделать новую запись в файл? [y/n]\n");
	scanf("%2s", ans);
	printf("%s", ans);
	
	result1 = strcmp(ans, chk_ans1); 
	result2 = strcmp(ans, chk_ans2);
	
	while (result1 == 0 || result2 == 0 )
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
		
		memset(ans,'0', 1);
		
		printf("Сделать еще одну запись? [y/n]\n");
		scanf("%2s", ans);
		
		result1 = strcmp(ans, chk_ans1); 
		result2 = strcmp(ans, chk_ans2);
	
	}
	
	free(ans);
	fclose(new_file);
	
	
	
}

void find(char *filename, struct voc *v)
{
	new_file = fopen(filename, "a+");
	
	char *key;
	char *file;
	int check;
	
	key = malloc(CHAR_SIZE);
	file = malloc(CHAR_SIZE);
	
	printf("Введите ключ: ");
	scanf("%99s", key);
	
	printf("\n--------------------------------\n");
	
	while (1)
    {
        if (fgets(file, 99, new_file)) 
        {
        	if (strstr(file, key)) 
        	{
        		printf ("     %s", file);
        		check = 1;
        	}
        	
        } 
        else 
        {
        	break;
        }

    }
    
    
    if (check != 1)
    {
    	printf("Совпадений не найдено\n");
    }
    
    check = 0;
    
    printf("--------------------------------\n\n");
    free(key);
    free(file);
	fclose(new_file);
}

void sort (char *filename)
{
	char *file;
	int count = 0;
	char *text;
	
	struct voc *v = NULL;
	int max_voc_count = 10;
	size_t size_voc = sizeof(struct voc);
	
	v = malloc(max_voc_count * size_voc);
	

	file = malloc(CHAR_SIZE);
	
	new_file = fopen(filename, "a+");
	
	while(feof(new_file) == 0)
	{
		fgets(file, 99, new_file);
		
		
		if(feof(new_file))
		{
			break;
		}
		
		char *str1 = malloc(CHAR_SIZE);
		char *str2 = malloc(CHAR_SIZE);
		
		if(sscanf(file, "%s - %s", str1, str2) == 2)
		{
			if (count >= max_voc_count)
			{
				max_voc_count = max_voc_count * 2;
				v = realloc(v, max_voc_count * size_voc);
			}
			
			v[count].word = str1;
			v[count].str = str2;
		}
		else
		{
			printf("ERROR\n");
			free(str1);
			free(str2);
		}
		
		//printf("%s", file);
		count++;
	}
	if (count < max_voc_count)
	{
		v = realloc(v, count * size_voc);
	}
	
	for(int i = 0; i <count; i++)
	{
		printf("%s == %s\n", v[i].word, v[i].str);
	}
	
	qsort(v, count, size_voc, compare); //
	printf("s_____________________________________________s\n");
	
	for(int i = 0; i <count; i++)
	{
		printf("%s == %s\n", v[i].word, v[i].str);
	}
	
	free(file);
	fclose(new_file);
	
	
}
