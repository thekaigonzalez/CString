// Copyright 2019-2023 Kai D. Gonzalez

#include "string.h"
#include <stdio.h>

void
str_add_char (String *_st, char _ns)
{
  _st->__ms[_st->__p] = _ns;
  _st->__ms[(_st->__p) + 1] = '\0';
  _st->__p++;
}

void
str_init (String *_st)
{
  _st->__ms = malloc (MAX_STRING);
  _st->__p = 0;
}

void
str_free (String *_st)
{
  free (_st->__ms);
  _st->__p = -1;
}

char **
str_split (String *s, char _SEP)
{
  char *_splits[MAX_SPLITS];
  char *temp = malloc (MAX_STRING);
  int temp_index = 0;
  int _splz = 0;

  for (int i = 0; i < str_length (s); ++i)
    {
      if (str_at (s, i) == _SEP)
        {
        save:
          _splits[_splz] = temp;
          _splz++;

          temp = malloc (MAX_STRING);
          temp_index = 0;
        }
      else
        {
          temp[temp_index] = str_at (s, i);
          temp_index++;
        }
    }
  if (temp_index > 0)
    {
      _splits[_splz] = temp;
      _splz++;
    }

  char **spl = _splits;

  return spl;
}

char
str_at (String *s, int _g)
{
  if (_g < str_length (s))
    {
      return s->__ms[_g];
    }
}

int
str_length (String *_st)
{
  return _st->__p;
}

char *
str_get (String *_s)
{
  return _s->__ms;
}
