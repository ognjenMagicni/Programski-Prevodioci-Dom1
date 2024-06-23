%{
    #include <stdio.h>
    void yyerror(const char* s);
%}

%start S
%token T_ID
%token T_DEC
%token T_HEX
%token T_DOU

%token T_PLUS
%token T_MINUS
%token T_STAR
%token T_SLASH
%token T_PERCENT
%token T_LESS
%token T_LESSEQ
%token T_GREATER
%token T_GREATEREQ
%token T_ASSIGN
%token T_EQ
%token T_NEQ
%token T_AND
%token T_OR
%token T_NOT
%token T_SEMICOLON
%token T_COMMA
%token T_LPAREN
%token T_RPAREN

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

%nonassoc T_ASSIGN
%left T_OR
%left T_AND
%left T_EQ T_NEQ
%nonassoc T_LESS T_LESSEQ T_GREATER T_GREATEREQ
%left T_PLUS T_MINUS
%left T_STAR T_SLASH T_MODULO
%left T_NOT

%union{
    double d_num;
    int i_num;
    float f_num;
    char* id;
}

%%
S: program 
;

program: T_LET declarations T_IN stat T_END 
    |T_LET T_IN stat T_END
;


declarations :type ident_decl
    |declarations type ident_decl;

ident_decl : T_ID
    | ident_decl T_ID;

/*
    | id_seq T_ID
;
id_seq : id_seq T_ID;*/


stat: stat command|
;

//svako pojavljivanje command se mijenja sa command_sequence
command : T_SKIP;
    | T_ID T_ASSIGN expression ;
    | T_IF expression T_THEN command_sequence T_ELSE command_sequence T_FI ;
    | T_WHILE expression T_DO command_sequence T_END ;
    | T_READ T_ID;
    | T_WRITE expression ;

command_sequence : stat;


expression :
    expression T_ASSIGN expression
    | expression T_OR expression
    | expression T_AND expression
    |expression T_NEQ expression 
    |expression T_EQ expression 
    | expression T_GREATER expression
    | expression T_LESSEQ expression
    | expression T_GREATEREQ expression
    | expression T_LESS expression
    
    | expression T_PLUS expression | expression T_MINUS expression
    | expression T_STAR expression | expression T_SLASH expression
    | T_NOT expression
    | T_LPAREN expression T_RPAREN
    | constant | T_ID 
   
;
constant : T_DEC
     | T_DOU | T_BOOLCONST | T_STRCONST;
type : T_INT | T_DOUBLE | T_BOOL | T_STRING;

%%

void yyerror(const char* s) { // poklapa se sa definicijom f-je u bisonu
    printf("0");
}

int main(){
    int res = yyparse();
    if(res == 0)
        printf("1");
    
    
    return 0;
}