#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	int roll;
	char name[50];
	float marks[3];
	float avg;
}s[100];


int n = 0;

void init ()
{
	int i;
	for ( i = 0; i < n; i++ )
	{
		int j;
		printf ( "\n\t Enter roll ==> ");
		scanf ( "%d", &(s[i].roll ));
		printf ( "\n\t Enter name ==> ");
		//scanf("%[^\n]", (s[i].name));
		gets(s[i].name);
		gets(s[i].name);
	
		printf ( "\n\t Enter marks of 3 subjects ==> ");
		float sum = 0;
		for (j = 0; j < 3; j++)
		{
			scanf("%f", &(s[i].marks[j]));
			sum += s[i].marks[j];
			s[i].avg = sum/3;
		}	
	}
}

void display ( struct student s)
{
	int i;
	printf( "\n\t Roll ==> %d", s.roll);
	printf( "\n\t Name ==> %s", s.name);
	printf( "\n\t Marks ==> ");
	for ( i = 0; i < 3; i++ )
		printf ("%f ",s.marks[i]);
	printf( "\n\t Avg ==> %f", s.avg);	
	printf ( "\n\n" );
}

void sort ()
{
	int i, j;
	struct student temp;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n-1; j++ )
		{
			if(strcmp(s[j+1].name,s[j].name) < 0)
			{
				temp = s[j+1];
				s[j+1] = s[j];
				s[j] = temp;
			}
		}
	}
}

void insert( int new)
{
		int i = new;
		int j;
		printf ( "\n\t Enter roll ==> ");
		scanf ( "%d", &(s[i].roll ));
		printf ( "\n\t Enter name ==> ");
		//scanf("%[^\n]", (s[i].name));
		gets(s[i].name);
		gets(s[i].name);
	
		printf ( "\n\t Enter marks of 3 subjects ==> ");
		float sum = 0;
		for (j = 0; j < 3; j++)
		{
			scanf("%f", &(s[i].marks[j]));
			sum += s[i].marks[j];
			s[i].avg = sum/3;
		}
}

void modify()
{
	int mod, i, flag = 0;;
	printf ("\n\n\t Enter roll number to be modified ==> ");
	scanf ("%d",&mod);
	for ( i = 0; i < n; i++ )
	{
		if (s[i].roll == mod)
		{
			printf ("\n\n\t Old Details");
			display(s[i]);
			printf ( "\n\n\t New Details");
			insert(i);
			flag = 1;
			break;
		}
	}
	if ( flag == 0 )
		printf("\n\n\t Student not found!");
	
}

void delete()
{
	int mod, i, flag = 0, x = 0;
	printf ("\n\n\t Enter roll number to be deleted ==> ");
	scanf ("%d",&mod);
	for ( i = 0; i < n; i++ )
	{
		if (s[i].roll == mod)
		{
			flag = 1;
			x = i;
			printf ( "\n\t Student deleted" );
		}
	}
	for ( i = x; i < n - 1; i++)
	{
		s[i] = s[i+1];
	}
	n--;
	if ( flag == 0 )
		printf("\n\n\t Student not found!");
	
}

main()
{
	printf ( "\n\n\t Enter number of students to be entered ==> ");
	scanf ("%d", &n);
	init (n);
	
	int ch = 0;
	while ( ch != 6 )
	{
		printf ( "\n\n\t\t Main Menu ");
		printf ( "\n\t1.Sort by name\n\t2.Display all students\n\t3.Modify a specific student\n\t4.Insert a new student\n\t5.Delete a student\n\t6.Exit\n\n\t==> ");
		int i;
		scanf ("%d",&ch);
		switch(ch)
		{
			case 1: sort();
					break;
			case 2: for ( i = 0; i < n; i++ ){display(s[i]);}
					break;
			case 3: modify();
					break;
			case 4: insert(n);
					n++;
					break;
			case 5: delete();
					break;
			case 6: break;
		}
	}
}
