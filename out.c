#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

static char str [N][N];
static int count=0;
static int j = 0;
void case1();  //создать
void case2();  //найти
void case3();  //показать все
void case4();  //удалить
void case5();  //перезаписать 
void case6();  //записать в выбранную ячейку
void case7();  //exit

int main(int argc, char ** argv)
{

	for (;;)
	{
		int a;
		printf("\n----------------------------------\n");
		printf("|  Choose the number of action:  |\n");
		printf("| 1. Create memo.                |\n");
		printf("| 2. Find memo.                  |\n");
		printf("| 3. Show all memos.             |\n");
		printf("| 4. Delete memo.                |\n");
		printf("| 5. Rewrite memo.               |\n");
		printf("| 6. Write memo in a chosen num. |\n");
		printf("| 7. Exit.                       |\n");
		printf("----------------------------------\n\n");

		printf("Enter the number: ");
		scanf("%d", &a);
		//printf("got choice: %d\n", a);
		switch (a)
		{
		case 1:
			case1();
			break;

		case 2:
			case2();
			break;

		case 3:
			case3();
			break;

		case 4: 
			case4();
			break;

		case 5:
			case5();
			break;

		case 6:
			case6();
			break;

		case 7:
			case7();
			break;

		default:
			return 0;
 
		}

	}

	return 0;
}

void case1()
{
	char ans[3];
	char a1[] = "y";
	char a2[] = "Y";
	int result1, result2;

	again:

	if (count < N ) 
	{

		//again:
		printf("Input memo: ");
		scanf("%9s", &str[count]);
		printf("Your memo is: %s\n", str[count]);
		count++;

		printf("Create another one?[y/n] \n");
		scanf("%s", &ans);

		result1 = strcmp (ans, a1);
		//printf("%s u %s", ans, a1);
	
		//count++;
		result2 = strcmp (ans, a2);
		//printf("%s u %s", ans, a2);
	

		if (result1 == 0 || result2 == 0)
			{
			//printf("TRUE\n");
			goto again;
			}	
		else
			printf("Going to main menu...\n\n\n");
	}

	else
		{
		if (count >= N )
		{
		printf (" --No free container. Please, clean another container or rewrite chosen container--\n\n");
		}
		
	}
}
	
void case2()
{
	char key [N];
	int result;
	int memo;
	int res = 0;
	//char str1[] = "TEST";
	//char str2[] = "TEST1";
	char done[] = "Finding...";
	int count1= 0;

	printf ("Enter keyword: ");
	scanf ("%9s", &key);


	//printf("%s\n", key);

	for ( count = 0; count<N; count++) //правка i = count
	{

	//printf("%9s\n", str[i]); 
	result = strcmp (key, str[count]);
	//printf ("N = %d, %s\n", count, str[count]);

	if (result == 0)
		{	
		res = 1;
		printf ("%d. %s\n", count+1, str[count]);
		//printf ("TRUE\n");
		//break;
		}
	/*else
		{ 
		//printf("%s\n", done);
	
		}*/
	}

	if (res != 1)
		{
		printf ("There are no '%s' \n", key);
		}
	res = 0; 
	
}

void case3()
{
 	for ( int i = 0; i<N; i++)
		{
		j++;
		printf("%d. %s\n", j, str[i]);
		}
	j = 0;
}

void case4()
{
	int i,j;
	printf("Enter the number of memo:");
	scanf("%d", &count);
	printf("%d. %s",count, str[count-1]);
	memset (str[count-1], 0, sizeof(str[count-1]));
	
}

void case5()
{
	char ans[3];
	char a1[] = "y";
	char a2[] = "Y";
	int result1, result2;
	printf("Enter the num of memo for rewriting:\n");
	scanf("%d", &count);
	printf("%d. %s. ", count, str[count-1]);
	printf("Do you really want to rewrite memo? [y/n]\n");
	scanf("%s", &ans);
	
	result1 = strcmp (ans, a1);
	result2 = strcmp (ans, a2);
	if (result1 == 0 || result2 == 0)
		{
		//printf("true");
		printf("Enter the new memo: \n");
		memset (str[count-1], 0, sizeof(str[count-1]));
		scanf("%9s", str[count-1]);
		printf("The memo rewrote. \n");

		}
	else
		printf("Going to main menu...\n\n\n");

}

void case6()
{	
	printf("Enter the number of container: \n");
	scanf("%d", &count);
	printf("Enter the text:");
	scanf("%9s", &str[count-1]);
	printf("done\n");
	
}

void case7()
{	printf("          -------------------------------- \n");
	printf("          |   Thanks for using memopad.  | \n");
	printf("          -------------------------------- \n");
	exit(0);
}

