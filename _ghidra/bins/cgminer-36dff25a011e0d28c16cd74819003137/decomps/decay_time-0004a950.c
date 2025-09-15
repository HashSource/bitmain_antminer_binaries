
void decay_time(double *f,double fadd,double fsecs,double interval)

{
  double dVar1;
  double interval_local;
  double fsecs_local;
  double fadd_local;
  double *f_local;
  double ftotal;
  double fprop;
  
  if (0.0 < fsecs) {
    dVar1 = exp(fsecs / interval);
    dVar1 = 1.0 - 1.0 / dVar1;
    *f = *f + (fadd / fsecs) * dVar1;
    *f = *f / (dVar1 + 1.0);
  }
  return;
}

