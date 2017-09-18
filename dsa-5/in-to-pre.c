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

int precedence ( char a, char b)
{
	if ( b == '(' )
		return 0;
	if ((a == '/') || ((a == '*')&&(b!='/')) || (( a == '+' )&&((b=='-')||(b=='+'))))
		return 1;
	return 0;
}

char* in_to_post (char* str)
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
	
	int n = i, p_count = 0, s_count = 0;
	char stack[n][20];
	char post[n][20];

	for ( i = n-1; i >= 0; i-- )
	{
		if ( tokens[i][0] == '(' )
			strcpy(stack[s_count++],tokens[i]);


		else if (tokens[i][0] == '+' || tokens[i][0] == '*' || tokens[i][0] == '-' || tokens[i][0] == '/')
		{	
			while (precedence(tokens[i][0], stack[s_count-1][0]))
			{
				strcpy(post[p_count++],stack[s_count-1]);
				s_count--;
			}
			strcpy(stack[s_count++],tokens[i]);
		}
		else if ( tokens[i][0] >= '0' && tokens[i][0] <= '9')
		{
			strcpy(post[p_count++],tokens[i]);
		}
		else if ( tokens[i][0] == ')')
		{
			while ( stack[s_count-1][0] != '(' )
			{
				strcpy(post[p_count++],stack[s_count-1]);
				s_count--;
			}
			stack[s_count-1][0] = '\0';
			s_count --;
		}
	}	
	printf ( "\n\n");
	char ans[n*21];
	i = 0;
	sprintf ( ans, "%s", post[i]);
	for ( i = 1; i < p_count; i++ )
	{
		sprintf ( ans, "%s %s", ans, post[i]);
	}
	printf ( "\n\t The postfix expression ==> %s\n", ans );
	
}

int main()
{
	char str[50];
	printf ( "\n\n\t Enter Infix Expression ==> ");
	scanf ("%[^\n]",str);
	in_to_post(str);
	return 0;
}
