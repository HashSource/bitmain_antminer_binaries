
double cgpu_runtime(int param_1)

{
  double dVar1;
  undefined auStack_10 [8];
  
  if (*(int *)(param_1 + 0x170) == 0) {
    dVar1 = *DAT_0001cce4;
  }
  else {
    cgtime(auStack_10);
    dVar1 = (double)tdiff(auStack_10,param_1 + 0x170);
  }
  if ((int)((uint)(dVar1 < 1.0) << 0x1f) < 0) {
    dVar1 = 1.0;
  }
  return dVar1;
}

