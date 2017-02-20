%{
	#include <stdio.h>
	#include <string.h>
	#define YYERROR_VERBOSE
	
	extern FILE *yyin;
	int lineNum = 1;
	int errorNum = 0;
	
	/* Called by yyparse on error. */
	void yyerror (char const *s)
	{

		errorNum += 1;
		fprintf (stderr, "Line %d: %s\n", lineNum, s);
	}
%}

%token AND
%token BY
%token CHAR
%token ELSE
%token FOR
%token IF
%token INT
%token NOT
%token OR
%token PROCEDURE
%token READ
%token THEN
%token TO
%token WHILE
%token WRITE


%token LT
%token LE
%token EQ
%token NE
%token GT
%token GE



%token NAME
%token NUMBER
%token CHARCONST

%%
Procedure: PROCEDURE NAME
			'{' Decls Stmts '}'

Decls: Decls Decl ';' 
	 | Decl ';' ;
Decl: Type SpecList;
Type : INT
	 | CHAR;
SpecList : SpecList ',' Spec
		 | Spec ;
Spec : NAME 
	 | NAME '[' Bounds ']' ;
Bounds : Bounds ',' Bound 
       | Bound ;
Bound : NUMBER ':' NUMBER ;

Stmts : Stmts Stmt 
	  | Stmt ;
Stmt : Reference '=' Expr ';' 
     | '{' Stmts '}' 
	 | WHILE '(' Bool ')' '{' Stmts '}' 
     | FOR NAME '=' Expr TO
          Expr BY Expr '{' Stmts '}' 
     | IF '(' Bool ')' THEN Stmt 
	 | IF '(' Bool ')' THEN WithElse ELSE Stmt 
	 | READ Reference ';' 
	 | WRITE Expr ';' 
	 | error ';' { yyerrok; } 
	 | '{' '}' { yyerror("Empty bracket");}; 	
WithElse : IF '(' Bool ')' THEN WithElse ELSE WithElse
 		 | Reference '=' Expr ';' 
     	 | '{' Stmts '}' 
	  	 | WHILE '(' Bool ')' '{' Stmts '}' 
     	 | FOR NAME '=' Expr TO Expr BY Expr '{' Stmts '}' 
		 | READ Reference ';' 
		 | WRITE Expr ';' ;



Bool : NOT OrTerm 
	 | OrTerm ;
OrTerm : OrTerm OR AndTerm 
	   | AndTerm ;
AndTerm : AndTerm AND RelExpr 
		| RelExpr ;
		
RelExpr : RelExpr LT Expr 
		| RelExpr LE Expr 
		| RelExpr EQ Expr 
		| RelExpr NE Expr 
		| RelExpr GE Expr 
		| RelExpr GT Expr 
		| Expr;
Expr : Expr '+' Term 
	 | Expr '-' Term
	 | Term ;
Term : Term '*' Factor 
	 | Term '/' Factor 
	 | Factor ;
Factor : '(' Expr ')' 
	   | Reference 
	   | NUMBER 
	   | CHARCONST ;
	   
Reference : NAME 
	   | NAME '[' Exprs ']';
	   
Exprs : Expr ',' Exprs 
	  | Expr
	  ;
	
%%

int yywrap(void) {
    return 1;
}

int main (int argc, char* argv[]) {
	if (argc == 2) {
		if (!strcmp("-h", argv[1])) {
			printf("-h : help\n");
		} else {
			FILE *fp;
			fp=fopen(argv[1], "r");
			yyin = fp;
		}
	} else {
		//read from std cin
		yyin = stdin;
	}
	yyparse();
	if (errorNum == 0) {
		printf("Parse Successfully\n");
	} else {
		printf("Total errors: %d\n", errorNum);
	}
	return 0;
}