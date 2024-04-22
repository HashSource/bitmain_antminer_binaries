
/* WARNING: Variable defined which should be unmapped: interval-local */

void decay_time(double *f,double fadd,double fsecs,double interval)

{
  double in_d0;
  double dVar1;
  double in_d1;
  double in_d2;
  double interval_local;
  double fsecs_local;
  double fadd_local;
  double *f_local;
  double ftotal;
  double fprop;
  
  if (0.0 < in_d1) {
    dVar1 = exp(in_d2);
    dVar1 = 1.0 - 1.0 / dVar1;
    *f = *f + (in_d0 / in_d1) * dVar1;
    *f = *f / (dVar1 + 1.0);
  }
  return;
}

