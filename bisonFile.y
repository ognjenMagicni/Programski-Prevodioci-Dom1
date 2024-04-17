%{
    #include <stdio.h>
    
%}

%start start
%token T_ID
%token T_DEC
%token T_HEX
%token T_DOU

%token T_PLUS
%token T_MINUS
%token T_MULTIPLY
%token T_DIVIDE
%token T_MODULO
%token T_BACKSLASH
%token T_LESS_THAN
%token T_LESS_THAN_OR_EQUAL
%token T_GREATER_THAN
%token T_GREATER_THAN_OR_EQUAL
%token T_ASSIGN
%token T_EQUAL
%token T_NOT_EQUAL
%token T_AND
%token T_OR
%token T_NOT
%token T_SEMICOLON
%token T_COMMA
%token T_PERIOD
%token T_LEFT_PAREN
%token T_RIGHT_PAREN

%token T_LET
%token T_IN
%token T_END
%token T_SKIP
%token T_IF
%token T_THEN
%token T_ELSE
%token T_FI
%token T_WHILE
%token T_DO
%token T_READ
%token T_WRITE
%token T_INT
%token T_DOUBLE
%token T_BOOL
%token T_STRING
%token T_INTCONST
%token T_DOUBLECONST
%token T_BOOLCONST
%token T_STRCONST