%{
 	#include "demo.tab.h"
 	extern int lineNum;
	
%}

%%
"and" {return AND;}
"by"  {return BY;}
"char" {return CHAR;}
"else" {return ELSE;}
"for" {return FOR ;}
"if" {return IF;}
"int" {return INT;}
"not" {return NOT;}
"or" {return OR;}
"procedure" {return PROCEDURE;}
"read" {return READ;}
"then" {return THEN;}
"to" {return TO;}
"while" {return WHILE;}
"write" {return WRITE;}

"+"  {return '+';}
"-"	{return '-';}
"*" {return '*';}
"/" {return '/';}

"<" {return LT;}
"<=" {return LE;}
"==" {return EQ;}
"!=" {return NE;}
">" {return GT;}
">=" {return GE;}

":" {return ':';}
";"	{return ';';}
"," {return ',';}
"=" {return '=';}
"{" {return '{';}
"}" {return '}';}
"[" {return '[';}
"]" {return ']';}
"(" {return '(';}
")" {return ')';}

[A-Za-z][A-Za-z0-9]* {return NAME;}
[0-9][0-9]*  {return NUMBER;}
'([^'\\\n]|\\.)'  {return CHARCONST;}
"//".*  ;
[ \t] 	{;}
. {}
[\n] {lineNum++; }
%%