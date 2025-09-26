
DH * d2i_DHxparams(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  DH *dh;
  undefined4 *ptr;
  BIGNUM *pBVar1;
  uchar *puVar2;
  undefined4 *puVar3;
  int iVar4;
  BIGNUM *pBVar5;
  ASN1_STRING *a;
  BIGNUM *pBVar6;
  
  dh = DH_new();
  if (dh == (DH *)0x0) {
    return (DH *)0x0;
  }
  ptr = (undefined4 *)d2i_int_dhx(0,param_2,param_3);
  if (ptr != (undefined4 *)0x0) {
    if (param_1 != (undefined4 *)0x0) {
      DH_free((DH *)*param_1);
      *param_1 = dh;
    }
    puVar3 = (undefined4 *)ptr[4];
    pBVar1 = (BIGNUM *)ptr[2];
    pBVar5 = (BIGNUM *)ptr[3];
    pBVar6 = (BIGNUM *)*ptr;
    dh->q = (BIGNUM *)ptr[1];
    dh->p = pBVar6;
    dh->g = pBVar1;
    dh->j = pBVar5;
    if (puVar3 != (undefined4 *)0x0) {
      a = (ASN1_STRING *)*puVar3;
      puVar2 = a->data;
      iVar4 = a->length;
      dh->counter = (BIGNUM *)puVar3[1];
      dh->seed = puVar2;
      dh->seedlen = iVar4;
      a->data = (uchar *)0x0;
      ASN1_BIT_STRING_free(a);
      CRYPTO_free((void *)ptr[4]);
      ptr[4] = 0;
    }
    CRYPTO_free(ptr);
    return dh;
  }
  DH_free(dh);
  return (DH *)0x0;
}

