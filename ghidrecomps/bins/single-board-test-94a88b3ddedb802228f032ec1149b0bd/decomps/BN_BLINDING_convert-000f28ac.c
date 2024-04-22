
int BN_BLINDING_convert(BIGNUM *n,BN_BLINDING *b,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *b_00;
  bool bVar2;
  
  b_00 = *(BIGNUM **)b;
  if ((b_00 == (BIGNUM *)0x0) || (*(int *)(b + 4) == 0)) {
    ERR_put_error(3,100,0x6b,DAT_000f2904,0xea);
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(b + 0x1c) + 1;
    bVar2 = iVar1 == 0;
    if (bVar2) {
      iVar1 = 0;
    }
    if (bVar2) {
      *(int *)(b + 0x1c) = iVar1;
    }
    else {
      iVar1 = BN_BLINDING_update(b,ctx);
      if (iVar1 == 0) {
        return 0;
      }
      b_00 = *(BIGNUM **)b;
    }
    iVar1 = BN_mod_mul(n,n,b_00,*(BIGNUM **)(b + 0xc),ctx);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}

