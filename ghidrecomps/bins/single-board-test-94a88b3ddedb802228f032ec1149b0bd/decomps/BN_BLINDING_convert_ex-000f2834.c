
int BN_BLINDING_convert_ex(BIGNUM *n,BIGNUM *r,BN_BLINDING *b,BN_CTX *param_4)

{
  int iVar1;
  BIGNUM *pBVar2;
  bool bVar3;
  
  if ((*(int *)b == 0) || (*(int *)(b + 4) == 0)) {
    ERR_put_error(3,100,0x6b,DAT_000f28a8,0xea);
    pBVar2 = (BIGNUM *)0x0;
  }
  else {
    iVar1 = *(int *)(b + 0x1c) + 1;
    bVar3 = iVar1 == 0;
    if (bVar3) {
      iVar1 = 0;
    }
    if (bVar3) {
      *(int *)(b + 0x1c) = iVar1;
    }
    else {
      iVar1 = BN_BLINDING_update(b,param_4);
      if (iVar1 == 0) {
        return 0;
      }
    }
    pBVar2 = (BIGNUM *)0x1;
    if ((r != (BIGNUM *)0x0) && (pBVar2 = BN_copy(r,*(BIGNUM **)(b + 4)), pBVar2 != (BIGNUM *)0x0))
    {
      pBVar2 = (BIGNUM *)0x1;
    }
    iVar1 = BN_mod_mul(n,n,*(BIGNUM **)b,*(BIGNUM **)(b + 0xc),param_4);
    if (iVar1 == 0) {
      pBVar2 = (BIGNUM *)0x0;
    }
  }
  return (int)pBVar2;
}

