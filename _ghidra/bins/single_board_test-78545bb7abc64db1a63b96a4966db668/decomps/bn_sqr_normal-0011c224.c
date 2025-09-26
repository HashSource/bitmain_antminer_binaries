
void bn_sqr_normal(ulong *param_1,ulong *param_2,int param_3,ulong *param_4)

{
  ulong uVar1;
  int num;
  int num_00;
  ulong *puVar2;
  ulong *rp;
  int num_01;
  int num_02;
  ulong *puVar3;
  ulong *unaff_r9;
  int iVar4;
  
  num = param_3 * 2;
  num_02 = param_3 + -1;
  param_1[num + 0x3fffffff] = 0;
  if (num_02 < 1) {
    unaff_r9 = param_2;
  }
  rp = param_1 + 1;
  *param_1 = 0;
  if (0 < num_02) {
    unaff_r9 = param_2 + 1;
    uVar1 = bn_mul_words(rp,unaff_r9,num_02,*param_2);
    rp[num_02] = uVar1;
    rp = param_1 + 3;
  }
  num_01 = param_3 + -2;
  if (0 < num_01) {
    iVar4 = param_3 + -3;
    if (10 < param_3) {
      puVar3 = rp + param_3;
      puVar2 = unaff_r9;
      do {
        unaff_r9 = puVar2 + 8;
        HintPreloadData(unaff_r9);
        num_02 = num_01 + -7;
        uVar1 = bn_mul_add_words(rp,puVar2 + 1,num_01,*puVar2);
        puVar3[-2] = uVar1;
        HintPreloadData(puVar3 + 6);
        uVar1 = bn_mul_add_words(rp + 2,puVar2 + 2,iVar4,puVar2[1]);
        puVar3[-1] = uVar1;
        iVar4 = iVar4 + -8;
        uVar1 = bn_mul_add_words(rp + 4,puVar2 + 3,num_01 + -2,puVar2[2]);
        *puVar3 = uVar1;
        uVar1 = bn_mul_add_words(rp + 6,puVar2 + 4,num_01 + -3,puVar2[3]);
        puVar3[1] = uVar1;
        uVar1 = bn_mul_add_words(rp + 8,puVar2 + 5,num_01 + -4,puVar2[4]);
        puVar3[2] = uVar1;
        uVar1 = bn_mul_add_words(rp + 10,puVar2 + 6,num_01 + -5,puVar2[5]);
        num_00 = num_01 + -6;
        puVar3[3] = uVar1;
        num_01 = num_01 + -8;
        uVar1 = bn_mul_add_words(rp + 0xc,puVar2 + 7,num_00,puVar2[6]);
        puVar3[4] = uVar1;
        uVar1 = bn_mul_add_words(rp + 0xe,unaff_r9,num_02,puVar2[7]);
        puVar3[5] = uVar1;
        rp = rp + 0x10;
        puVar3 = puVar3 + 8;
        puVar2 = unaff_r9;
      } while (7 < iVar4);
    }
    puVar2 = rp + num_02 + 0x3ffffffe;
    iVar4 = num_02;
    do {
      iVar4 = iVar4 + -1;
      uVar1 = bn_mul_add_words(rp,unaff_r9 + 1,iVar4,*unaff_r9);
      puVar2 = puVar2 + 1;
      *puVar2 = uVar1;
      rp = rp + 2;
      unaff_r9 = unaff_r9 + 1;
    } while (0 < (iVar4 + num_01) - num_02);
  }
  bn_add_words(param_1,param_1,param_1,num);
  bn_sqr_words(param_4,param_2,param_3);
  bn_add_words(param_1,param_1,param_4,num);
  return;
}

