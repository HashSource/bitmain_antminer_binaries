
BIGNUM * bn_mul_fixed_top(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  BIGNUM *pBVar1;
  int iVar2;
  BIGNUM *pBVar3;
  BIGNUM *b;
  int iVar4;
  ulong *puVar5;
  BIGNUM *pBVar6;
  ulong *puVar7;
  BIGNUM *pBVar8;
  BIGNUM *pBVar9;
  
  pBVar8 = (BIGNUM *)param_2->top;
  pBVar9 = (BIGNUM *)param_3->top;
  if (pBVar9 == (BIGNUM *)0x0 || pBVar8 == (BIGNUM *)0x0) {
    BN_set_word(param_1,0);
    return (BIGNUM *)0x1;
  }
  iVar4 = (int)&pBVar9->d + (int)&pBVar8->d;
  BN_CTX_start(param_4);
  b = param_1;
  if ((param_3 != param_1 && param_2 != param_1) || (b = BN_CTX_get(param_4), b != (BIGNUM *)0x0)) {
    if (pBVar8 == (BIGNUM *)0x8 && pBVar8 == pBVar9) {
      iVar4 = bn_wexpand(b,0x10);
      if (iVar4 != 0) {
        puVar7 = param_3->d;
        puVar5 = param_2->d;
        b->top = 0x10;
        bn_mul_comba8(b->d,puVar5,puVar7);
LAB_0011ba14:
        if (b == param_1) {
          pBVar8 = (BIGNUM *)0x1;
        }
        b->neg = param_3->neg ^ param_2->neg;
        if ((b != param_1) && (pBVar8 = BN_copy(param_1,b), pBVar8 != (BIGNUM *)0x0)) {
          pBVar8 = (BIGNUM *)0x1;
        }
        goto LAB_0011ba36;
      }
    }
    else {
      pBVar3 = pBVar8;
      if (0xf < (int)pBVar8) {
        pBVar3 = pBVar9;
      }
      if (((int)pBVar3 < 0x10) || (2 < ((int)pBVar8 - (int)pBVar9) + 1U)) {
        iVar2 = bn_wexpand(b,iVar4);
        if (iVar2 != 0) {
          puVar7 = param_3->d;
          puVar5 = param_2->d;
          b->top = iVar4;
          bn_mul_normal(b->d,puVar5,pBVar8,puVar7,pBVar9);
          goto LAB_0011ba14;
        }
      }
      else {
        if ((int)pBVar8 - (int)pBVar9 == -1) {
          iVar2 = BN_num_bits_word((ulong)pBVar9);
        }
        else {
          iVar2 = BN_num_bits_word((ulong)pBVar8);
        }
        pBVar6 = (BIGNUM *)(1 << (iVar2 - 1U & 0xff));
        pBVar3 = BN_CTX_get(param_4);
        if (pBVar3 != (BIGNUM *)0x0) {
          iVar2 = (int)pBVar9 - (int)pBVar6;
          pBVar1 = pBVar9;
          if ((int)pBVar9 <= (int)pBVar6) {
            iVar2 = (int)pBVar8 - (int)pBVar6;
            pBVar1 = pBVar8;
          }
          if (pBVar1 == pBVar6 || iVar2 < 0 != SBORROW4((int)pBVar1,(int)pBVar6)) {
            iVar2 = bn_wexpand(pBVar3,(int)pBVar6 << 2);
            if ((iVar2 != 0) && (iVar2 = bn_wexpand(b,(int)pBVar6 << 2), iVar2 != 0)) {
              pBVar8 = (BIGNUM *)((int)pBVar8 - (int)pBVar6);
              bn_mul_recursive(b->d,param_2->d,param_3->d,pBVar6,pBVar8,(int)pBVar9 - (int)pBVar6,
                               pBVar3->d);
              goto LAB_0011baa6;
            }
          }
          else {
            iVar2 = bn_wexpand(pBVar3,(int)pBVar6 << 3);
            if ((iVar2 != 0) && (iVar2 = bn_wexpand(b,(int)pBVar6 << 3), iVar2 != 0)) {
              pBVar8 = (BIGNUM *)((int)pBVar8 - (int)pBVar6);
              bn_mul_part_recursive
                        (b->d,param_2->d,param_3->d,pBVar6,pBVar8,(int)pBVar9 - (int)pBVar6,
                         pBVar3->d);
LAB_0011baa6:
              b->top = iVar4;
              goto LAB_0011ba14;
            }
          }
        }
      }
    }
  }
  pBVar8 = (BIGNUM *)0x0;
LAB_0011ba36:
  BN_CTX_end(param_4);
  return pBVar8;
}

