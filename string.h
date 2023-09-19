// Copyright 2019-2023 Kai D. Gonzalez

/*
C strings - simple string implementation
fast and reliable
*/

#include <stdlib.h>

#define MAX_STRING 128
#define MAX_SPLITS 64

/* helper function */
#define str_iskilled(s) (str_length (&s) == -1)

typedef struct Str
{
  char *__ms;    /*internal string*/
  int __p;       /*string array index*/
  int __is_init; /* is initialized (1 is true 0 is false)*/
} String;

// initialize a string
void str_init (String *);

// add a character to a string
void str_add_char (String *, char _ns);

// return the string length
int str_length (String *);

// get string
char *str_get (String *);

// remove string
void str_free (String *);

// split string
char **str_split (String *, char _SEP);

// get character at string
char str_at (String *, int);
