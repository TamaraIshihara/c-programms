#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE* new_file;
	char* filename = argv[1];
	char* attr = argv[2];
	char* file = malloc(100);
	char* memo = malloc(100);
	char n;
	int result1, result2, result3;
	char* attr1 = "r";
	char* attr2 = "w";
	char* attr3 = "d";
	
	if (argc != 3)
	{
		printf("There are no arguments\n");
		exit(0);
	}
	
	result1 = strcmp (attr1, attr);
	result2 = strcmp (attr2, attr);
	result3 = strcmp (attr3, attr);
	
	if (result1 == 0 && result2 !=0  && result3 != 0)
	{
		new_file = fopen(filename, "r");
		
		if(new_file == 0)
		{
			printf("There are no %s\n", filename);
			exit(0);
		}
	
		while(!feof(new_file))
		{
			fscanf(new_file,"%c", &n);
			printf("%c", n);
		}
		printf("\n");
		fclose(new_file);
	}
	else if(result1 != 0 && result2 ==0 && result3 !=0)
	{
		new_file = fopen(filename, "a+");
		
		printf("The new file was created\n");
		scanf("%s", memo);
		fprintf(new_file, "%s", memo);
		
		fclose(new_file);
	}
	else if(result1 != 0 && result2 !=0 && result3 ==0)
	{
		new_file = fopen(filename, "r+");
		
		if(new_file == 0)
		{
			printf("No file %s\n", filename);
			exit(0);
		}
		else
		{
			fclose(new_file);
			remove(filename);
		}
	}
	
	free (file);
	free (memo);
	
	return 0;
}
