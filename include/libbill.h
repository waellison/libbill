/**
 * \file libbill.h
 *
 * Libbill is a personally written library designed to do functionality that I
 * deem useful.  These functionalities include the following:
 *
 * - Debug output handling.
 * - Vector math with 3D vectors.
 * - Comparison functions for use with qsort and bsearch.
 * - Implementations of the clamp function.
 * - Facilities for setting the values of OpenGL Shading Language uniform
 *   variables.
 * - Slightly friendlier strings.
 * - Facilities for preprocessing small input files to remove comments.
 *
 * The library is designed to be initialized prior to use and will eventually
 * clean up all of the memory associated with it at exit.
 * 
 * \author Bill Ellison
 * \version Alpha
 * \date 2011-04-06
 */
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _LIBBILL_H_
#define _LIBBILL_H_

  typedef struct _bvec3 {
    float x, y, z;
  } bvec3;

  typedef struct _bstring {
    char * contents;
    unsigned int length;
  } bstring;

//! @file libbill.c
void message(const char *fmt, ...);
//! @file libbill.c
void libbill_init();
//! @file libbill.c
void libbill_set_no_debug();
//! @file libbill.c
void libbill_set_debug();
//! @file libbill.c
void libbill_set_debug_output(const char *);
//! @file libbill.c
void libbill_cleanup();

//! @file text_file_preprocess.c
bstring *text_file_preprocess(const char *file);
//! @file text_file_read.c
bstring *text_file_read(const char *file);

//! @file compare.c
int fcompare(const void *, const void *);
//! @file compare.c
int dcompare(const void *, const void *);
//! @file compare.c
int icompare(const void *, const void *);
//! @file compare.c
int ccompare(const void *, const void *);
//! @file compare.c
int llcompare(const void *, const void *);
//! @file compare.c
int scompare(const void *, const void *);
//! @file compare.c
int lcompare(const void *, const void *);

//! @file clamp.c
float     clampf(float value, float min, float max);
//! @file clamp.c
double    clampd(double value, double min, double max);
//! @file clamp.c
int       clampi(int value, int min, int max);
//! @file clamp.c
long long clampll(long long value, long long min, long long max);
//! @file clamp.c
short     clamps(short value, short min, short max);
//! @file clamp.c
long      clampl(long value, long min, long max);

//! @file vectormath.c
bvec3 *make_bvec3(float, float, float);
//! @file vectormath.c
bvec3 *make_bvec3v(float *);
//! @file vectormath.c
float dot(bvec3*, bvec3*);
//! @file vectormath.c
bvec3 *cprod(bvec3*, bvec3*);
//! @file vectormath.c
float norm(bvec3*);
//! @file vectormath.c
bvec3 *normalize(bvec3*);
//! @file vectormath.c
bvec3 *vadd(bvec3 *, bvec3 *);
//! @file vectormath.c
bvec3 *vsub(bvec3 *, bvec3 *);
//! @file vectormath.c
bvec3 *vscale(bvec3 *, float);

//! @file uniform_ops.c
int set_uniform_1b(unsigned, char *, bool);
//! @file uniform_ops.c
int set_uniform_1f(unsigned, char *, float);
//! @file uniform_ops.c
int set_uniform_2f(unsigned, char *, float, float);
//! @file uniform_ops.c
int set_uniform_2fv(unsigned, char *, float *);
//! @file uniform_ops.c
int set_uniform_3f(unsigned, char *, float, float, float);
//! @file uniform_ops.c
int set_uniform_3fv(unsigned, char *, float *);
//! @file uniform_ops.c
int set_uniform_4f(unsigned, char *, float, float, float, float);
//! @file uniform_ops.c
int set_uniform_4fv(unsigned, char *, float *);
//! @file uniform_ops.c
int set_uniform_1i(unsigned, char *, int);
//! @file uniform_ops.c
int set_uniform_2i(unsigned, char *, int, int);
//! @file uniform_ops.c
int set_uniform_2iv(unsigned, char *, int *);
//! @file uniform_ops.c
int set_uniform_3i(unsigned, char *, int, int, int);
//! @file uniform_ops.c
int set_uniform_3iv(unsigned, char *, int *);
//! @file uniform_ops.c
int set_uniform_4i(unsigned, char *, int, int, int, int);
//! @file uniform_ops.c
int set_uniform_4iv(unsigned, char *, int *);

//! @file bstring.c
bstring *bstring_create(const char *);
//! @file bstring.c
void bstring_delete(bstring *);

#define newptr(variable, type, amount) \
   variable = (type*) malloc(sizeof(type) * amount);	\
   if(variable == NULL) { \
     perror("__func__"); \
     exit(EXIT_FAILURE); \
   }

#define newhandle(variable, where, mode)		\
   variable = fopen(where, mode); \
   if(variable == NULL) { \
     perror("__func__"); \
     exit(EXIT_FAILURE); \
   }

#define BSTR(the_bstring) thestring->contents

#ifdef __cplusplus
}
#endif

#endif /* defined _LIBBILL_H_ */

