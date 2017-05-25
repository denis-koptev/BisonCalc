#include "y_tab.h"
#include "calc_engine.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

FILE * fp;

int main()
{
	fp = fopen("code.txt", "rb");

	if (!fp)
	{
		printf("Error: input file was not opened");
		return 1;
	}

	yyparse();
	fclose(fp);
	return 0;
}

int yylex()
{
	char foo_token[256] = "";

	while (1)
	{
		char c = fgetc(fp);

		if (!isalpha(c) && strlen(foo_token) != 0)
		{
			ungetc(c, fp);
			return parse_my_token(foo_token);
		}

		if (isspace(c))
		{
			continue;
		}

		if (c == EOF)
		{
			return '$';
		}

		if (isdigit(c))
		{
			int val = c - '0';
			yylval.val = val * 1.0;
			return number;
		}
		else if (isalpha(c))
		{
			char s_c[2];
			s_c[0] = c;
			s_c[1] = '\0';
			strcat(foo_token, s_c);
		}
		else
		{
			return c;
		}
	}

	return '$';
}

int yyerror(char * str)
{
	printf("%s\n", str);

	return 0;
}