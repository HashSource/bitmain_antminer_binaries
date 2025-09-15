
void bn_sqr_recursive(ulong *param_1,ulong *param_2,int param_3,ulong *param_4)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  uint uVar5;
  ulong *puVar6;
  int iVar7;
  ulong *puVar8;
  ulong *rp;
  
  if (param_3 == 4) {
    bn_sqr_comba4();
    return;
  }
  if (param_3 == 8) {
    bn_sqr_comba8();
    return;
  }
  if (param_3 < 0x10) {
    bn_sqr_normal();
    return;
  }
  iVar7 = param_3 >> 1;
  puVar6 = param_2 + iVar7;
  iVar1 = bn_cmp_words(param_2,puVar6,iVar7);
  if (iVar1 < 1) {
    if (iVar1 == 0) {
      puVar8 = param_4 + param_3 * 2;
      memset(param_4 + param_3,0,param_3 * 4);
      goto LAB_000f3fa8;
    }
    bn_sub_words(param_4,puVar6,param_2,iVar7);
  }
  else {
    bn_sub_words(param_4,param_2,puVar6,iVar7);
  }
  puVar8 = param_4 + param_3 * 2;
  bn_sqr_recursive(param_4 + param_3,param_4,iVar7,puVar8);
LAB_000f3fa8:
  rp = param_4 + param_3;
  bn_sqr_recursive(param_1,param_2,iVar7,puVar8);
  bn_sqr_recursive(param_1 + param_3,puVar6,iVar7,puVar8);
  uVar2 = bn_add_words(param_4,param_1,param_1 + param_3,param_3);
  uVar3 = bn_sub_words(rp,param_4,rp,param_3);
  uVar4 = bn_add_words(param_1 + iVar7,param_1 + iVar7,rp,param_3);
  uVar5 = uVar4 + (uVar2 - uVar3);
  if (uVar5 != 0) {
    iVar7 = iVar7 + param_3;
    uVar2 = param_1[iVar7];
    puVar6 = param_1 + iVar7;
    param_1[iVar7] = uVar5 + uVar2;
    if (uVar5 + uVar2 < uVar5) {
      do {
        uVar2 = puVar6[1];
        puVar6 = puVar6 + 1;
        *puVar6 = uVar2 + 1;
      } while (uVar2 + 1 == 0);
    }
  }
  return;
}

