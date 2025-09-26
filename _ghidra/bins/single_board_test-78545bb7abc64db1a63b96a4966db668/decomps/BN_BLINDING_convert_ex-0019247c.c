
int BN_BLINDING_convert_ex(BIGNUM *n,BIGNUM *r,BN_BLINDING *b,BN_CTX *param_4)

{
  BIGNUM *pBVar1;
  int iVar2;
  bool bVar3;
  
  if ((*(int *)b == 0) || (*(int *)(b + 4) == 0)) {
    ERR_put_error(3,100,0x6b,"crypto/bn/bn_blind.c",0x8d);
    return 0;
  }
  iVar2 = *(int *)(b + 0x14) + 1;
  bVar3 = iVar2 == 0;
  if (bVar3) {
    iVar2 = 0;
  }
  if (bVar3) {
    *(int *)(b + 0x14) = iVar2;
  }
  else {
    iVar2 = BN_BLINDING_update(b,param_4);
    if (iVar2 == 0) {
      return 0;
    }
  }
  if ((r != (BIGNUM *)0x0) && (pBVar1 = BN_copy(r,*(BIGNUM **)(b + 4)), pBVar1 == (BIGNUM *)0x0)) {
    return 0;
  }
  if (*(BN_MONT_CTX **)(b + 0x1c) != (BN_MONT_CTX *)0x0) {
    iVar2 = BN_mod_mul_montgomery(n,n,*(BIGNUM **)b,*(BN_MONT_CTX **)(b + 0x1c),param_4);
    return iVar2;
  }
  iVar2 = BN_mod_mul(n,n,*(BIGNUM **)b,*(BIGNUM **)(b + 0xc),param_4);
  return iVar2;
}

