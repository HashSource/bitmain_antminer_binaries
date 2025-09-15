
void decay_time(double *f,double fadd,double fsecs,double interval)

{
  double dVar1;
  
  if (0.0 < fsecs) {
    dVar1 = exp(fsecs / interval);
    dVar1 = 1.0 - 1.0 / dVar1;
    *f = (*f + dVar1 * (fadd / fsecs)) / (dVar1 + 1.0);
  }
  return;
}

