
EC_GROUP * EC_GROUP_new(EC_METHOD *meth)

{
  EC_GROUP *ptr;
  BIGNUM *pBVar1;
  int iVar2;
  code *pcVar3;
  
  if (meth == (EC_METHOD *)0x0) {
    ERR_put_error(0x10,0x6c,0x6c,"crypto/ec/ec_lib.c",0x19);
    return (EC_GROUP *)0x0;
  }
  if (*(int *)(meth + 8) == 0) {
    ERR_put_error(0x10,0x6c,0x42,"crypto/ec/ec_lib.c",0x1d);
    return (EC_GROUP *)0x0;
  }
  ptr = (EC_GROUP *)CRYPTO_zalloc(0x68,"crypto/ec/ec_lib.c",0x21);
  if (ptr == (EC_GROUP *)0x0) {
    ERR_put_error(0x10,0x6c,0x41,"crypto/ec/ec_lib.c",0x23);
    return (EC_GROUP *)0x0;
  }
  iVar2 = *(int *)meth;
  *(EC_METHOD **)ptr = meth;
  if (iVar2 << 0x1e < 0) {
LAB_0011df84:
    pcVar3 = *(code **)(meth + 8);
    *(undefined4 *)(ptr + 0x14) = 1;
    *(undefined4 *)(ptr + 0x1c) = 4;
    iVar2 = (*pcVar3)(ptr);
    if (iVar2 != 0) {
      return ptr;
    }
  }
  else {
    pBVar1 = BN_new();
    *(BIGNUM **)(ptr + 8) = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_0011dfae;
    pBVar1 = BN_new();
    *(BIGNUM **)(ptr + 0xc) = pBVar1;
    if (pBVar1 != (BIGNUM *)0x0) goto LAB_0011df84;
  }
  pBVar1 = *(BIGNUM **)(ptr + 8);
LAB_0011dfae:
  BN_free(pBVar1);
  BN_free(*(BIGNUM **)(ptr + 0xc));
  CRYPTO_free(ptr);
  return (EC_GROUP *)0x0;
}

