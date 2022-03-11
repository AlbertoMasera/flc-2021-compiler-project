/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     INT_VAL = 258,
     REAL_VAL = 259,
     BOOLEAN_VAL = 260,
     STRING_VAL = 261,
     ID = 262,
     PRINT = 263,
     BLOCK = 264,
     RETURN = 265,
     IF = 266,
     ELSE = 267,
     ELIF = 268,
     WHILE = 269,
     INT = 270,
     REAL = 271,
     BOOLEAN = 272,
     STRING = 273,
     LN = 274,
     LOG = 275,
     LOG10 = 276,
     SQRT = 277,
     GT = 278,
     LT = 279,
     GE = 280,
     LE = 281,
     EQ = 282,
     NE = 283,
     TAN = 284,
     COS = 285,
     SIN = 286,
     UMINUS = 287
   };
#endif
/* Tokens.  */
#define INT_VAL 258
#define REAL_VAL 259
#define BOOLEAN_VAL 260
#define STRING_VAL 261
#define ID 262
#define PRINT 263
#define BLOCK 264
#define RETURN 265
#define IF 266
#define ELSE 267
#define ELIF 268
#define WHILE 269
#define INT 270
#define REAL 271
#define BOOLEAN 272
#define STRING 273
#define LN 274
#define LOG 275
#define LOG10 276
#define SQRT 277
#define GT 278
#define LT 279
#define GE 280
#define LE 281
#define EQ 282
#define NE 283
#define TAN 284
#define COS 285
#define SIN 286
#define UMINUS 287




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 179 "calc-yacc.y"
{
        int int_value;
        double real_value;
        Boolean boolean_value;
        char *string_value;
        char *lexeme;
        Type type;
        StatementResult *statement_result;
        ExprResult *expr_result;
       }
/* Line 1529 of yacc.c.  */
#line 124 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

