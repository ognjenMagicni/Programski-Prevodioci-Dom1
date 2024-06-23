%{
    #include <stdio.h>
    #include <string.h>
    #include "parser.tab.h"
    int row  = 1;
    int column = 1;
%}


%%
"FUNCTION" {return T_FUNCTION;}
"PARAMETER" {return T_PARAMETER;}
"FUNCTIONEND" {return T_FUNCTIONEND;}
"RETURN" {return T_RETURN;}
"LET" { return T_LET; }
"IN" { return T_IN; }
"END" { return T_END; }
"SKIP" { return T_SKIP; }
"IF" { return T_IF; }
"THEN" { return T_THEN; }
"ELSE" { return T_ELSE; }
"FI" { return T_FI; }
"WHILE" { return T_WHILE; }
"DO" { return T_DO; }
"READ" { return T_READ; }
"WRITE" { return T_WRITE; }
"INT" { return T_INT; }
"DOUBLE" { return T_DOUBLE; }
"BOOL" { return T_BOOL; }
"STRING" { return T_STRING; }
"INTCONST" { return T_INTCONST; }
"DOUBLECONST" { return T_DOUBLECONST; }
"BOOLCONST" { return T_BOOLCONST; }
"STRCONST" { return T_STRCONST; }
"TRUE" {yylval.id = yytext;return T_BOOLCONST;}
"FALSE" {yylval.id = yytext;return T_BOOLCONST;}


[0-9]+ {   
    column+=strlen(yytext);
    if(strlen(yytext)>1){
        if(yytext[0]=='0'){
            printf("Greska: los decimalni broj '%s' na liniji %d i koloni %d\n",yytext,row,column);
            printf("0");
            exit(1);
        }
        else{
            yylval.i_num = atoi(yytext);
            return T_DEC;
            //printf("T_DEC(%s) ",yytext); 
            
            
        }

    }else{
        yylval.i_num = atoi(yytext);
        return T_DEC;
        //printf("T_DEC(%s) ",yytext);
    }
    }
(0x|0X)([0-9a-fA-F]*) {
    column+=strlen(yytext);
    if(strlen(yytext)==2){
        printf("Greska: los heksadecimalni broj '%s' na liniji %d i koloni %d\n",yytext,row,column);
        printf("0");
        exit(1);
    }
    else if(strlen(yytext)>3){
        if(yytext[2]=='0'){
            printf("Greska: los heksadecimalni broj '%s' na liniji %d i koloni %d\n",yytext,row,column);
            printf("0");
            exit(1);
        }
        else{
            //printf("T_HEX(%s) ",yytext);    
            return T_HEX;
        }
    }else{
        //printf("T_HEX(%s) ",yytext);
        return T_HEX;
    }
    }

[0-9]*"."[0-9]*((E|e)("+"|"-")?[0-9]*)? {
    column+=strlen(yytext);

    char* ptr = strchr(yytext,'.');
    int posDot = ptr-yytext;

    char* ptrE = strchr(yytext,'E');
    char* ptre = strchr(yytext,'e');

    if(posDot==0){
        printf("Greska: los double broj '%s' na liniji %d i koloni %d\n",yytext,row,column);
        printf("0");
        exit(1);
    }

    else if(posDot>1 && yytext[0]=='0'){
        printf("Greska: los double broj '%s' na liniji %d i koloni %d\n",yytext,row,column);
        printf("0");
        exit(1);
    }

    else if(ptrE!=NULL || ptre!=NULL){
        int posE = (ptrE!=NULL)? (ptrE-yytext):(ptre-yytext);
        if(strlen(yytext)-1==posE){
            printf("Greska: los double broj '%s' na liniji %d i koloni %d\n",yytext,row,column);
            printf("0");
            exit(1);
        }
        else{
            if(yytext[posE+1]=='+' || yytext[posE+1]=='-'){
                if(strlen(yytext)-1>posE+2 && yytext[posE+2]=='0'){
                    printf("Greska: los double broj '%s' na liniji %d i koloni %d\n",yytext,row,column);
                    printf("0");
                    exit(1);
                }
                else{
                    //printf("T_DOU(%s) ",yytext);
                    yylval.d_num = strtod(yytext,NULL);
                    return T_DOU;
                }
            }
            
            else{
                if(strlen(yytext)-1>posE+1 && yytext[posE+1]=='0'){
                    printf("Greska: los double broj '%s' na liniji %d i koloni %d\n",yytext,row,column);
                    printf("0");
                    exit(1);
                }
                else{
                    //printf("T_DOU(%s) ",yytext);
                    yylval.d_num = strtod(yytext,NULL);
                    return T_DOU;
                }
            }
        }
    }
    
    else{
        //printf("T_DOU(%s) ",yytext);
        yylval.d_num = strtod(yytext,NULL);
        return T_DOU;
    }
}

[0-9A-Za-z"_"]+ {
    column+=strlen(yytext);

    if(strlen(yytext)>31){
        printf("Greska: identeifikator na liniji %d i koloni %d '%s' je predug\n",row,column,yytext);
        printf("0");
        exit(1);
    }
    else if(yytext[0]=='_'){
        printf("Greska: identifikator na liniji %d i koloni %d '%s' ne moze da pocne sa _\n",row,column,yytext);
        printf("0");
        exit(1);
    }
    else{
        //printf("T_ID(%s) ",yytext);
        yylval.id = yytext;
        return T_ID;
    }
}

"+" { return T_PLUS; }
"-" { return T_MINUS; }
"*" { return T_STAR; }
"/" { return T_SLASH; }
"%" { return T_PERCENT; }
"<" { return T_LESS; }
"<=" { return T_LESSEQ; }
">" { return T_GREATER; }
">=" { return T_GREATEREQ; }
"=" { return T_ASSIGN; }
"==" { return T_EQ; }
"!=" { return T_NEQ; }
"&&" { return T_AND; }
"||" { return T_OR; }
"!" { return T_NOT; }
";" { return T_SEMICOLON; }
"," { return T_COMMA; }

"(" { return T_LPAREN; }
")" { return T_RPAREN; }

"//"(.)* {}
"/*"(.|(\n))*"*/" {}

\n { row++;column = 1; }
\r {}
\t {}
" " {column++;}


%%
