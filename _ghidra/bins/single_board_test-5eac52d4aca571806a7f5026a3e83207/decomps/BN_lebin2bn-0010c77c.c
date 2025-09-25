
BIGNUM * BN_lebin2bn(int param_1,int param_2,BIGNUM *param_3)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  BIGNUM *a;
  
  a = (BIGNUM *)0x0;
  if ((param_3 != (BIGNUM *)0x0) || (param_3 = BN_new(), a = param_3, param_3 != (BIGNUM *)0x0)) {
    pbVar4 = (byte *)(param_1 + param_2);
    if ((param_2 < 1) || (pbVar4[-1] != 0)) {
      if (param_2 == 0) {
LAB_0010c810:
        param_3->top = 0;
        return param_3;
      }
    }
    else {
      pbVar2 = pbVar4 + -1;
      do {
        pbVar4 = pbVar2;
        param_2 = param_2 + -1;
        if (param_2 == 0) goto LAB_0010c810;
        pbVar2 = pbVar4 + -1;
      } while (pbVar4[-1] == 0);
    }
    uVar5 = param_2 - 1U & 7;
    iVar6 = (param_2 - 1U >> 3) + 1;
    iVar1 = bn_wexpand(param_3,iVar6);
    if (iVar1 != 0) {
      pbVar2 = pbVar4 + -param_2;
      uVar3 = 0;
      param_3->top = iVar6;
      param_3->neg = 0;
      do {
        while( true ) {
          pbVar4 = pbVar4 + -1;
          uVar3 = (uint)*pbVar4 | uVar3 << 8;
          if (uVar5 != 0) break;
          iVar6 = iVar6 + -1;
          param_3->d[iVar6] = uVar3;
          uVar5 = 7;
          uVar3 = 0;
          if (pbVar4 == pbVar2) goto LAB_0010c7fc;
        }
        uVar5 = uVar5 - 1;
      } while (pbVar4 != pbVar2);
LAB_0010c7fc:
      bn_correct_top(param_3);
      return param_3;
    }
    BN_free(a);
    param_3 = (BIGNUM *)0x0;
  }
  return param_3;
}

