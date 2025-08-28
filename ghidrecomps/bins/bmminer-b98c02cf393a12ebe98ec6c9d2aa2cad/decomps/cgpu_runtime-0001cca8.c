
undefined4 cgpu_runtime(int param_1)

{
  undefined4 uVar1;
  double dVar2;
  undefined4 extraout_s1;
  undefined1 auStack_10 [8];
  
  dVar2 = total_secs;
  if (*(int *)(param_1 + 0x170) != 0) {
    cgtime(auStack_10);
    uVar1 = tdiff(auStack_10,param_1 + 0x170);
    dVar2 = (double)CONCAT44(extraout_s1,uVar1);
  }
  if ((int)((uint)(dVar2 < 1.0) << 0x1f) < 0) {
    dVar2 = 0.0;
  }
  return SUB84(dVar2,0);
}

