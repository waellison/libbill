#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <libbill.h>

static bool debugp;
static FILE *debug_out;

void libbill_init()
{
   atexit(libbill_cleanup);
   debugp = true;
   debug_out = stderr;
}

void libbill_set_no_debug() {
  debugp = false;
}

void libbill_set_debug() {
  debugp = true;
  message("libbill: set debug mode to on\n");
}

void libbill_set_debug_output(const char *path) {
  message("libbill: setting debug output to: %s\n", path);
  newhandle(debug_out, path, "a");
}

// For a given format string (printf-style) and argument list, print them out.
void message(const char *fmt, ...)
{
  if(!debugp) return;
  
  va_list ap;
  va_start(ap, fmt);
  vfprintf(debug_out, fmt, ap);
  va_end(ap)
}

// Clean up all the crud from the library.
void libbill_cleanup() {
  if(debug_out != stderr)
    fclose(debug_out);
}

