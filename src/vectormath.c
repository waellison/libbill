/**
 * \file vectormath.c
 *
 * The vector math component of libbill enables the programmer to perform simple
 * manipulations on three-dimensional vectors.  The assumptions include that the
 * programmer knows the math behind these functions (or at least knows that
 * math's applicability) and that the vectors he wishes to use are
 * 3-dimensional.
 *
 * Every bvec3 returned by functions in this library must be freed by the user.
 * This will be fixed in a future release.
 *
 * \author William Ellison
 * \version Alpha
 * \date 2011-04-06
 */

#include <libbill.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h> 

/**
 * \brief Create a 3-dimensional vector and initialize it to the values
 * given as parameters; that is, \f$\mathbf{u} = \lbrack x, y, z \rbrack\f$.
 * @param x the x value of the vector
 * @param y the y value of the vector
 * @param z the z value of the vector
 * @return a new vector object with the values given
 */
bvec3 *make_bvec3(float x, float y, float z) {
  bvec3 *vector;
  newptr(vector, bvec3, 1);
  vector->x = x;
  vector->y = y;
  vector->z = z;
  return vector;
}

/**
 * \brief Create a 3-dimensional vector and initialize it to the values
 * given in the parameter array; that is, \f$\mathbf{u} =
 * \lbrack v_1, v_2, v_3 \rbrack\f$.
 *
 * @param v the array to use
 * @return a new vector object with the values given
 */
bvec3 *make_bvec3v(float* v) {
  bvec3 *vector;
  newptr(vector, bvec3, 1);
  vector->x = v[0];
  vector->y = v[1];
  vector->z = v[2];
  return vector;
}

/**
 * \brief Scale a vector via scalar multiplication.
 *
 * This is the standard linear algebra operation where \f$ k\mathbf{u} =
 * \lbrack ku_x, ku_y, ku_z \rbrack\f$.
 *
 * @param u a vector that the user wishes to scale
 * @param k a scalar value to be used for the scalar multiplication
 * @return a new vector with the scaled values as its components
 */
bvec3 *vscale(bvec3 *u, float k) {
  bvec3 *w;
  w = make_bvec3(k * u->x, k * u->y, k * u->z);
  return w;
}

/**
 * \brief Add two vectors component-wise.
 *
 * The result is \f$\mathbf{u} + \mathbf{v} = \lbrack u_x + v_x, u_y +
 * v_y, u_z + v_z \rbrack\f$.
 *
 * @param u the first vector to add
 * @param v the second vector to add
 * @return a new vector with the sum of the two parameters as its values
 */
bvec3 *vadd(bvec3 *u, bvec3 *v) {
  bvec3 *w;
  w = make_bvec3(u->x + v->x, u->y + v->y, u->z + v->z);
  return w;
}

/**
 * \brief Subtract two vectors component-wise.
 *
 * The result is \f$\mathbf{u} - \mathbf{v} = \lbrack u_x - v_x, u_y -
 * v_y, u_z - v_z \rbrack\f$.
 *
 * @param u the first vector to subtract
 * @param v the second vector to subtract
 * @return a new vector with the difference of the two parameters as its values
 */
bvec3 *vsub(bvec3 *u, bvec3 *v) {
  bvec3 *w;
  w = make_bvec3(u->x - v->x, u->y - v->y, u->z - v->z);
  return w;
}

/**
 * \brief Compute the dot product of two three-dimensional vectors.
 *
 * This is the standard dot product from linear algebra where
 * \f[ \mathbf{u} \cdot \mathbf{v} = \sum_{i=1}^n u_iv_i \f]
 * As in linear algebra, this can be interpreted as the norm of each vector
 * multiplied by the cosine of the angle between the vectors; that is,
 * \f[ \mathbf{u} \cdot \mathbf{v} = ||\mathbf{u}|| ||\mathbf{v}||
 * \cos{\theta}\f]
 * where \f$\theta\f$ is the angle between the vectors.
 * 
 * @param v1 the first vector
 * @param v2 the second vector
 * @return the dot product of the vectors
 */
float dot(bvec3 *v1, bvec3 *v2) {
  float dprod = 0;
  dprod += v1->x * v2->x;
  dprod += v1->y * v2->y;
  dprod += v1->z * v2->z;
  return dprod;
}

/**
 * \brief Compute the cross product of two vectors.
 *
 * The function computes the cross product of two vectors and returns
 * the result vector.  The function assumes a right-hand coordinate system.
 * If operating in a left-hand coordinate system for some bizarre reason,
 * the result can be scaled by -1.
 *
 * @param u the first vector
 * @param v the second vector
 * @return the result of the cross product multiplication
 */
bvec3 *cprod(bvec3 *u, bvec3 *v) {
  bvec3 *result;
  result = make_bvec3(u->y * v->z - u->z * v->y,
                      u->z * v->x - u->x * v->z,
                      u->x * v->y - u->y * v->x);
  return result;
}

/**
 * \brief Compute the norm of a vector.
 *
 * The function calculates the norm of a vector and returns it,
 * according to the formula \f$\sqrt{u_x^2 + u_y^2 + u_z^2}\f$.
 * @param u the vector whose norm is to be calculated
 * @return the norm of the vector
 */
float norm(bvec3 *u) {
  return sqrtf(powf(u->x, 2) + powf(u->y, 2) + powf(u->z, 2));
}

/**
 * \brief Normalize a vector.
 *
 * The function computes the norm of the vector and then scales the vector by
 * the norm's reciprocal in order to compute the normalized vector.  In
 * mathematical terms, we compute \f$\frac{1}{||\mathbf{u}||} \mathbf{u}\f$.
 *
 * @param u the vector to normalize
 * @return the normalized vector
 */
bvec3 *normalize(bvec3 *u) {
  float usize = norm(u);
  bvec3 *result;
  result = vscale(u, 1. / usize);
  return result;
}
