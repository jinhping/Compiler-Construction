WHITESPACE [ \t]
NUM [0-9]+

%{

  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>

  #include "iloc.tab.hh"
  
  #include "code.h"

  int line_counter = 1;
 
  char token[256];

%}

%%

\[            {return OPEN_BRACKET;}
\]            {return CLOSE_BRACKET;}
\;            {return SEMICOLON;}
\,            {return COMMA;}
\=\>          {return ARROW;}
\-\>          {return ARROW;}

r{NUM}        {yylval.ival = atoi(&yytext[1]); return REGISTER;}
{NUM}         {(void) strcpy(token,yytext);
                yylval.ival = atoi(yytext); 
                return NUMBER;
              }
\-{NUM}       {(void) strcpy(token,yytext);
                yylval.ival = atoi(yytext); 
                return NUMBER;
              }

dis         {return DATA_INT;}
dcs         {return DATA_CHAR;}

[a-zA-Z0-9\_]+: {(void) strcpy(token,yytext); return TARGET;}

[a-zA-Z0-9\_]+  {
                  (void) strcpy(token,yytext);
				   
				   if (isOpcode(token)) {
						return OPCODE;
				   } else {
						return LABEL;
				   }

                }


\/\/[^\n]*  { /* Comment */}

[\n]          {line_counter++;}

{WHITESPACE}  {;}

%%

int yywrap()
{
  return 1;
}

