%{
    #include <stdio.h>
    #include <string.h>
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
    if(strlen(yytext)>1){
        if(yytext[0]=='0')
            printf("T_WN ");
        else
            printf("T_DECN(%s) ",yytext);    
    }else{
        printf("T_DECN(%s) ",yytext);
    }
    }
(0x|0X)([0-9a-fA-F]*) {
    if(strlen(yytext)==2)
        printf("T_WN ");
    else if(strlen(yytext)>3){
        if(yytext[2]=='0')
            printf("T_WN ");
        else
            printf("T_HEXN(%s) ",yytext);    
    }else{
        printf("T_HEXN(%s) ",yytext);
    }
    }

[0-9]+ "."[0-9]* {

}
. 


%%
