#include "calc_engine.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "y_tab.h"

double parse_my_double(double pre, double post)
{
	char * s_post = (char *)malloc(256);
	itoa((int)post, s_post, 10);
	double double_result = pre + post / pow(10, strlen(s_post));
	return double_result;
}

int parse_my_token(char * token)
{
	if (strcmp(token, "sin") == 0)
	{
		return fsin;
	}
	else if (strcmp(token, "cos") == 0)
	{
		return fcos;
	}
	else if (strcmp(token, "tg") == 0)
	{
		return ftg;
	}
	else if (strcmp(token, "arctg") == 0)
	{
		return farctg;
	}
	else if (strcmp(token, "sqrt") == 0)
	{
		return fsqrt;
	}
	else
	{
		return 0;
	}
}