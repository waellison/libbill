#include <libbill.h>

float clampf(float value, float min, float max) {
  return (value > max) ? max : (value < min) ? min : value;
}

double clampd(double value, double min, double max) {
  return (value > max) ? max : (value < min) ? min : value;
}

int clampi(int value, int min, int max) {
  return (value > max) ? max : (value < min) ? min : value;
}

long clampl(long value, long min, long max) {
  return (value > max) ? max : (value < min) ? min : value;
}

short clamps(short value, short min, short max) {
  return (value > max) ? max : (value < min) ? min : value;
}

long long clampll(long long value, long long min, long long max) {
  return (value > max) ? max : (value < min) ? min : value;
}

