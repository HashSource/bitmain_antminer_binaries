
BN_BLINDING *
BN_BLINDING_create_param
          (BN_BLINDING *b,BIGNUM *e,BIGNUM *m,BN_CTX *ctx,bn_mod_exp *bn_mod_exp,BN_MONT_CTX *m_ctx)

{
  BIGNUM *pBVar1;
  int iVar2;
  BN_BLINDING *b_00;
  int iVar3;
  int local_24 [2];
  
  b_00 = b;
  if ((b == (BN_BLINDING *)0x0) &&
     (b_00 = BN_BLINDING_new((BIGNUM *)0x0,(BIGNUM *)0x0,m), b_00 == (BN_BLINDING *)0x0))
  goto LAB_00188794;
  if (*(int *)b_00 == 0) {
    pBVar1 = BN_new();
    *(BIGNUM **)b_00 = pBVar1;
    if (pBVar1 != (BIGNUM *)0x0) goto LAB_001886cc;
  }
  else {
LAB_001886cc:
    if (*(int *)(b_00 + 4) == 0) {
      pBVar1 = BN_new();
      *(BIGNUM **)(b_00 + 4) = pBVar1;
      if (pBVar1 == (BIGNUM *)0x0) goto LAB_0018872a;
    }
    if (e == (BIGNUM *)0x0) {
      pBVar1 = *(BIGNUM **)(b_00 + 8);
    }
    else {
      BN_free(*(BIGNUM **)(b_00 + 8));
      pBVar1 = BN_dup(e);
      *(BIGNUM **)(b_00 + 8) = pBVar1;
    }
    if (pBVar1 != (BIGNUM *)0x0) {
      if (bn_mod_exp != (bn_mod_exp *)0x0) {
        *(bn_mod_exp **)(b_00 + 0x20) = bn_mod_exp;
      }
      if (m_ctx != (BN_MONT_CTX *)0x0) {
        *(BN_MONT_CTX **)(b_00 + 0x1c) = m_ctx;
      }
      iVar3 = 0x21;
      do {
        iVar2 = BN_priv_rand_range(*(undefined4 *)b_00,*(undefined4 *)(b_00 + 0xc));
        if (iVar2 == 0) goto LAB_0018872a;
        iVar2 = int_bn_mod_inverse(*(undefined4 *)(b_00 + 4),*(undefined4 *)b_00,
                                   *(undefined4 *)(b_00 + 0xc),ctx,local_24);
        if (iVar2 != 0) {
          if ((*(code **)(b_00 + 0x20) == (code *)0x0) || (*(int *)(b_00 + 0x1c) == 0)) {
            iVar3 = BN_mod_exp(*(BIGNUM **)b_00,*(BIGNUM **)b_00,*(BIGNUM **)(b_00 + 8),
                               *(BIGNUM **)(b_00 + 0xc),ctx);
          }
          else {
            iVar3 = (**(code **)(b_00 + 0x20))
                              (*(undefined4 *)b_00,*(undefined4 *)b_00,*(undefined4 *)(b_00 + 8),
                               *(undefined4 *)(b_00 + 0xc),ctx,*(int *)(b_00 + 0x1c));
          }
          if (iVar3 != 0) {
            if (*(int *)(b_00 + 0x1c) == 0) {
              return b_00;
            }
            iVar3 = bn_to_mont_fixed_top
                              (*(undefined4 *)(b_00 + 4),*(undefined4 *)(b_00 + 4),
                               *(int *)(b_00 + 0x1c),ctx);
            if ((iVar3 != 0) &&
               (iVar3 = bn_to_mont_fixed_top
                                  (*(undefined4 *)b_00,*(undefined4 *)b_00,
                                   *(undefined4 *)(b_00 + 0x1c),ctx), iVar3 != 0)) {
              return b_00;
            }
          }
          goto LAB_0018872a;
        }
        if (local_24[0] == 0) goto LAB_0018872a;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      ERR_put_error(3,0x80,0x71,"crypto/bn/bn_blind.c",0x11d);
    }
  }
LAB_0018872a:
  if (b != (BN_BLINDING *)0x0) {
    return b_00;
  }
LAB_00188794:
  BN_BLINDING_free(b_00);
  return (BN_BLINDING *)0x0;
}

