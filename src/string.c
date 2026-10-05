/*============================================================================

  string.c

  String handling functions 

  Copyright (c)2026 Kevin Boone, GPLv3.0

============================================================================*/

#include "string.h" 

/*============================================================================

  strcmp

============================================================================*/
int strcmp (const char *p1, const char *p2)
  {
  register const unsigned char *s1 = (const unsigned char *) p1;
  register const unsigned char *s2 = (const unsigned char *) p2;
  unsigned register char c1, c2;

  do
    {
    c1 = (unsigned char) *s1++;
    c2 = (unsigned char) *s2++;
    if (c1 == '\0')
      return c1 - c2;
    } while (c1 == c2);

  return c1 - c2;
  }

