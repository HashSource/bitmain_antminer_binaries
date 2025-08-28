
undefined4 json_real_set(int *param_1)

{
  int iVar1;
  uint uVar2;
  double in_d0;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 4)) {
    return 0xffffffff;
  }
  uVar2 = (uint)((ulonglong)in_d0 >> 0x20);
  iVar1 = __isnan(in_d0);
  if ((iVar1 == 0) &&
     (iVar1 = __isinf((double)(((ulonglong)uVar2 << 0x20) + ((ulonglong)in_d0 & 0xffffffff))),
     iVar1 == 0)) {
    param_1[2] = SUB84(in_d0,0);
    param_1[3] = uVar2;
    return 0;
  }
  return 0xffffffff;
}

