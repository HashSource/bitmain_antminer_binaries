
ulong BN_mod_word(BIGNUM *a,ulong w)

{
  ulong *puVar1;
  ulong uVar2;
  ulong *puVar3;
  ulong uVar4;
  int iVar5;
  ulong *puVar6;
  int iVar7;
  
  if (w == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar5 = a->top;
    iVar7 = iVar5 + -1;
    if (iVar7 < 0) {
      uVar2 = 0;
    }
    else {
      puVar3 = a->d;
      if (iVar5 < 9) {
        uVar2 = 0;
      }
      else {
        puVar6 = puVar3 + iVar5 + -0xd;
        uVar2 = 0;
        do {
          iVar7 = iVar7 + -8;
          HintPreloadData(puVar6);
          uVar4 = w;
          __aeabi_uldivmod(puVar6[0xc],uVar2,w,0);
          uVar2 = w;
          __aeabi_uldivmod(puVar6[0xb],uVar4,w,0);
          uVar4 = w;
          __aeabi_uldivmod(puVar6[10],uVar2,w,0);
          uVar2 = w;
          __aeabi_uldivmod(puVar6[9],uVar4,w,0);
          uVar4 = w;
          __aeabi_uldivmod(puVar6[8],uVar2,w,0);
          uVar2 = w;
          __aeabi_uldivmod(puVar6[7],uVar4,w,0);
          uVar4 = w;
          __aeabi_uldivmod(puVar6[6],uVar2,w,0);
          puVar1 = puVar6 + 5;
          puVar6 = puVar6 + -8;
          uVar2 = w;
          __aeabi_uldivmod(*puVar1,uVar4,w,0);
        } while (iVar7 != (iVar5 - (iVar5 - 9U & 0xfffffff8)) + -9);
      }
      puVar3 = puVar3 + iVar7 + 1;
      do {
        puVar3 = puVar3 + -1;
        uVar4 = w;
        __aeabi_uldivmod(*puVar3,uVar2,w,0);
        uVar2 = uVar4;
        iVar7 = iVar7 + -1;
      } while (-1 < iVar7);
    }
  }
  return uVar2;
}

