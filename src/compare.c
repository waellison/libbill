#include <libbill.h>

int comparef(const void *f1, const void *f2) {
  float *n1, *n2;
  n1 = (float*) f1;
  n2 = (float*) f2;
  if(*n1 < *n2)
    return -1;
  if(*n1 > *n2)
    return 1;
  return 0;
}

int comparec(const void *f1, const void *f2) {
  char *n1, *n2;
  n1 = (char*) f1;
  n2 = (char*) f2;
  if(*n1 < *n2)
    return -1;
  if(*n1 > *n2)
    return 1;
  return 0;
}

int comparei(const void *f1, const void *f2) {
  int *n1, *n2;
  n1 = (int*) f1;
  n2 = (int*) f2;
  if(*n1 < *n2)
    return -1;
  if(*n1 > *n2)
    return 1;
  return 0;
}

int compares(const void *f1, const void *f2) {
  short *n1, *n2;
  n1 = (short*) f1;
  n2 = (short*) f2;
  if(*n1 < *n2)
    return -1;
  if(*n1 > *n2)
    return 1;
  return 0;
}

int comparel(const void *f1, const void *f2) {
  long *n1, *n2;
  n1 = (long*) f1;
  n2 = (long*) f2;
  if(*n1 < *n2)
    return -1;
  if(*n1 > *n2)
    return 1;
  return 0;
}

int comparell(const void *f1, const void *f2) {
  long long *n1, *n2;
  n1 = (long long*) f1;
  n2 = (long long*) f2;
  if(*n1 < *n2)
    return -1;
  if(*n1 > *n2)
    return 1;
  return 0;
}

int compared(const void *f1, const void *f2) {
  double *n1, *n2;
  n1 = (double*) f1;
  n2 = (double*) f2;
  if(*n1 < *n2)
    return -1;
  if(*n1 > *n2)
    return 1;
  return 0;
}

int compareld(const void *f1, const void *f2) {
  long double *n1, *n2;
  n1 = (long double*) f1;
  n2 = (long double*) f2;
  if(*n1 < *n2)
    return -1;
  if(*n1 > *n2)
    return 1;
  return 0;
}

int compareu(const void *f1, const void *f2) {
  unsigned int *n1, *n2;
  n1 = (unsigned int*) f1;
  n2 = (unsigned int*) f2;
  if(*n1 < *n2)
    return -1;
  if(*n1 > *n2)
    return 1;
  return 0;
}

int compareul(const void *f1, const void *f2) {
  unsigned long *n1, *n2;
  n1 = (unsigned long*) f1;
  n2 = (unsigned long*) f2;
  if(*n1 < *n2)
    return -1;
  if(*n1 > *n2)
    return 1;
  return 0;
}