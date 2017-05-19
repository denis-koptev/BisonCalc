%{

#define alloca malloc
#include "calc_engine.h"
#include <math.h>

%}

%union {
	double val;
    char * foo;
};

%type <val> S D INT
%token <val> number
%token <foo> fsin fcos ftg farctg fsqrt

%left '+' '-'
%left '*' '/'
%left UMINUS
%right '^'

%%

S:	D '$' {
		printf("Result: %f", $1);
		YYACCEPT;
	}

D	: INT { $$ = $1; }
	| INT '.' INT { $$ = parse_my_double($1, $3);}
	| D '+' D { $$ = $1 + $3; }
	| D '-' D { $$ = $1 - $3; }
	| '-' D %prec UMINUS { $$ = -$2; }
	| D '*' D { $$ = $1 * $3; }
	| D '/' D { $$ = $1 / $3; }
	| D '^' D { $$ = pow($1, $3); }
	| '(' D ')' { $$ = $2; }
	| '[' D ']' { $$ = $2; }
	| fsin '(' D ')' { $$ = sin($3); }
	| fcos '(' D ')' { $$ = cos($3); }
	| ftg '(' D ')' { $$ = tan($3); }
	| farctg '(' D ')' { $$ = atan($3); }
	| fsqrt '(' D ')' { $$ = sqrt($3); }

INT	: number { $$ = $1; }
	| INT number { $$ = $1*10 + $2; }
