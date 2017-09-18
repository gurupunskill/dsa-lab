#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int intmaker(char *token)
{
	int n = strlen(token);
	int a, ans = 0, i = 0;

	for( i = 0; i < n; i++ )
	{
		a = (int)token[i] - 48;
		ans += (a*pow(10,n-i-1));
	}
	return ans;
}

float eval(char* str)
{
	
	char* tokens[25];
	int i = 0;
	const char s[2] = " ";
		
	tokens[i] = strtok( str,s );
	while( tokens[i] != NULL )
	{	
		//printf ( "%s  %ld\n", tokens[i], strlen(tokens[i]));
		i++;		
		tokens[i] = strtok(NULL, s);
	}
	
	int n = i;
	float stack[n];
	int count = 0;
	float temp;
	
	for ( i = n-1; i >= 0; i-- )
	{
		if ( tokens[i][0] >= '0' && tokens[i][0] <= '9')
		{
			stack[count] = intmaker(tokens[i]);
			count++;
		}
		
		else if ( tokens[i][0] == '*' )
		{
			temp = stack[count-1] * stack[count-2];
			stack[count-1] = 0;
			stack[count-2] = temp;
			count--;
		}
		else if ( tokens[i][0] == '/' )
		{
			temp = stack[count-1] / stack[count-2];
			stack[count-1] = 0;
			stack[count-2] = temp;
			count--;
		}
		else if ( tokens[i][0] == '+' )
		{
			temp = stack[count-1] + stack[count-2];
			stack[count-1] = 0;
			stack[count-2] = temp;
			count--;
		}
		else if ( tokens[i][0] == '-' )
		{
			temp = stack[count-1] - stack[count-2];
			stack[count-1] = 0;
			stack[count-2] = temp;
			count--;
		}
	}
	return stack[0];
}

int main()
{
	char str[50];
	printf ( "\n\n\t Enter Prefix Expression ==> ");
	scanf ("%[^\n]",str);
	printf ( "\n\t Answer ==> %f \n\n", eval (str));
	return 0;
}
