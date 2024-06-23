%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    void yyerror(const char* s);

    int identf = 0;
    

        struct ast{
            char* token;
            int id;
            int num;
            int type;
            struct ast** offspring; 
        };
    
    
    void init(struct ast** root){
        *root = malloc(sizeof(struct ast));
        (*root)->token = malloc(sizeof(strdup("root"))+1);
        strcpy((*root)->token,"root");
        (*root)->id = 0;
        (*root)->num = 0;
        (*root)->type = 0;
        (*root)->offspring = (struct ast**)malloc(10*sizeof(struct ast*));
        
    }
    void add(struct ast* parent, struct ast* child){
        parent->offspring[parent->num] = malloc(sizeof(*child));
        parent->offspring[parent->num] = child;
        parent->num = parent->num+1;
    }
    struct ast* createNode(char* token,int type){
        
        identf++;
        struct ast* node = malloc(sizeof(struct ast));
        node->token = malloc(sizeof(strdup(token))+1);
        strcpy(node->token,token);
        
        node->id = identf;
        node->num = 0;
        node->type = type;
        node->offspring = (struct ast**)malloc(10*sizeof(struct ast*));
        
        return node;
    }
    void printAST(struct ast* root){
        
        int n = root->num;
        printf("(%s, %d) -> (",root->token,root->id);
        int i=0;
        while(i<n){
            printf("%s, %d; ",root->offspring[i]->token,root->offspring[i]->id);
            i++;
        }
        printf(") \n" );
        i=0;
        while(i<n){
            printAST(root->offspring[i]);
            i++;
        }
    }
    struct ast* root;
    
    
    
    

%}

%start S

%union{
    double d_num;
    int i_num;
    float f_num;
    char* id;
    struct ast* tree;
}

%token <id> T_ID
%token <i_num>T_DEC
%token T_HEX
%token <d_num>T_DOU

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
%token <i_num> T_INTCONST
%token <d_num> T_DOUBLECONST
%token <id> T_BOOLCONST
%token <id> T_STRCONST

%token T_FUNCTION
%token T_PARAMETER
%token T_FUNCTIONEND
%token T_RETURN

%nonassoc T_ASSIGN
%left T_OR
%left T_AND
%left T_EQ T_NEQ
%nonassoc T_LESS T_LESSEQ T_GREATER T_GREATEREQ
%left T_PLUS T_MINUS
%left T_STAR T_SLASH T_MODULO
%left T_NOT

%type<tree> expression
%type<tree> type
%type<tree> constant
%type<tree> stat
%type<tree> command
%type<tree> declarations
%type<tree> ident_decl

%%

S: program 
;

program: T_LET declarations T_IN stat T_END {
        struct ast* tLet =  createNode("LET",0);
        struct ast* tIn =  createNode("IN",0);
        struct ast* tEnd =  createNode("END",0);
        struct ast* st = $4;

        add(root,tLet);
        add(root,$2);
        add(root,tIn);
        add(root,st);
        add(root,tEnd);
}
    |T_LET T_IN stat T_END{
        
        struct ast* tLet =  createNode("LET",0);
        struct ast* tIn =  createNode("IN",0);
        struct ast* tEnd =  createNode("END",0);
        struct ast* st = $3;


        add(root,tLet);
        add(root,tIn);
        add(root,st);
        add(root,tEnd);
    }
;


declarations :type ident_decl{
    
    struct ast* declaration = createNode("declar",0);

    add(declaration,$1);
    add(declaration,$2);

    $$ = declaration;
}
    |declarations type ident_decl{

    struct ast* declaration = createNode("declaration",0);

    add(declaration,$1);
    add(declaration,$2);
    add(declaration,$3);

    $$ = declaration;

};

ident_decl : T_ID{
    
    $$  = createNode($1,0);
}
    | ident_decl T_ID;




stat: stat command{
    struct ast* stat = createNode("stat",0);
    
    struct ast* command = $2;
    

    add(stat,$1);
    add(stat,command);
    $$ = stat;
}|{
    struct ast* lambda = createNode("lambda",0);
    $$ = lambda;
}
;


command :
     T_ID T_ASSIGN expression T_SEMICOLON {
        struct ast* id = createNode($1,0);
        struct ast* assign = createNode("=",0);
        struct ast* exp = $3;
        struct ast* sc = createNode(";",0);
        struct ast* command = createNode("command",0);
        add(command,id);
        add(command,assign);
        add(command,exp);
        add(command,sc);
    
        $$ = command;
     }
    | T_IF expression T_THEN command_sequence1 T_ELSE command_sequence1 T_FI {$$=createNode("prazno",0);}
    | T_WHILE expression T_DO command_sequence1 T_END                         {$$=createNode("prazno",0);}
    | T_READ T_ID T_SEMICOLON                                                   {$$=createNode("prazno",0);}
    | T_WRITE expression T_SEMICOLON                                            {$$=createNode("prazno",0);}
    | type T_FUNCTION T_ID T_PARAMETER declarations T_IN command_sequence T_RETURN expression T_SEMICOLON T_FUNCTIONEND   {$$=createNode("prazno",0);}
    | T_FUNCTION T_ID T_PARAMETER declarations T_IN command_sequence T_FUNCTIONEND {$$=createNode("prazno",0);};



stat1: stat1 command1|;

command1 : T_SKIP
    | T_ID T_ASSIGN expression T_SEMICOLON
    | T_IF expression T_THEN command_sequence1 T_ELSE command_sequence1 T_FI 
    | T_WHILE expression T_DO command_sequence1 T_END 
    | T_READ T_ID T_SEMICOLON
    | T_WRITE expression T_SEMICOLON
    | type T_FUNCTION T_ID T_PARAMETER declarations T_IN command_sequence T_RETURN expression T_SEMICOLON T_FUNCTIONEND
    | T_FUNCTION T_ID T_PARAMETER declarations T_IN command_sequence T_FUNCTIONEND;


command_sequence1 : stat1;
command_sequence: stat;

expression :
    expression T_ASSIGN expression
    | expression T_OR expression        { if( !($1->type==3 && $3->type==3) ){printf("01");exit(1);} $$=createNode("prazno",0);}
    | expression T_AND expression       {if( !($1->type==3 && $3->type==3) ){printf("02");exit(1);} $$=createNode("prazno",0);}
    | expression T_NEQ expression        {if($1->type!=$3->type){printf("03");exit(1);} $$=createNode("prazno",0);}
    | expression T_EQ expression         {if($1->type!=$3->type){printf("04");exit(1);} $$=createNode("prazno",0);}
    | expression T_GREATER expression   {if(  !(($1->type==1 || $1->type==2) && ($3->type==1 || $3->type==2)) ){printf("05");exit(1);} $$=createNode("prazno",0);}
    | expression T_LESSEQ expression    {if(  !(($1->type==1 || $1->type==2) && ($3->type==1 || $3->type==2)) ){printf("06");exit(1);} $$=createNode("prazno",0);}
    | expression T_GREATEREQ expression {if(  !(($1->type==1 || $1->type==2) && ($3->type==1 || $3->type==2)) ){printf("07");exit(1);} $$=createNode("prazno",0);}
    | expression T_LESS expression      {if(  !(($1->type==1 || $1->type==2) && ($3->type==1 || $3->type==2)) ){printf("08");exit(1);} $$=createNode("prazno",0);}

    | expression T_PLUS expression      {
        struct ast* p = createNode("+",0);
        
        if($1->type!=$3->type){
            printf("Can not add two different types /n0");exit(1);
            }
        
        struct ast* expF = createNode("exp",0);
        add(expF,($1));
        add(expF,p);
        add(expF,($3));

        $$ = expF;
    }
    | expression T_MINUS expression     {if($1->type != $3->type){printf("010");exit(1);} $$=createNode("prazno",0);}
    | expression T_STAR expression      {if($1->type != $3->type){printf("011");exit(1);} $$=createNode("prazno",0);}
    | expression T_SLASH expression     {if($1->type != $3->type){printf("012");exit(1);} $$=createNode("prazno",0);}
    | T_NOT expression                  {if($2->type != 3){printf("013");exit(1);} $$=createNode("prazno",0);}

    | T_LPAREN expression T_RPAREN  {$$=createNode("prazno",0);} 
    | constant{
        $$ = $1
    } 
    | T_ID {
        $$ = createNode($1,0);
    } 
    | T_ID T_PARAMETER ident_decl {$$ = createNode($1,0);}
;

constant : T_DEC {
    char num[32];
    sprintf(num,"%d",$1);
    $$ = createNode(num,1);
}
     | T_DOU {
        char num[32];
        sprintf(num,"%f",$1);
        $$ = createNode(num,2);
    }
     | T_BOOLCONST {$$ = createNode($1,3);}
     | T_STRCONST {$$ = createNode($1,4);};
type : T_INT {$$ = createNode("INT",0);}
 | T_DOUBLE {$$ = createNode("DOUBLE",0);}
 | T_BOOL {$$ = createNode("BOOL",0);}
 | T_STRING {$$ = createNode("STRING",0);};


%%

void yyerror(const char* s) { // poklapa se sa definicijom f-je u bisonu
    printf("%s",s);
    printf("0");
}

int main(){
    init(&root);
    int res = yyparse();
    if(res == 0)
        printf("1\n");
    printAST(root);
    
    
    return 0;
}

//stablo formata (token, id) -> (token,id; token,id)