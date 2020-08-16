#if defined __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <GL/glut.h>
#endif
#include <stdbool.h>

int set_uniform_1b(unsigned shad, char *which, bool value)
{
  GLint uniform_location = glGetUniformLocation(shad, which);
  if(uniform_location != -1) glUniform1f(uniform_location, value);
  return uniform_location;  
}

int set_uniform_1f(unsigned shad, char *which, float value)
{
  GLint uniform_location = glGetUniformLocation(shad, which);
  if(uniform_location != -1) glUniform1f(uniform_location, value);
  return uniform_location;  
}

int set_uniform_2f(unsigned shad, char *which, float x, float y)
{
  GLint uniform_location = glGetUniformLocation(shad, which);
  if(uniform_location != -1) glUniform2f(uniform_location, x, y);
  return uniform_location;  
}

int set_uniform_2fv(unsigned shad, char *which, float* array)
{
  GLint uniform_location = glGetUniformLocation(shad, which);
  if(uniform_location != -1) glUniform2fv(uniform_location, 1, array);
  return uniform_location;  
}

int set_uniform_3f(unsigned shad, char *which, float x, float y, float z)
{
  GLint uniform_location = glGetUniformLocation(shad, which);
  if(uniform_location != -1) glUniform3f(uniform_location, x, y, z);
  return uniform_location;  
}

int set_uniform_3fv(unsigned shad, char *which, float* array)
{
  GLint uniform_location = glGetUniformLocation(shad, which);
  if(uniform_location != -1) glUniform3fv(uniform_location, 1, array);
  return uniform_location;  
}

int set_uniform_4f(unsigned shad, char *which, float x, float y, float z, float w) 
{
  GLint uniform_location = glGetUniformLocation(shad, which);
  if(uniform_location != -1) glUniform4f(uniform_location, x, y, z, w);
  return uniform_location;  
}

int set_uniform_4fv(unsigned shad, char *which, float* array)
{
  GLint uniform_location = glGetUniformLocation(shad, which);
  if(uniform_location != -1) glUniform4fv(uniform_location, 1, array);
  return uniform_location;  
}

int set_uniform_1i(unsigned shad, char *which, int value)
{
  GLint uniform_location = glGetUniformLocation(shad, which);
  if(uniform_location != -1) glUniform1i(uniform_location, value);
  return uniform_location;  
}

int set_uniform_2i(unsigned shad, char *which, int x, int y)
{
  GLint uniform_location = glGetUniformLocation(shad, which);
  if(uniform_location != -1) glUniform2i(uniform_location, x, y);
  return uniform_location;  
}

int set_uniform_2iv(unsigned shad, char *which, int* array)
{
  GLint uniform_location = glGetUniformLocation(shad, which);
  if(uniform_location != -1) glUniform2iv(uniform_location, 1, array);
  return uniform_location;  
}

int set_uniform_3i(unsigned shad, char *which, int x, int y, int z)
{
  GLint uniform_location = glGetUniformLocation(shad, which);
  if(uniform_location != -1) glUniform3i(uniform_location, x, y, z);
  return uniform_location;  
}

int set_uniform_3iv(unsigned shad, char *which, int* array)
{
  GLint uniform_location = glGetUniformLocation(shad, which);
  if(uniform_location != -1) glUniform3iv(uniform_location, 1, array);
  return uniform_location;  
}

int set_uniform_4i(unsigned shad, char *which, int x, int y, int z, int w) 
{
  GLint uniform_location = glGetUniformLocation(shad, which);
  if(uniform_location != -1) glUniform4i(uniform_location, x, y, z, w);
  return uniform_location;  
}

int set_uniform_4iv(unsigned shad, char *which, int* array)
{
  GLint uniform_location = glGetUniformLocation(shad, which);
  if(uniform_location != -1) glUniform4iv(uniform_location, 1, array);
  return uniform_location;  
}

