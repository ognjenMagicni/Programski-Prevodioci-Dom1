%{
    #include <stdio.h>
    #include <string.h>
    int row  = 1;
    int column = 1;
%}


%%
"LET" {printf("T_INT ");}
"IN" {printf("T_IN ");}
"END" {printf("T_END ");}
"SKIP" {printf("T_SKIP ");}
"IF" {printf("T_IF ");}
"THEN" {printf("T_THEN ");}
"ELSE" {printf("T_ELSE ");}
"FI" {printf("T_FI ");}
"WHILE" {printf("T_WHILE ");}
"DO" {printf("T_DO ");}
"READ" {printf("T_READ ");}
"WRITE" {printf("T_WRITE ");}
"INT" {printf("T_INT ");}
"DOUBLE" {printf("T_DOUBLE ");}
"BOOL" {printf("T_BOOL ");}
"STRING" {printf("T_STRING ");}
"INTCONST" {printf("T_INTCONST ");}
"DOUBLECONST" {printf("T_DOUBLECONST ");}
"BOOLCONST" {printf("T_BOOLCONST ");}
"STRCONST" {printf("T_STRCONST ");}

[0-9]+ {
    column+=strlen(yytext);
    if(strlen(yytext)>1){
        if(yytext[0]=='0')
            printf("Greska: los decimalni broj '%s' na liniji %d i koloni %d",yytext,row,column);
        else
            printf("T_DECN(%s) ",yytext);    
    }else{
        printf("T_DECN(%s) ",yytext);
    }
    }
(0x|0X)([0-9a-fA-F]*) {
    column+=strlen(yytext);
    if(strlen(yytext)==2)
        printf("Greska: los heksadecimalni broj '%s' na liniji %d i koloni %d",yytext,row,column);
    else if(strlen(yytext)>3){
        if(yytext[2]=='0')
            printf("Greska: los heksadecimalni broj '%s' na liniji %d i koloni %d",yytext,row,column);
        else
            printf("T_HEXN(%s) ",yytext);    
    }else{
        printf("T_HEXN(%s) ",yytext);
    }
    }

[0-9]*"."[0-9]*((E|e)("+"|"-")?[0-9]*)? {
    column+=strlen(yytext);

    char* ptr = strchr(yytext,'.');
    int posDot = ptr-yytext;

    char* ptrE = strchr(yytext,'E');
    char* ptre = strchr(yytext,'e');

    if(posDot==0)
        printf("Greska: los double broj '%s' na liniji %d i koloni %d",yytext,row,column);

    else if(posDot>1 && yytext[0]=='0')
        printf("Greska: los double broj '%s' na liniji %d i koloni %d",yytext,row,column);

    else if(ptrE!=NULL || ptre!=NULL){
        int posE = ptrE!=NULL? (ptrE-yytext):(ptre-yytext);
        if(strlen(yytext)-1==posE)
            printf("Greska: los double broj '%s' na liniji %d i koloni %d",yytext,row,column);
        /*else{
            posE = yytext[posE]=='+' || yytext[posE]=='-'?;
        }*/
    }
    
    else{
        printf("T_DOU(%s) ",yytext);
    }
}

[0-9A-Za-z"_"]+ {
    column+=strlen(yytext);

    if(strlen(yytext)>31){
        printf("Greska: identeifikator na liniji %d i koloni %d '%s' je predug",row,column,yytext);
    }
    else if(yytext[0]=='_')
        printf("Greska: identifikator na liniji %d i koloni %d '%s' ne moze da pocne sa _",row,column,yytext);
    else{
        printf("T_ID(%s) ",yytext);
    }
}

"+" { printf("T_+"); }
"-" { printf("T_-"); }
"*" { printf("T_*"); }
"/" { printf("T_/"); }
"%" { printf("T_%"); }
"<" { printf("T_<"); }
"<=" { printf("T_<="); }
">" { printf("T_>"); }
">=" { printf("T_>="); }
"=" { printf("T_="); }
"==" { printf("T_=="); }
"!=" { printf("T_!="); }
"&&" { printf("T_&&"); }
"||" { printf("T_||"); }
"!" { printf("T_!"); }
";" { printf("T_;"); }
"," { printf("T_,"); }

"(" { printf("T_("); }
")" { printf("T_)"); }



\n { row++;column = 1; }


. {column++;}


%%
