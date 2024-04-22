
double diff_from_target(void *target)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *target_local;
  double d64;
  double dcut64;
  
  uVar2 = truediffone._4_4_;
  uVar1 = truediffone._0_4_;
  dcut64 = le256todouble(target);
  if (dcut64 == 0.0) {
    dcut64 = 1.0;
  }
  return (double)CONCAT44(uVar2,uVar1) / dcut64;
}

