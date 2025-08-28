
ulong BN_mod_word(BIGNUM *a,ulong w)

{
  ulong *puVar1;
  ulong uVar2;
  ulong *puVar3;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  ulong extraout_r2_06;
  ulong extraout_r2_07;
  int iVar4;
  ulong *puVar5;
  int iVar6;
  
  if (w == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar4 = a->top;
    iVar6 = iVar4 + -1;
    if (iVar6 < 0) {
      uVar2 = 0;
    }
    else {
      puVar3 = a->d;
      if (iVar4 < 9) {
        uVar2 = 0;
      }
      else {
        puVar5 = puVar3 + iVar4 + -0xd;
        uVar2 = 0;
        do {
          iVar6 = iVar6 + -8;
          HintPreloadData(puVar5);
          __aeabi_uldivmod(puVar5[0xc],uVar2,w,0);
          __aeabi_uldivmod(puVar5[0xb],extraout_r2,w,0);
          __aeabi_uldivmod(puVar5[10],extraout_r2_00,w,0);
          __aeabi_uldivmod(puVar5[9],extraout_r2_01,w,0);
          __aeabi_uldivmod(puVar5[8],extraout_r2_02,w,0);
          __aeabi_uldivmod(puVar5[7],extraout_r2_03,w,0);
          __aeabi_uldivmod(puVar5[6],extraout_r2_04,w,0);
          puVar1 = puVar5 + 5;
          puVar5 = puVar5 + -8;
          __aeabi_uldivmod(*puVar1,extraout_r2_05,w,0);
          uVar2 = extraout_r2_06;
        } while (iVar6 != (iVar4 - (iVar4 - 9U & 0xfffffff8)) + -9);
      }
      puVar3 = puVar3 + iVar6 + 1;
      do {
        puVar3 = puVar3 + -1;
        __aeabi_uldivmod(*puVar3,uVar2,w,0);
        iVar6 = iVar6 + -1;
        uVar2 = extraout_r2_07;
      } while (-1 < iVar6);
    }
  }
  return uVar2;
}

