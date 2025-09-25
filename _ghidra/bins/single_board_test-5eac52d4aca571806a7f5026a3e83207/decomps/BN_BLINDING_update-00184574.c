
int BN_BLINDING_update(BN_BLINDING *b,BN_CTX *ctx)

{
  BN_BLINDING *pBVar1;
  BIGNUM *pBVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  if ((*(int *)b == 0) || (pBVar2 = *(BIGNUM **)(b + 4), pBVar2 == (BIGNUM *)0x0)) {
    ERR_put_error(3,0x67,0x6b,"crypto/bn/bn_blind.c",0x62);
    pBVar1 = (BN_BLINDING *)0x0;
  }
  else {
    if (*(int *)(b + 0x14) == -1) {
      *(undefined4 *)(b + 0x14) = 1;
      if (*(int *)(b + 0x18) << 0x1f < 0) {
        return 1;
      }
    }
    else {
      iVar4 = *(int *)(b + 0x14) + 1;
      *(int *)(b + 0x14) = iVar4;
      if (iVar4 == 0x20) {
        if (*(int *)(b + 8) == 0) {
          uVar5 = *(uint *)(b + 0x18);
        }
        else {
          uVar5 = *(uint *)(b + 0x18);
          if ((uVar5 & 2) == 0) {
            pBVar1 = BN_BLINDING_create_param
                               (b,(BIGNUM *)0x0,(BIGNUM *)0x0,ctx,(bn_mod_exp *)0x0,
                                (BN_MONT_CTX *)0x0);
            if (pBVar1 != (BN_BLINDING *)0x0) {
              pBVar1 = (BN_BLINDING *)0x1;
            }
            goto LAB_001845ca;
          }
        }
        if ((int)(uVar5 << 0x1f) < 0) {
          pBVar1 = (BN_BLINDING *)0x1;
          goto LAB_001845d0;
        }
      }
      else if (*(int *)(b + 0x18) << 0x1f < 0) {
        return 1;
      }
    }
    if (*(int *)(b + 0x1c) == 0) {
      iVar4 = BN_mod_mul(pBVar2,pBVar2,pBVar2,*(BIGNUM **)(b + 0xc),ctx);
      if (iVar4 == 0) goto LAB_001845c8;
      pBVar2 = *(BIGNUM **)b;
      pBVar1 = (BN_BLINDING *)BN_mod_mul(pBVar2,pBVar2,pBVar2,*(BIGNUM **)(b + 0xc),ctx);
      if (pBVar1 != (BN_BLINDING *)0x0) {
        pBVar1 = (BN_BLINDING *)0x1;
      }
    }
    else {
      iVar4 = bn_mul_mont_fixed_top(pBVar2,pBVar2,pBVar2,*(int *)(b + 0x1c),ctx);
      if (iVar4 == 0) {
LAB_001845c8:
        pBVar1 = (BN_BLINDING *)0x0;
      }
      else {
        uVar3 = *(undefined4 *)b;
        pBVar1 = (BN_BLINDING *)
                 bn_mul_mont_fixed_top(uVar3,uVar3,uVar3,*(undefined4 *)(b + 0x1c),ctx);
        if (pBVar1 != (BN_BLINDING *)0x0) {
          pBVar1 = (BN_BLINDING *)0x1;
        }
      }
    }
  }
LAB_001845ca:
  if (*(int *)(b + 0x14) != 0x20) {
    return (int)pBVar1;
  }
LAB_001845d0:
  *(undefined4 *)(b + 0x14) = 0;
  return (int)pBVar1;
}

