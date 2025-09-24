
BIGNUM * bn_sqr_fixed_top(BIGNUM *param_1,BIGNUM *param_2,BN_CTX *param_3)

{
  BIGNUM *pBVar1;
  int iVar2;
  BIGNUM *b;
  ulong uVar3;
  int iVar4;
  undefined1 auStack_a0 [128];
  
  uVar3 = param_2->top;
  if ((int)uVar3 < 1) {
    param_1->top = 0;
    param_1->neg = 0;
    return (BIGNUM *)0x1;
  }
  BN_CTX_start(param_3);
  b = param_1;
  if (param_2 == param_1) {
    b = BN_CTX_get(param_3);
  }
  pBVar1 = BN_CTX_get(param_3);
  if (pBVar1 != (BIGNUM *)0x0 && b != (BIGNUM *)0x0) {
    iVar4 = uVar3 << 1;
    iVar2 = bn_wexpand(b,iVar4);
    if (iVar2 != 0) {
      if (uVar3 == 4) {
        bn_sqr_comba4(b->d,param_2->d);
      }
      else if (uVar3 == 8) {
        bn_sqr_comba8(b->d,param_2->d);
      }
      else {
        if (0xf < (int)uVar3) {
          iVar2 = BN_num_bits_word(uVar3);
          if (uVar3 == 1 << (iVar2 - 1U & 0xff)) {
            iVar2 = bn_wexpand(pBVar1,uVar3 << 2);
            if (iVar2 != 0) {
              bn_sqr_recursive(b->d,param_2->d,uVar3,pBVar1->d);
              goto LAB_00112968;
            }
          }
          else {
            iVar2 = bn_wexpand(pBVar1,iVar4);
            if (iVar2 != 0) {
              bn_sqr_normal(b->d,param_2->d,uVar3,pBVar1->d);
              goto LAB_00112968;
            }
          }
          goto LAB_00112918;
        }
        bn_sqr_normal(b->d,param_2->d,uVar3,auStack_a0);
      }
LAB_00112968:
      b->top = iVar4;
      if (b == param_1) {
        param_2 = (BIGNUM *)0x1;
      }
      b->neg = 0;
      if ((b != param_1) && (param_2 = BN_copy(param_1,b), param_2 != (BIGNUM *)0x0)) {
        param_2 = (BIGNUM *)0x1;
      }
      goto LAB_0011291a;
    }
  }
LAB_00112918:
  param_2 = (BIGNUM *)0x0;
LAB_0011291a:
  BN_CTX_end(param_3);
  return param_2;
}

