
BIGNUM * pub_cmp_gost94(EVP_PKEY *param_1,EVP_PKEY *param_2)

{
  void *pvVar1;
  void *pvVar2;
  uint uVar3;
  BIGNUM *pBVar4;
  
  pvVar1 = EVP_PKEY_get0(param_1);
  pvVar2 = EVP_PKEY_get0(param_2);
  if (pvVar2 == (void *)0x0 || pvVar1 == (void *)0x0) {
    pBVar4 = (BIGNUM *)0x0;
  }
  else {
    pBVar4 = *(BIGNUM **)((int)pvVar1 + 0x18);
    if (pBVar4 != (BIGNUM *)0x0) {
      if (*(BIGNUM **)((int)pvVar2 + 0x18) == (BIGNUM *)0x0) {
        return (BIGNUM *)0x0;
      }
      uVar3 = BN_cmp(pBVar4,*(BIGNUM **)((int)pvVar2 + 0x18));
      pBVar4 = (BIGNUM *)(1 - uVar3);
      if (1 < uVar3) {
        pBVar4 = (BIGNUM *)0x0;
      }
      return pBVar4;
    }
  }
  return pBVar4;
}

