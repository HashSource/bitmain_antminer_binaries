
double fabs(double __x)

{
  double x_local;
  
  if ((int)((uint)(__x < 0.0) << 0x1f) < 0) {
    __x = -__x;
  }
  return __x;
}

