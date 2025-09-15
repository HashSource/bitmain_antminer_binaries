
double diff_from_target(void *target)

{
  void *target_local;
  double d64;
  double dcut64;
  
  dcut64 = le256todouble(target);
  if (dcut64 == 0.0) {
    dcut64 = 1.0;
  }
  return 2.695953529101131e+67 / dcut64;
}

