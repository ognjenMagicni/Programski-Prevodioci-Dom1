
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_ID = 258,
     T_DEC = 259,
     T_HEX = 260,
     T_DOU = 261,
     T_PLUS = 262,
     T_MINUS = 263,
     T_STAR = 264,
     T_SLASH = 265,
     T_PERCENT = 266,
     T_LESS = 267,
     T_LESSEQ = 268,
     T_GREATER = 269,
     T_GREATEREQ = 270,
     T_ASSIGN = 271,
     T_EQ = 272,
     T_NEQ = 273,
     T_AND = 274,
     T_OR = 275,
     T_NOT = 276,
     T_SEMICOLON = 277,
     T_COMMA = 278,
     T_LPAREN = 279,
     T_RPAREN = 280,
     T_LET = 281,
     T_IN = 282,
     T_END = 283,
     T_SKIP = 284,
     T_IF = 285,
     T_THEN = 286,
     T_ELSE = 287,
     T_FI = 288,
     T_WHILE = 289,
     T_DO = 290,
     T_READ = 291,
     T_WRITE = 292,
     T_INT = 293,
     T_DOUBLE = 294,
     T_BOOL = 295,
     T_STRING = 296,
     T_INTCONST = 297,
     T_DOUBLECONST = 298,
     T_BOOLCONST = 299,
     T_STRCONST = 300,
     T_MODULO = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 62 "bisonFile.y"

    double d_num;
    int i_num;
    float f_num;
    char* id;



/* Line 1676 of yacc.c  */
#line 107 "bisonFile.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


