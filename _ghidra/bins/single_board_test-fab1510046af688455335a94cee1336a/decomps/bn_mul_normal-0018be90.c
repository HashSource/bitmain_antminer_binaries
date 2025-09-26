
void bn_mul_normal(ulong *param_1,ulong *param_2,int param_3,ulong *param_4,int param_5)

{
  ulong uVar1;
  ulong *rp;
  int iVar2;
  ulong *puVar3;
  ulong *puVar4;
  bool bVar5;
  
  iVar2 = param_5;
  puVar3 = param_4;
  if (param_3 < param_5) {
    iVar2 = param_3;
    puVar3 = param_2;
    param_3 = param_5;
    param_2 = param_4;
  }
  puVar4 = param_1 + param_3;
  if (iVar2 < 1) {
    bn_mul_words(param_1,param_2,param_3,0);
    return;
  }
  uVar1 = bn_mul_words(param_1,param_2,param_3,*puVar3);
  iVar2 = iVar2 + -1;
  param_1[param_3] = uVar1;
  if (iVar2 != 0) {
    do {
      uVar1 = bn_mul_add_words(param_1 + 1,param_2,param_3,puVar3[1]);
      puVar4[1] = uVar1;
      if (iVar2 == 1) {
        return;
      }
      uVar1 = bn_mul_add_words(param_1 + 2,param_2,param_3,puVar3[2]);
      puVar4[2] = uVar1;
      rp = param_1 + 3;
      param_1 = param_1 + 4;
      if (iVar2 == 2) {
        return;
      }
      uVar1 = bn_mul_add_words(rp,param_2,param_3,puVar3[3]);
      bVar5 = iVar2 == 3;
      puVar4[3] = uVar1;
      iVar2 = iVar2 + -4;
      if (bVar5) {
        return;
      }
      puVar3 = puVar3 + 4;
      uVar1 = bn_mul_add_words(param_1,param_2,param_3,*puVar3);
      puVar4 = puVar4 + 4;
      *puVar4 = uVar1;
    } while (0 < iVar2);
  }
  return;
}

