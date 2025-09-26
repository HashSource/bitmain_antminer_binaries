
void bn_sqr_normal(ulong *param_1,ulong *param_2,int param_3,ulong *param_4)

{
  ulong *puVar1;
  ulong uVar2;
  int iVar3;
  ulong *rp;
  int num;
  int num_00;
  ulong *puVar4;
  ulong *puVar5;
  int num_01;
  int iVar6;
  ulong *ap;
  
  num = param_3 * 2;
  param_1[num + -1] = 0;
  num_01 = param_3 + -1;
  rp = param_1 + 1;
  *param_1 = 0;
  ap = param_2;
  if (0 < num_01) {
    uVar2 = bn_mul_words(rp,param_2 + 1,num_01,*param_2);
    rp[num_01] = uVar2;
    rp = param_1 + 3;
    ap = param_2 + 1;
  }
  num_00 = param_3 + -2;
  if (0 < num_00) {
    iVar6 = param_3 + -3;
    if (10 < param_3) {
      puVar4 = rp + param_3;
      puVar5 = ap + -1;
      puVar1 = ap;
      do {
        ap = puVar1 + 8;
        uVar2 = bn_mul_add_words(rp,puVar1 + 1,num_00,puVar5[1]);
        puVar4[-2] = uVar2;
        num_01 = num_00 + -7;
        uVar2 = bn_mul_add_words(rp + 2,puVar1 + 2,iVar6,puVar5[2]);
        puVar4[-1] = uVar2;
        iVar6 = iVar6 + -8;
        uVar2 = bn_mul_add_words(rp + 4,puVar1 + 3,num_00 + -2,puVar5[3]);
        *puVar4 = uVar2;
        HintPreloadData(ap);
        uVar2 = bn_mul_add_words(rp + 6,puVar1 + 4,num_00 + -3,puVar5[4]);
        puVar4[1] = uVar2;
        HintPreloadData(puVar4 + 6);
        uVar2 = bn_mul_add_words(rp + 8,puVar1 + 5,num_00 + -4,puVar5[5]);
        puVar4[2] = uVar2;
        uVar2 = bn_mul_add_words(rp + 10,puVar1 + 6,num_00 + -5,puVar5[6]);
        puVar4[3] = uVar2;
        iVar3 = num_00 + -6;
        num_00 = num_00 + -8;
        uVar2 = bn_mul_add_words(rp + 0xc,puVar1 + 7,iVar3,puVar5[7]);
        puVar4[4] = uVar2;
        puVar5 = puVar5 + 8;
        uVar2 = bn_mul_add_words(rp + 0xe,ap,num_01,*puVar5);
        puVar4[5] = uVar2;
        rp = rp + 0x10;
        puVar4 = puVar4 + 8;
        puVar1 = ap;
      } while (7 < iVar6);
    }
    iVar6 = num_01 + -1;
    puVar5 = rp + iVar6;
    do {
      uVar2 = bn_mul_add_words(rp,ap + 1,iVar6,*ap);
      iVar3 = num_00 + iVar6;
      *puVar5 = uVar2;
      iVar6 = iVar6 + -1;
      rp = rp + 2;
      puVar5 = puVar5 + 1;
      ap = ap + 1;
    } while (0 < iVar3 - num_01);
  }
  bn_add_words(param_1,param_1,param_1,num);
  bn_sqr_words(param_4,param_2,param_3);
  bn_add_words(param_1,param_1,param_4,num);
  return;
}

