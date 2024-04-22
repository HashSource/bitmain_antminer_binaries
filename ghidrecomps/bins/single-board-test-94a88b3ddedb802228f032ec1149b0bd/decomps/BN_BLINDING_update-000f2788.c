
int BN_BLINDING_update(BN_BLINDING *b,BN_CTX *ctx)

{
  BN_BLINDING *pBVar1;
  BIGNUM *pBVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  pBVar2 = *(BIGNUM **)b;
  if ((pBVar2 == (BIGNUM *)0x0) || (*(int *)(b + 4) == 0)) {
    ERR_put_error(3,0x67,0x6b,DAT_000f2830,0xc4);
    pBVar1 = (BN_BLINDING *)0x0;
  }
  else {
    if (*(int *)(b + 0x1c) == -1) {
      *(undefined4 *)(b + 0x1c) = 1;
      if (*(int *)(b + 0x20) << 0x1f < 0) {
        pBVar1 = (BN_BLINDING *)0x1;
        goto LAB_000f27b4;
      }
    }
    else {
      iVar3 = *(int *)(b + 0x1c) + 1;
      *(int *)(b + 0x1c) = iVar3;
      if (iVar3 == 0x20) {
        uVar4 = *(uint *)(b + 0x20);
        if ((*(int *)(b + 8) != 0) && ((uVar4 & 2) == 0)) {
          pBVar1 = BN_BLINDING_create_param
                             (b,(BIGNUM *)0x0,(BIGNUM *)0x0,ctx,(bn_mod_exp *)0x0,(BN_MONT_CTX *)0x0
                             );
          if (pBVar1 != (BN_BLINDING *)0x0) {
            pBVar1 = (BN_BLINDING *)0x1;
          }
          goto LAB_000f27b4;
        }
      }
      else {
        uVar4 = *(uint *)(b + 0x20);
      }
      if ((int)(uVar4 << 0x1f) < 0) {
        pBVar1 = (BN_BLINDING *)0x1;
        goto LAB_000f27b4;
      }
    }
    pBVar1 = (BN_BLINDING *)BN_mod_mul(pBVar2,pBVar2,pBVar2,*(BIGNUM **)(b + 0xc),ctx);
    if (pBVar1 != (BN_BLINDING *)0x0) {
      pBVar2 = *(BIGNUM **)(b + 4);
      pBVar1 = (BN_BLINDING *)BN_mod_mul(pBVar2,pBVar2,pBVar2,*(BIGNUM **)(b + 0xc),ctx);
      if (pBVar1 != (BN_BLINDING *)0x0) {
        pBVar1 = (BN_BLINDING *)0x1;
      }
    }
  }
LAB_000f27b4:
  iVar3 = *(int *)(b + 0x1c);
  bVar5 = iVar3 == 0x20;
  if (bVar5) {
    iVar3 = 0;
  }
  if (bVar5) {
    *(int *)(b + 0x1c) = iVar3;
  }
  return (int)pBVar1;
}

