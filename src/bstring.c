#include <libbill.h>
#include <stdlib.h>
#define __USE_BSD
#include <string.h>

bstring *bstring_create(const char *contents) {
  bstring *mystring = (bstring *) malloc(sizeof(bstring));
  mystring->contents = (char *) strdup(contents);
  mystring->length = strlen(contents);
  return mystring;
}

void bstring_delete(bstring *deleteme) {
  free(deleteme->contents);
  free(deleteme);
}

