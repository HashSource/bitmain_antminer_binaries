
undefined4 json_real_set(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  double in_d0;
  int local_18;
  int iStack_14;
  
  if ((((param_1 == (int *)0x0) || (*param_1 != 4)) || (iVar1 = __isnan(in_d0), iVar1 != 0)) ||
     (iVar1 = __isinf(in_d0), iVar1 != 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    local_18 = SUB84(in_d0,0);
    iStack_14 = (int)((ulonglong)in_d0 >> 0x20);
    param_1[2] = local_18;
    param_1[3] = iStack_14;
    uVar2 = 0;
  }
  return uVar2;
}

