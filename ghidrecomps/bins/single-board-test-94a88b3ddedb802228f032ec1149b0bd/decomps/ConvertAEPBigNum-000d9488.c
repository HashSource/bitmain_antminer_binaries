
undefined4 ConvertAEPBigNum(BIGNUM *param_1,uint param_2,ulong *param_3)

{
  ulong uVar1;
  ulong *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_2 * 8 + 0x1f;
  iVar4 = param_2 * 8 + 0x3e;
  if (-1 < iVar3) {
    iVar4 = iVar3;
  }
  if (param_1->dmax < iVar4 >> 5) {
    bn_expand2(param_1,iVar4 >> 5);
  }
  param_1->top = param_2 >> 2;
  if (param_2 >> 2 != 0) {
    iVar4 = 0;
    puVar2 = param_1->d + -1;
    do {
      iVar4 = iVar4 + 1;
      uVar1 = *param_3;
      param_3 = param_3 + 1;
      puVar2 = puVar2 + 1;
      *puVar2 = uVar1;
    } while (iVar4 < param_1->top);
  }
  return 0;
}

