
void decay_time(double *f,double fadd,double fsecs,double interval)

{
  double in_d0;
  double dVar1;
  double in_d1;
  double unaff_d8;
  
  if (0.0 < in_d1) {
    dVar1 = exp(unaff_d8);
    dVar1 = 1.0 - 1.0 / dVar1;
    *f = (*f + dVar1 * (in_d0 / in_d1)) / (dVar1 + 1.0);
  }
  return;
}

