
void bn_sqr_recursive(ulong *param_1,ulong *param_2,int param_3,ulong *param_4)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  uint uVar5;
  ulong *puVar6;
  int num;
  ulong *rp;
  ulong *puVar7;
  
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
  num = param_3 >> 1;
  puVar6 = param_2 + num;
  iVar1 = bn_cmp_words(param_2,puVar6,num);
  if (iVar1 < 1) {
    if (iVar1 == 0) {
      puVar7 = param_4 + param_3 * 2;
      memset(param_4 + param_3,0,param_3 * 4);
      goto LAB_0011c40c;
    }
    bn_sub_words(param_4,puVar6,param_2,num);
  }
  else {
    bn_sub_words(param_4,param_2,puVar6,num);
  }
  puVar7 = param_4 + param_3 * 2;
  bn_sqr_recursive(param_4 + param_3,param_4,num,puVar7);
LAB_0011c40c:
  rp = param_4 + param_3;
  bn_sqr_recursive(param_1,param_2,num,puVar7);
  bn_sqr_recursive(param_1 + param_3,puVar6,num,puVar7);
  uVar2 = bn_add_words(param_4,param_1,param_1 + param_3,param_3);
  uVar3 = bn_sub_words(rp,param_4,rp,param_3);
  uVar4 = bn_add_words(param_1 + num,param_1 + num,rp,param_3);
  uVar5 = uVar4 + (uVar2 - uVar3);
  if (uVar5 != 0) {
    param_3 = param_3 + num;
    uVar2 = param_1[param_3];
    puVar6 = param_1 + param_3;
    param_1[param_3] = uVar2 + uVar5;
    if (uVar2 + uVar5 < uVar5) {
      do {
        puVar6 = puVar6 + 1;
        uVar2 = *puVar6;
        *puVar6 = uVar2 + 1;
      } while (uVar2 + 1 == 0);
    }
  }
  return;
}

