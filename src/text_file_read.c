#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libbill.h>

/**
 * \brief Read a text file into a character string.
 *
 * This function blasts a text file into a character stream and returns
 * the stream as a pointer.  Caller frees it.
 *
 * @param path the path to read from
 * @return a string containing the contents of the file
 */
bstring *text_file_read(const char *path)
{
   FILE *handle;
   char *contents = NULL;
   bstring *retval;
   size_t size;

   newhandle(handle, path, "r");

   // how big is the file, portably
   fseek(handle, 0, SEEK_END);
   size = ftell(handle);
   rewind(handle);
   
   message("libbill: read text file %s from disk (%ud bytes)\n", path, size)

   // if there's a file, load it
   if(0 < size) {
      newptr(contents, char, size + 1);
      fread(contents, sizeof(char), size, handle);
      contents[size] = '\0';
   }

   fclose(handle);
   retval = bstring_create(contents);
   return retval;
}

