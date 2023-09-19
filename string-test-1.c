// Copyright 2019-2023 Kai D. Gonzalez

#include "string.h"
#include <assert.h>
#include <stdio.h>

int
main ()
{
  String s;
  str_init (&s);

  str_add_char (&s, 'a');
  str_add_char (&s, '-');
  str_add_char (&s, 'c');

  char **_arra = str_split (&s, '-');

  printf ("first split  (by -): %s\n", _arra[0]);
  printf ("second split (by -): %s\n", _arra[1]);

  assert (str_length (&s) == 3);

  assert (str_at (&s, 2) == 'c');

  assert (*_arra[0] == 'a' && *_arra[1] == 'c');

  str_free (&s);

  printf ("TESTS 1 & 2 & 3 PASSED! :)\n");
}
