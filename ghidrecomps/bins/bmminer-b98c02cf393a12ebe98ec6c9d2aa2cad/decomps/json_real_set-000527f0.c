
undefined4 json_real_set(int *param_1)

{
  int iVar1;
  undefined4 unaff_r4;
  undefined4 unaff_r6;
  undefined8 in_d0;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 4)) {
    return 0xffffffff;
  }
  iVar1 = __isnan((double)CONCAT44(unaff_r6,unaff_r4));
  if ((iVar1 == 0) && (iVar1 = __isinf((double)CONCAT44(unaff_r6,unaff_r4)), iVar1 == 0)) {
    param_1[2] = (int)in_d0;
    param_1[3] = (int)((ulonglong)in_d0 >> 0x20);
    return 0;
  }
  return 0xffffffff;
}

