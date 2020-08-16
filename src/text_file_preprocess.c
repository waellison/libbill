#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <string.h>
#include <libbill.h>

/**
 * \brief Preprocess a text file, removing commented lines from the file.
 *
 * Maximal line length is 1024 characters.  This function removes blank
 * lines and commented lines with a #.
 *
 * The only limitation is that multicharacter comment characters don't
 * work and end-of-line comments aren't handled.
 * @param file the file's path name to read from
 * @return A character stream with the preprocessed file in it.  The caller is
 * responsible for freeing the memory associated with the stream.
 */
bstring *text_file_preprocess(const char *file)
{
  char *contents = NULL, *line;
  size_t size, skipped = 0, lines = 0, offset = 0;
  bstring *retval;
  FILE *handle;

  handle = fopen(file, "r");
  if(handle == NULL)
    return NULL;

  newptr(line, char, 1024);

  // how big is the file, portably
  fseek(handle, 0, SEEK_END);
  size = ftell(handle);
  rewind(handle);
  
  message("read text file %s from disk (%ud bytes), for preprocessing\n", path, size)

  if(size > 0) {
    newptr(contents, char, size + 1);
    memset(contents, 0, size + 1);

    for(;;) {
      memset(line, 0, 1024);
      char *ptr = fgets(line, 1024, handle);

      if(ptr != NULL) {
        int len = strlen(line);
        ++lines;
        // if the line starts with a comment or is empty, don't load it
        // otherwise, do load it
        switch(line[0]) {
          case '#':
          case ';':
          case '\n':
            ++skipped;
            break;
          default:
            // the following line is bad and i should feel bad
            strncat(contents, line, len);
            offset += len;
            break;
        }
      } else break;
    }
    contents[offset+1] = '\0';
  }
  retval = bstring_create(contents);
  fclose(handle);
  free(line);
  return retval;
}

