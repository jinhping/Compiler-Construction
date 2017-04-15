%{
  #define YYERROR_VERBOSE 

  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>


  extern int yylex(void);
  char token[256];

  #define MAX_ERROR_MESSAGE_LENGTH 100


  extern char yytext[];

  extern int line_counter;

  /* This function must be defined */
  void yyerror(const char*);

  /* If an error is encountered during parsing this is changed to 1 */
  int error_found = 0;


  /* address for data initializations */
  int Start;

%}


%token OPEN_BRACKET
%token CLOSE_BRACKET
%token SEMICOLON
%token COMMA
%token ARROW
%token OPCODE
%token DOUTPUT
%token REGISTER
%token NUMBER
%token LABEL
%token TARGET

%token DATA_CHAR
%token DATA_INT



%start iloc_program



%% /* Beginning of rules */

iloc_program	: instruction_list
				{
				
				}
                | data_defs instruction_list
                {
		  
				}
                ;

instruction_list	: instruction
					{
		
					}
					| label_def instruction
					{
		
					}
					| instruction_list instruction
					{
	
					}
					| instruction_list label_def instruction
					{
	
					}
					;

instruction		: operation
                {
		 
				}
               // | OPEN_BRACKET operation_list CLOSE_BRACKET
             //   {
		
			//	}
                ;



operation   : //the_opcode operand_list ARROW operand_list
          //  {

			//}
          //   the_opcode operand_list
        //    {
	
		//	}
         //   | the_opcode ARROW operand_list
         //   {

		//	}
			 the_opcode
            {
	
			}
            ;

the_opcode  : OPCODE
            {

			}
            ;


reg     : REGISTER
        {
		  
		}
        ;

const   : NUMBER
        {
		 
		}
		;

lbl     : LABEL
        {
		   
		}
        ;

label_def   : TARGET
            {
			
			}
            ;


data_defs   : data_defs data_def
            | data_def
            ;

data_def    : DATA_CHAR addr listofchar {  }
            | DATA_INT  addr listofint  { }
            ;

listofchar  : listofchar charinit
            | charinit  {  }
            ;

listofint   : listofint intinit
            | intinit
            ;

charinit  	:  LABEL {}
			;

intinit   :  NUMBER {}
          ;

addr    :  NUMBER {}
        ;          

%% /* Support Code */
	
void yyerror(const char* s)
{
  (void) fprintf(stderr, "Line %d: %s\n", line_counter, s);
  error_found = 1;
}

int main () {
	
	return 0;
}