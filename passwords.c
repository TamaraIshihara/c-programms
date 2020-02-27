#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <time.h>

int main (int a, char *argv[])
{

	int num, num1;
	int rand1, rand2;
	int pasnum;
	int pass, pass1;
	int j;
	int strl;
	
	char *argv3 = argv[3];
	
	srand (time(NULL));
	
	if (a < 4)
	{
		printf("No arguments\n");
		exit(0);
	}
	
	if (a > 4)
	{
		printf("Too many arguments\n");
		exit(0);
	}
	//printf("%s \n", argv3);
	
	strl = strlen(argv3);
	//printf("%d", strl);
	
	for (int i = 0; i < strl; i++)
	{
		//printf("%c\n", argv3[j]);
		j++;
	}
	
	num = atoi(argv[1]);
	num1 = atoi(argv[2]);

	
	//printf("%d \n", num);
	//printf("%d \n", num1);
	
	rand1 = num1 - num;
	rand2 = rand() % rand1;
	
	//printf("%d\n", rand2);
	
	pasnum = num + rand2;
	
	for (int i = 0; i < pasnum; i++)
	{
		pass = rand() % 9;
		pass1 = rand() % j;
		
		char a = argv3[pass1];
		
		printf("%d", pass);
		printf("%c", a);
	}
	
	printf("\n");

return 0;
}


